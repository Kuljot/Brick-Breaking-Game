#include "brick.h"
#include <cmath>
#include <iostream>

Brick::Brick(){
    std::cout<<"Brick Constructor()"<<std::endl;
    center_x=50;
    center_y=20;
}
Brick::Brick(float _x, float _y){
    std::cout<<"Brick Constructor"<<std::endl;
    center_x=_x;
    center_y=_y;
}
Brick::~Brick(){
    std::cout<<"Brick Destructor"<<std::endl;
};

//Copy Constructor
Brick::Brick(const Brick& other){
    std::cout<<"Brick Copy Constructor"<<std::endl;
    this->alive=other.alive;
    this->center_x=other.center_x;
    this->center_y=other.center_y;
}

//Copy Assignment
Brick & Brick::operator=(const Brick & rhs){
    std::cout<<"Brick Copy Assignment"<<std::endl;
    if(this!=&rhs){
        this->alive=rhs.alive;
        this->center_x=rhs.center_x;
        this->center_y=rhs.center_y;
    }
    return *this;
}

//Move Constructor
Brick::Brick(Brick && other){
    std::cout<<"Brick Move Constructor"<<std::endl;
    alive=std::move(other.alive);
    center_x=std::move(other.center_x);
    center_y=std::move(other.center_y);
}

//Move Assignment
Brick & Brick::operator=(Brick && rhs){
    std::cout<<"Brick Move Assignment"<<std::endl;
    if(this!=&rhs){
        this->alive=std::move(rhs.alive);
        this->center_x=std::move(rhs.center_x);
        this->center_y=std::move(rhs.center_y);
    }
    return *this;
}




bool Brick::CheckCollision(std::unique_ptr<Ball> & ball){
    //Check collision with bricks
    if(std::abs(ball->center_y-(center_y)) <= (height/2+ball->radius)){
        if (alive){
            if(std::abs(ball->center_x-center_x) <= (width/2))
                {
                    std::cout<<"Brick Collision"<<std::endl;
                    ball->collision=true;
                    alive=false;
                    if ((ball->center_y>=center_y && ball->vel_y<0)||(ball->center_y<center_y && ball->vel_y>0)){
                        ball->vel_y= -ball->vel_y;
                        return true;
                    }
                    else return false;
                }
        }
    }
}
