//
// Created by will on 1/8/2025.
//

#include "Player.h"

#include <utility>
#include <iostream>
#include "PlayerRenderComponent.h"

Player::Player(PlayerRenderComponent* renderComponent)
        : renderComponent_(renderComponent) {
    
    lookingAt = {-1, 0};
    head = new PlayerCell{
        .pos = {-2, 0},
        .isNew = false
    };
    head->next = new PlayerCell{
        .pos = {-1, 0},
        .isNew = false
    };
    head->next->next = new PlayerCell{
        .pos = {0, 0},
        .isNew = false,
    };
}

Player::~Player() {
    std::cout << "Player destroyed" << std::endl;
    
    delete renderComponent_;

    PlayerCell* next = head;
    while (next != nullptr) {
        PlayerCell* temp = next;
        next = next->next;
        temp->next = nullptr;
        delete temp;
    }
}


void Player::update() {
    renderComponent_->draw(*this);
}

void Player::moveForward() {
    // Save the current head position
    Vector2 prevPos = head->pos;
    
    // Advance the head forward
    head->pos.x += lookingAt.x;
    head->pos.y += lookingAt.y;
    
    PlayerCell* next = head->next;
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
}

void Player::addTail() {
    PlayerCell* next = head;
    while (next->next != nullptr) {
        next = next->next;
    }
    
    next->next = new PlayerCell{.pos = Vector2{next->pos.x, next->pos.y}, .isNew = true};
}

Vector2 Player::getTailPos() {
    PlayerCell* next = head;
    while (next->next != nullptr) {
        next = next->next;
    }
    return next->pos;
}

std::vector<Vector2> Player::getCellPositions() {
    std::vector<Vector2> result{};
    PlayerCell* next = head;
    while (next != nullptr) {
        result.push_back(next->pos);
        next = next->next;
    }
    
    return result;
};

int Player::getCellCount() {
    int count = 0;
    PlayerCell* next = head;
    while (next != nullptr) {
        count++;
        next = next->next;
    }
    
    return count;
}

Vector2 Player::getHeadPos() {
    return head->pos;
}
