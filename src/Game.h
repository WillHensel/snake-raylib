//
// Created by will on 1/8/2025.
//

#ifndef SNAKE_RAYLIB_GAME_H
#define SNAKE_RAYLIB_GAME_H

#include <array>
#include <iostream>
#include "Player.h"
#include "GameAreaRenderComponent.h"
#include "PlayerRenderComponent.h"

class Game {
public:
    Game() : player_(Player{new PlayerRenderComponent(gameAreaSize_, gameAreaScreenCoordinates_)}) {};
    void gameLoop();

private:
    int score_ = 0;
    float gameAreaSize_ = 500;
    Vector2 gameAreaScreenCoordinates_{
            (float) GetRenderWidth() / 2.0f - gameAreaSize_ / 2.0f,
            (float) GetRenderHeight() / 2.0f - gameAreaSize_ / 2.0f
    };

    Player player_;

    GameAreaRenderComponent renderComponent{gameAreaSize_, gameAreaScreenCoordinates_};
};


#endif //SNAKE_RAYLIB_GAME_H
