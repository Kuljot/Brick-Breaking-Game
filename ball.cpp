#include "ball.h"
#include <cmath>
#include<thread>
#include <iostream>

Ball::Ball(){
    center_x=400;
    center_y=400;
    float x=-PI/3-static_cast<float>(std::rand())/(RAND_MAX/(2*PI/3));// Random angle between -PI/2 +/- PI/6
    vel_x=vel*std::cos(x);
    vel_y=-vel*std::sin(x);
}

Ball::Ball(int screen_width, int screen_height){
    center_x=screen_width/2;
    center_y=screen_height/2;
    float x=-PI/3-static_cast<float>(std::rand())/(RAND_MAX/(2*PI/3));// Random angle between -PI/2 +/- PI/6
    
    vel_x=vel*std::cos(x);
    vel_y=-vel*std::sin(x);
}

Ball::~Ball(){
    std::cout<<"Ball Destructor"<<std::endl;
};

Ball::Ball(const Ball & other){};  //Copy Constructor
//Move Constructor
Ball::Ball(Ball && other){
    this->alive=std::move(other.alive);
    this->center_x=std::move(other.center_x);
    this->center_y=std::move(other.center_y);
    this->vel_x=std::move(other.vel_x);
    this->vel_y=std::move(other.vel_y);
};  

Ball& Ball::operator=(const Ball & rhs){}; //Copy Assignment
//Move Assignment
Ball& Ball::operator=(Ball&& rhs){
    this->alive=std::move(rhs.alive);
    this->center_x=std::move(rhs.center_x);
    this->center_y=std::move(rhs.center_y);
    this->vel_x=std::move(rhs.vel_x);
    this->vel_y=std::move(rhs.vel_y);
};  



void Ball::UpdateVel(int screen_width, int screen_height){
    if((center_x <= radius && vel_x<0) || (center_x >= (screen_width-radius) && vel_x>0))
    {
        vel_x= -vel_x;
    }
    if(center_y <=radius && vel_y<0)
    {
        vel_y= -vel_y;
        
    }

}
 
void Ball::UpdateCenter(int delta_T){
    if (center_x <= 800-radius || center_x >= radius){
        center_x+=vel_x*delta_T*0.2;    
    }
    else if(center_x > 800-radius){
        center_x=800-radius;    
    }
    else if(center_x < radius){
        center_x=radius;    
    }
    center_y+=vel_y*delta_T*0.8;
}
