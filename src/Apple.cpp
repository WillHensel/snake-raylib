//
// Created by will on 1/10/2025.
//

#include "Apple.h"
#include "Player.h"
#include "AppleRenderComponent.h"
#include "GameInfo.h"

Apple::Apple(Player &player): player_(player) {
        renderComponent_ = new AppleRenderComponent();
        initPosition();
};

Apple::~Apple() {
    delete renderComponent_;
}

void Apple::update() {
    renderComponent_->draw(*this);
}

void Apple::initPosition() {
    std::vector<Vector2> playerCellPositions = player_.getCellPositions();
    Vector2 applePos{
            (float)(rand() % GameInfo::getNumCells() - 10 + (GameInfo::getCellSize() / 2)),
            (float)(rand() % GameInfo::getNumCells() - 10 + (GameInfo::getCellSize() / 2))
    };
    position_ = GameInfo::getScreenSpaceCoordinateOfCell(applePos);
}

Vector2 Apple::getPosition() {
    return position_;
}
