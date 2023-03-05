#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include <SDL2/SDL.h>
#include<memory>
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "striker.h"

class Game {
 public:
  int screen_width;
  int screen_height;
  int score=0;
  std::unique_ptr<Striker> striker;
  std::vector<std::unique_ptr<Brick>> bricks;
  std::unique_ptr<Ball> ball;
  Game();
  Game(int _width, int _height);
  ~Game();

  Game(const Game & other)=delete;  //Copy Constructor
  Game(Game && other);  //Move Constructor
  Game& operator=(const Game & rhs)=delete; //Copy Assignment
  Game& operator=(Game&& rhs);  //Move Assignment

  void Run(Controller &controller, Renderer &renderer,std::size_t target_frame_duration);
 private:
  void Update(Uint32 delta_tick, std::unique_ptr<Ball> & ball, std::vector<std::unique_ptr<Brick>> & bricks);
 
};

#endif