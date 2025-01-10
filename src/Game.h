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
#include "Apple.h"
#include "AppleRenderComponent.h"
#include "GameInfo.h"

class Game {
public:
    void gameLoop();
private:
    int score_ = 0;

    Player player_{new PlayerRenderComponent()};
    Apple apple_{new AppleRenderComponent(), player_};
    GameAreaRenderComponent renderComponent{};
};


#endif //SNAKE_RAYLIB_GAME_H
