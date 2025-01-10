//
// Created by will on 1/9/2025.
//

#ifndef SNAKE_RAYLIB_APPLICATION_H
#define SNAKE_RAYLIB_APPLICATION_H


#include "Game.h"

class Application {
public:
    Application();
    ~Application();
    
    Vector2 getWindowSize();
    void startGame();
private:
    Game game_;
    Vector2 windowSize_ = Vector2{1280, 800}; 
};


#endif //SNAKE_RAYLIB_APPLICATION_H
