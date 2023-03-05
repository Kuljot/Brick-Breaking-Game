#ifndef BALL_H
#define BALL_H

#include <vector>
#include <SDL2/SDL.h>


class Ball {
 public:
  const int vel=2;//Pixels per second
  const int radius{15};
  bool alive=true;
  bool collision=false;
  int center_x;
  int center_y;
  float vel_x;
  float vel_y;
  const float PI=3.14159;

  Ball();
  Ball(int screen_width, int screen_height);
  ~Ball();

  Ball(const Ball & other);  //Copy Constructor
  Ball(Ball && other);  //Move Constructor
  Ball& operator=(const Ball & rhs); //Copy Assignment
  Ball& operator=(Ball&& rhs);  //Move Assignment

  //Setter
  void UpdateCenter(int delta_T);
  void UpdateVel(int screen_width, int screen_height);
};

#endif