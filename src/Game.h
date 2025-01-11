//
// Created by will on 1/8/2025.
//

#ifndef SNAKE_RAYLIB_GAME_H
#define SNAKE_RAYLIB_GAME_H

#include <array>
#include <iostream>
#include "GameInfo.h"

class Apple;
class GameAreaRenderComponent;
class GameUiComponent;

class Game {
public:
    Game();
    ~Game();
    void gameLoop();
private:
    int score_ = 0;

    Player* player_;
    Apple* apple_;
    GameAreaRenderComponent* renderComponent_;
    GameUiComponent* uiComponent_;
};


#endif //SNAKE_RAYLIB_GAME_H
