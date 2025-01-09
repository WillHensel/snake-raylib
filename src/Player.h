//
// Created by will on 1/8/2025.
//

#ifndef SNAKE_RAYLIB_PLAYER_H
#define SNAKE_RAYLIB_PLAYER_H

#include "PlayerCell.h";
#include "raylib.h";


class Player {
public:
    Player();
    void moveForward();
    void addTail();
    Vector2 getHeadPos();
    Vector2 getTailPos();
    int getCellCount();
    
private:
    Vector2 lookingAt{};
    PlayerCell* head;
};


#endif //SNAKE_RAYLIB_PLAYER_H
