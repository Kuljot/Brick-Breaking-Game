##Introduction 

This is Capstone project for Udacity's C++ Nanodegree program. In the program a bricks breaking game implemented using the SDL Library.  

  

In the game there are 8 bricks on the top , a ball and a striker. The ball will break the brick if it collides with it and jumps back if collides with the striker. The user is able to control a striker and move it left or right so that the ball does not fall on the floor. If the ball falls on the floor instead of the striker, the game will terminate. The game will also terminate if all the bricks are broken. 

The final score will be printed at the end. 

  

##Control/External Input 

To move the striker use left or right arrow keys. It will be moving in the direction of the arrow keys unless it reached the limits of the window. 

  

Key	Action 

Right	Move the striker rightwards 

Left	Move the striker leftwards 

  

  

## Dependencies for Running Locally 

* cmake >= 3.7 

  * All OSes: [click here for installation instructions](https://cmake.org/install/) 

* make >= 4.1 (Linux, Mac), 3.81 (Windows) 

  * Linux: make is installed by default on most Linux distros 

  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/) 

  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm) 

* SDL2 >= 2.0 

  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation) 

  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.  

* gcc/g++ >= 5.4 

  * Linux: gcc / g++ is installed by default on most Linux distros 

  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/) 

  * Windows: recommend using [MinGW](http://www.mingw.org/) 

  

## Basic Build Instructions 

  

1. Clone this repo. 

2. Make a build directory in the top level directory: mkdir build && cd build 

3. Compile: cmake .. && make 

4. Run it: ./BreakGame 

  

  

##Project Files 

#main.cpp 

main.cpp is the starting point of the program. It constructs renderer, controller and the game objects with default graphics parameters. Also prints out the final score on end. 

  

#renderer.h and renderer.cpp  

renderer.h and renderer.cpp defines the constructor, default constructor and destructor for the renderer object and also defines a method RenderCircle to help draw the ball by making multiple diametrical lines. Also, Render method is defined in these files to draw all the objects on the using the SDL library. UpdateWindowTitle method that shows the current score on the title is defined in these files. 

  

#controller.h and controller.cpp 

controller.h and controller.cpp defines the constructor, default constructor and the destructor for the controller object also defines a method HandleInput to take input from the keyboard and call the Move method of the Striker class to update the position of the striker 

  

#game.h and game.cpp 

game.h and game.cpp declares all the in-game objects like striker, ball & bricks as unique pointers and also defines the constructor, default constructor, copy and move constructors/ assignment operators and a destructor for the game class. Also, it defines the method Run to continously call the HandleInput, Render, UpdateWindow and the Update method keep game running wih time. Update method updates the position of the ball based on the elapsed time and check if it has collided with other objects. 

  

#striker.h and striker.cpp 

striker.h and striker.cpp defines constructor, default constructor, copy and move constructors/ assignment operators and a destructor for Striker class. The class also includes two methods Move and CheckCollision. The Move method takes a grid width as an argument and moves the striker towards left or right depending on the direction of the movement. The CheckCollision method checks if there is a collision between the striker and the ball, and in case of a collision, it reflects back the ball and also checks if ball fails to colide with striker. 

  

#ball.h and ball.cpp 

ball.h and ball.cpp defines constructor, default constructor, copy and move constructors/ assignment operators and a destructor for ball class. The constructor provides it random velocity and angle in downwards direction on starting.The class also includes two methods UpdateCenter and UpdateVel. The UpdateVel method checks if the ball has reached the edges of the window and it reflects it back by changing the velocity. The UpdateCenter method updates the coordinates of the center of ball based on te time elapsed and velocity. 

  

#brick.h and brick.cpp 

brick.h and brick.cpp defines constructor, default constructor, copy and move constructors/ assignment operators and a destructor for Brick class. The class also includes a method CheckCollision that checks if there is a collision between the brick and the ball, and in case of a collision, it changes the ball's velocity to negative and make the alive status of the brick as false so that it no longer gets considered for rendering and collision checking. 

  

##Rubric Points 

Below are the rubric points that are implemented in this project. 

  

#Loop, Functions, I/O 

* The project demonstrates an understanding of C++ functions and control structures. The project code is   organized into functions. 

* The project accepts user input and processes the input as in this program in the file controller.cpp HandleInput method is defined to take keyboard instructions to move the striker 

  

#Object Oriented Programming 

* The project uses Object Oriented Programming techniques. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks. 

* Classes use appropriate access specifiers for class members. All class data members are explicitly specified as public, protected, or private. 

* Classes abstract implementation details from their interfaces. (e.g. see game.cpp) 

  

#Memory management 

* The project makes use of references in function declarations. (e.g. see Update method of Game class) 

* The project uses destructors appropriately (Prints on the screen when destructors run to show all the objects are destroyed e.g. destructors in renderer.cpp and game.cpp files). 

* The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate (see constructor in renderer.cpp and game.cpp also the logs printed on the terminal shows running of constructors and destructors) 

* The project follows the Rule of 5. (check game.cpp, renderer.cpp because in these classes members are declared as pointers) 

* The project uses smart pointers instead of raw pointers. (e.g. check game.cpp in which game objects like bricks, ball, striker are declared as unique pointers) 

  

#Concurrency 

* The project uses multithreading (In the Update method of the Game class multithreading is used to separate the collision checking and ball's state update functions) 

* A promise and future is used in the project (In the Update method of the Game future and promise is used to send the time it took to check collision to the update_thread to reduce it from the overall elapsed time) 

 
