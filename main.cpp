#include <iostream>
#include <memory>
#include<fstream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main(){
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{800};
  constexpr std::size_t kScreenHeight{800};
  constexpr std::size_t kGridWidth{15};
  constexpr std::size_t kGridHeight{15};  
  
  //Renderer, Controller, Game Run;
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kScreenWidth, kScreenHeight);
  game.Run(controller, renderer, kMsPerFrame);
  SDL_Delay(5000);
  
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Final Score  :"<<game.score<<std::endl;
  return 0;
}