//
// Created by will on 1/10/2025.
//

#include <iostream>
#include "Apple.h"
#include "Player.h"
#include "AppleRenderComponent.h"
#include "GameInfo.h"

Apple::Apple(Player &player, std::function<void()> updateScore): player_(player), updateScoreCallback_(updateScore) {
        renderComponent_ = new AppleRenderComponent();
        initPosition();
};

Apple::~Apple() {
    delete renderComponent_;
}

void Apple::update() {
    if (checkForHeadCollision()) {
        updateScoreCallback_();
    }
    renderComponent_->draw(*this);
}

void Apple::initPosition() {
    std::vector<Vector2> playerCellPositions = player_.getCellPositions();
    do {
        Vector2 applePos{
                (float)(rand() % GameInfo::getNumCells() - 10),
                (float)(rand() % GameInfo::getNumCells() - 10)
        };
        position_ = applePos;
    } while (player_.isCellAt(position_, true));
}

Vector2 Apple::getPosition() {
    return position_;
}

bool Apple::checkForHeadCollision() {
    Vector2 headPosition = player_.getHeadPos();
    return position_.x == headPosition.x && position_.y == headPosition.y;
}
