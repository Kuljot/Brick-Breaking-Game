#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL.h>
#include "ball.h"
#include "striker.h"
#include "brick.h"


class Renderer {
 public:
  Renderer();
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

   Renderer(const Renderer &other) = delete;          // Copy Constructor
   Renderer(Renderer &&other) = delete;               // Move Constructor
   Renderer &operator=(const Renderer &rhs) = delete; // Copy Assignment
   Renderer &operator=(Renderer &&rhs) = delete;      // Move Assignment

  void RenderCircle(SDL_Renderer* renderer, int x, int y, int radius);
  void Render(std::unique_ptr<Striker> & striker, std::unique_ptr<Ball> & ball, std::vector<std::unique_ptr<Brick>> & bricks);
  void UpdateWindowTitle(int score);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

   std::size_t screen_width;
   std::size_t screen_height;
   std::size_t grid_width;
   std::size_t grid_height;
};

#endif