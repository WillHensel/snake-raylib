//
// Created by will on 1/8/2025.
//

#include "Player.h"

#include <utility>
#include <iostream>
#include "PlayerRenderComponent.h"

Player::Player() {
    renderComponent_ = new PlayerRenderComponent();
    
    // Initially looking left
    lookingAt_ = {-1, 0};
    
    initialize(5);
}

Player::~Player() {
//    std::cout << "Player destroyed" << std::endl;
    
    delete renderComponent_;

    PlayerCell* next = head_;
    while (next != nullptr) {
        PlayerCell* temp = next;
        next = next->next;
        temp->next = nullptr;
        delete temp;
    }
}

void Player::initialize(int numCells) {
    head_ = new PlayerCell{
        .pos = {(-1.0f * (float)numCells), 0},
        .isNew = false
    };
    
    PlayerCell* current = head_;
    int runningCellCount = 1;
    while (runningCellCount < numCells) {
        current->next = new PlayerCell{
            .pos = {current->pos.x + 1, 0},
            .isNew = false
        };
        current = current->next;
        runningCellCount++;
    }
}

void Player::update() {
    handleInput();
    
    double currentTime = GetTime();
    if (currentTime - lastMove_ >= 0.15) {
        lastMove_ = currentTime;
        moveForward();
        movesSinceLastInput++;
    }
    renderComponent_->draw(*this);
}

void Player::handleInput() {
    if (movesSinceLastInput < 1) {
        return;
    }
    
    int keyPressed = GetKeyPressed();
    switch (keyPressed) {
        case KEY_W:
            if (lookingAt_.x == 0 && lookingAt_.y == 1)
                break;

            lookingAt_ = Vector2{0, -1};
            movesSinceLastInput = 0;
            break;

        case KEY_S:
            if (lookingAt_.x == 0 && lookingAt_.y == -1)
                break;

            lookingAt_ = Vector2{0, 1};
            movesSinceLastInput = 0;
            break;

        case KEY_D:
            if (lookingAt_.x == -1 && lookingAt_.y == 0)
                break;

            lookingAt_ = Vector2{1, 0};
            movesSinceLastInput = 0;
            break;
        case KEY_A:
            if (lookingAt_.x == 1 && lookingAt_.y == 0)
                break;

            lookingAt_ = Vector2{-1, 0};
            movesSinceLastInput = 0;
            break;
    }
    
}

void Player::moveForward() {
    // Save the current head position
    Vector2 prevPos = head_->pos;
    
    // Advance the head forward
    head_->pos.x += lookingAt_.x;
    head_->pos.y += lookingAt_.y;
    
    PlayerCell* next = head_->next;
    Vector2 nextPos;
    
    while (next != nullptr) {
        // If the next cell is a new tail, it stays where it is for its first move
        if (next->isNew) {
            next->isNew = false;
            break;
        }
        
        nextPos = next->pos;
        
        next->pos.x = prevPos.x;
        next->pos.y = prevPos.y;
        prevPos = nextPos;
        
        next = next->next;
    }
    
//    std::cout << "Head position: (" << getHeadPos().x << ", " << getHeadPos().y << ")" << std::endl;
}

void Player::addTail() {
    PlayerCell* next = head_;
    while (next->next != nullptr) {
        next = next->next;
    }
    
    next->next = new PlayerCell{.pos = Vector2{next->pos.x, next->pos.y}, .isNew = true};
}

Vector2 Player::getTailPos() {
    PlayerCell* next = head_;
    while (next->next != nullptr) {
        next = next->next;
    }
    return next->pos;
}

std::vector<Vector2> Player::getCellPositions() {
    std::vector<Vector2> result{};
    PlayerCell* next = head_;
    while (next != nullptr) {
        result.push_back(next->pos);
        next = next->next;
    }
    
    return result;
};

int Player::getCellCount() {
    int count = 0;
    PlayerCell* next = head_;
    while (next != nullptr) {
        count++;
        next = next->next;
    }
    
    return count;
}

Vector2 Player::getHeadPos() {
    return head_->pos;
}
