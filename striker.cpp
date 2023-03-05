#include "striker.h"
#include <cmath>
#include <iostream>

Striker::Striker(){
    center_x=0;
    center_y=0;
}
Striker::Striker(int width, int height){
    center_x=width/2;
    center_y=height/2;
}
Striker::~Striker(){
    std::cout<<"Striker Destructor"<<std::endl;
};

void Striker::Move(int grid_width){
    if(direction==Towards::Left){
        if(center_x > width/2){
            if(center_x > (50+width/2)){
                center_x-=50;
            }
            else if(center_x <= (50+width/2)){
                center_x=width/2;
            }
        }
    }
    if(direction==Towards::Right){
        if(std::abs(center_x-grid_width) > (width/2)){
           if(std::abs(center_x-grid_width) > (50+width/2)){
                center_x+=50;
            }
            else if(std::abs(center_x-grid_width) <= (50+width/2)){
                center_x=grid_width-width/2;
            } 
        }
    
    }

}

void Striker::CheckCollision(std::unique_ptr<Ball> & ball){
    //Check collision with floor
    int _X=ball->center_x;
    int _Y=ball->center_y;
    if(std::abs(_X-center_x) > (width/2+ball->radius) && std::abs(_Y-(800-center_y)) <= (ball->radius))
    {
        std::cout<<"floor Collision"<<std::endl;
        ball->alive=false;
        ball->collision=true;

    }
    //Check collision with striker
    if(std::abs(_X-center_x) <= (width/2+ball->radius) && std::abs(_Y-(800-center_y)) <= (height/2+ball->radius))
    {
        std::cout<<"striker Collision"<<std::endl;
        ball->collision=true;
        ball->vel_y= -ball->vel_y;
    }
}

