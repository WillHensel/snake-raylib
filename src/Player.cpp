//
// Created by will on 1/8/2025.
//

#include "Player.h"

Player::Player() {
    lookingAt = {-1, 0};
    head = new PlayerCell{
        .pos = {0, 0},
    };
}

void Player::moveForward() {
    Vector2 prevPos = head->pos;
    head->pos.x += lookingAt.x;
    head->pos.y += lookingAt.y;
    
    PlayerCell* next = head->next;
    Vector2 nextPos;
    
    while (next != nullptr) {
        if (next->isNew) {
            next->isNew = false;
            break;
        }
        
        nextPos = next->pos;
        
        next->pos.x = prevPos.x;
        next->pos.y = prevPos.y;
        prevPos = next->pos;
        
        next = next->next;
    }
}

void Player::addTail() {
    PlayerCell* next = head;
    while (next->next != nullptr) {
        next = next->next;
    }
    
    next->next = new PlayerCell{Vector2{next->pos.x, next->pos.y}};
    next->next->isNew = true;
}

Vector2 Player::getTailPos() {
    PlayerCell* next = head;
    while (next->next != nullptr) {
        next = next->next;
    }
    return next->pos;
}

int Player::getCellCount() {
    int count = 1;
    PlayerCell* next = head;
    while (next->next != nullptr) {
        count++;
        next = next->next;
    }
    
    return count;
}

Vector2 Player::getHeadPos() {
    return head->pos;
}