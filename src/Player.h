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
    explicit Player();
    ~Player();
    void update();

    void addTail();
    Vector2 getHeadPos();
    
    std::vector<Vector2> getCellPositions();
    
private:
    void handleInput();
    void moveForward();
    void initialize(int);
    Vector2 getTailPos();
    int getCellCount();
    
    
    int movesSinceLastInput = 1; 
    double lastMove_ = 0;
    Vector2 lookingAt_{};
    PlayerCell* head_;
    
    PlayerRenderComponent* renderComponent_;
};


#endif //SNAKE_RAYLIB_PLAYER_H
