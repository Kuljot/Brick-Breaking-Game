#ifndef BRICK_H
#define BRICK_H

#include "ball.h"
#include <vector>
#include<memory>
#include <SDL2/SDL.h>

class Brick{
  public:
    int center_x;
    int center_y;
    int width=100;
    int height=40;
    bool alive=true;

    Brick();
    Brick(float _x, float _y);
    ~Brick();

    Brick(const Brick & other);  //Copy Constructor
    Brick(Brick && other);  //Move Constructor
    Brick& operator=(const Brick & rhs); //Copy Assignment
    Brick& operator=(Brick&& rhs);  //Move Assignment

    bool CheckCollision(std::unique_ptr<Ball> & ball);
};

#endif