#include "renderer.h"
#include <iostream>
#include <string>
#include <SDL2/SDL_render.h>
Renderer::Renderer(){
  screen_width=800;
  screen_height=800;
  grid_width=15;
  grid_height=15;
};
void Renderer::RenderCircle(SDL_Renderer* renderer, int x, int y, int radius) {
  for (int angle = 0; angle < 360; angle += 3) {
    int x2 = x + radius * cos(angle * M_PI / 180.0);
    int y2 = y + radius * sin(angle * M_PI / 180.0);
    SDL_RenderDrawLine(renderer, x, y, x2, y2);
  }
}

Renderer::Renderer(const std::size_t screen_width,const std::size_t screen_height,const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height){
  
  std::cout << "Renderer constructor" << std::endl;
  
  // Initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  if (SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL could not initialize.\n";
    std::cout << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Break Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, screen_width,screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cout << "Window could not be created.\n";
    std::cout << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cout << "Renderer could not be created.\n";
    std::cout << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer(){
  SDL_DestroyWindow(sdl_window);
  std::cout << "Renderer destructor" << std::endl;
  SDL_Quit();
}

void Renderer::Render(std::unique_ptr<Striker> & striker, std::unique_ptr<Ball> & ball, std::vector<std::unique_ptr<Brick>> & bricks) { 
  
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
  SDL_RenderClear(sdl_renderer);

  //Render Ball
  SDL_SetRenderDrawColor(sdl_renderer, 255, 51, 204, 0xFF);
  RenderCircle(sdl_renderer, ball->center_x, ball->center_y, ball->radius);

  //Render Striker
  SDL_SetRenderDrawColor(sdl_renderer, 0, 153, 255, 0xFF);
  SDL_Rect StrikerRect={striker->center_x-striker->width/2, static_cast<int>(screen_height-(striker->center_y+striker->height/2)),striker->width,striker->height};
  SDL_RenderFillRect(sdl_renderer, &StrikerRect);

  //Render Bricks
  SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 0xFF);
  for (auto & element : bricks){
    if (element->alive){
      SDL_Rect BrickRect={element->center_x-element->width/2,element->center_y+element->height/2,element->width,element->height};
      SDL_RenderFillRect(sdl_renderer, &BrickRect);
    }
  }
  //Render Bricks
  SDL_SetRenderDrawColor(sdl_renderer, 102, 255, 102, 0xFF);
  for (auto & element : bricks){
    if (element->alive){
      SDL_Rect BrickRect={element->center_x-element->width/2, element->center_y+element->height/2,element->width,element->height};
      SDL_RenderDrawRect(sdl_renderer, &BrickRect);
     }
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score) {
  std::string title{"Break Score: " + std::to_string(score)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
