#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "striker.h"
#include <memory>

class Controller
{
public:
    bool running;
    Controller();
    Controller(bool _status);
    ~Controller();
    Controller(const Controller &other) = delete;          // Copy Constructor
    Controller(Controller &&other) = delete;               // Move Constructor
    Controller &operator=(const Controller &rhs) = delete; // Copy Assignment
    Controller &operator=(Controller &&rhs) = delete;      // Move Assignment

    void HandleInput(std::unique_ptr<Striker> &striker, int grid_width);
};

#endif