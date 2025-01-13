//
// Created by will on 1/10/2025.
//

#ifndef SNAKE_RAYLIB_GAMEUICOMPONENT_H
#define SNAKE_RAYLIB_GAMEUICOMPONENT_H


#include "raylib.h"

class GameUiComponent {
public:
    void drawScore(int);
    void drawStartScreen(const std::function<void()>&);
    void drawGameOverScreen(const std::function<void()>&);
private:
};


#endif //SNAKE_RAYLIB_GAMEUICOMPONENT_H
