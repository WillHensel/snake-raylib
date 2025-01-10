//
// Created by will on 1/9/2025.
//

#ifndef SNAKE_RAYLIB_PLAYERRENDERCOMPONENT_H
#define SNAKE_RAYLIB_PLAYERRENDERCOMPONENT_H


#include "raylib.h"

// Forward reference prevents a circular dependency
class Player;

class PlayerRenderComponent {
public:
    PlayerRenderComponent(float, Vector2);
    void draw(Player&) const;
private:
    float gameAreaSize_;
    Vector2 gameAreaScreenCoordinates_;
};


#endif //SNAKE_RAYLIB_PLAYERRENDERCOMPONENT_H
