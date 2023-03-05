#include "controller.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "striker.h"

Controller::Controller(){
  running=true;
}
Controller::Controller(bool _status){
  running=_status;
}
Controller::~Controller(){
  running=false;
}

//Handle the Keyboard Input
void Controller::HandleInput(std::unique_ptr<Striker> & striker, int grid_width)
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
        running = false;
    } 
    else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          striker->direction=Towards::Left;
          striker->Move(grid_width);
          break;

        case SDLK_RIGHT:
          striker->direction=Towards::Right;
          striker->Move(grid_width);
          break;
      }
    }
  }
}