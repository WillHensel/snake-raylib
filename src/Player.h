//
// Created by will on 1/8/2025.
//

#ifndef SNAKE_RAYLIB_PLAYER_H
#define SNAKE_RAYLIB_PLAYER_H

#include <vector>
#include "PlayerCell.h"
#include "raylib.h"

class PlayerRenderComponent;

class Player {
public:
    explicit Player(PlayerRenderComponent*);
    void update();
    void moveForward();
    void addTail();
    Vector2 getHeadPos();
    Vector2 getTailPos();
    std::vector<Vector2> getCellPositions();
    int getCellCount();
    
private:
    Vector2 lookingAt{};
    PlayerCell* head;
    
    PlayerRenderComponent* renderComponent_;
};


#endif //SNAKE_RAYLIB_PLAYER_H
