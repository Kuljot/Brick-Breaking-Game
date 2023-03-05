#ifndef STRIKER_H
#define STRIKER_H
#include "ball.h"
#include <vector>
#include<memory>
#include <SDL2/SDL.h>
enum class Towards{Left, Right};
class Striker{
 public:
   const int width=200;
   const int height=50;
   Towards direction;
   int center_x;
   int center_y;
   Striker();
   Striker(int width, int height);
   ~Striker();

  
   void CheckCollision(std::unique_ptr<Ball> & ball);
   void Move(int grid_width);
    
};

#endif