#include "game.h"
#include <bits/stdc++.h>
#include <iostream>
#include<chrono>
#include <SDL2/SDL.h>

//Game constructor when window size is not given
Game::Game()
{   
    screen_width=800;
    screen_height=800;
    striker=std::make_unique<Striker>(Striker(200,50));
    ball=std::make_unique<Ball>(Ball(screen_width, screen_height));
    int i=0;
     for(i=0;i<8;i++){
      bricks.emplace_back(std::make_unique<Brick>(Brick(50+i*100,0)));
     }
    
}


//Game Constructor when window dimnesions are given
Game::Game(int _width, int _height)
{   
    screen_width=_width;
    screen_height=_height;
    striker=std::make_unique<Striker>(Striker(200,50));
    ball=std::make_unique<Ball>(Ball(screen_width, screen_height));
    int i=0;
     for(i=0;i<8;i++){
      bricks.emplace_back(std::make_unique<Brick>(Brick(50+i*100,0)));
     }
}

//Destructor for the game
Game::~Game(){                    
  ball.~unique_ptr();                     //Delete ball
  striker.~unique_ptr();                  //Delete Striker
  for(auto & element : bricks){ 
      element.~unique_ptr();              //Delete the remaining bricks
  }
  std::cout<<"Game Over"<<std::endl;
};

//Move Constructor
  Game::Game(Game && other){
    std::cout<<"Game move constructor"<<std::endl;
    other.ball=std::move(ball);
    other.striker=std::move(striker);
    other.bricks=std::move(bricks);
  };  
 //Move Assignment
  Game& Game::operator=(Game&& rhs){
    std::cout<<"Game move assignment"<<std::endl;
    rhs.ball=std::move(ball);
    rhs.striker=std::move(striker);
    rhs.bricks=std::move(bricks);
    return *this;
  };  



void Game::Run(Controller &controller, Renderer &renderer,std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
 
  while (ball->alive && score<8) {
    
    frame_start = SDL_GetTicks();

    //Input, Update, Render - the main game loop.
    SDL_Delay(5);                                     //Delay for the main loop
    controller.HandleInput(striker, screen_width);    //Handle the input from the user for controlling the striker
    Update(SDL_GetTicks()-frame_start,ball,bricks);   //Update the game
    renderer.Render(striker,ball,bricks);             //Render the game
    renderer.UpdateWindowTitle(score);
  }
  }

void Game::Update(Uint32 delta_tick, std::unique_ptr<Ball> & ball, std::vector<std::unique_ptr<Brick>> & bricks) {
  if (!ball->alive || score>7){
      this->~Game();
      return;
    }
  else{

    //Promise & Future to send & recieved the elapsed time in collision checking thread 
    std::promise<std::chrono::duration<double,std::milli>> ChkCollisionPromise;
    std::future<std::chrono::duration<double,std::milli>> ChkCollisionFuture=ChkCollisionPromise.get_future();

    //Thread for collision checking
      std::thread collision_thread([&] {
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime=std::chrono::high_resolution_clock::now();
        striker->CheckCollision(ball);       
        for(auto & element : bricks){
          if(element->CheckCollision(ball)){
            score++;
            std::cout << "Score  :"<<score<<std::endl;
          };
        }
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime=std::chrono::high_resolution_clock::now();
        ChkCollisionPromise.set_value(endTime-startTime);
      });
      collision_thread.join();


     //Thread for updating the ball's velocity and location
      std::thread update_thread([&] {
        
        //Reduce the time taken to check for the collision from the elapsed time
        ball->UpdateCenter(delta_tick-static_cast<int>(ChkCollisionFuture.get().count())); //Update the ball's coordinates
        ball->UpdateVel(screen_width, screen_height);                                      //Check if ball reached the limits of window
      });
      update_thread.join();
    }
}
