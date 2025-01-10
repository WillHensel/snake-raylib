//
// Created by will on 1/9/2025.
//

#ifndef SNAKE_RAYLIB_GAMEAREARENDERCOMPONENT_H
#define SNAKE_RAYLIB_GAMEAREARENDERCOMPONENT_H


#include "raylib.h"

class GameAreaRenderComponent {
public:
    GameAreaRenderComponent(float gameAreaSize, Vector2 gameAreaScreenCoordinates)
            : gameAreaSize_(gameAreaSize), gameAreaScreenCoordinates_(gameAreaScreenCoordinates) {}
            
    virtual void draw();

private:
    float gameAreaSize_;
    Vector2 gameAreaScreenCoordinates_;
};


#endif //SNAKE_RAYLIB_GAMEAREARENDERCOMPONENT_H
