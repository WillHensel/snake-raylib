//
// Created by will on 1/9/2025.
//

#include <vector>
#include "PlayerRenderComponent.h"
#include "Player.h"

PlayerRenderComponent::PlayerRenderComponent(float gameAreaSize, Vector2 gameAreaScreenCoordinates)
        : gameAreaSize_(gameAreaSize), gameAreaScreenCoordinates_(gameAreaScreenCoordinates) {}

void PlayerRenderComponent::draw(Player &player) const {
    float cellSize = gameAreaSize_ / 20;

    std::vector<Vector2> cellPositions = player.getCellPositions();

    for (auto pos: cellPositions) {
        Rectangle cellRect{
                .x = (pos.x + gameAreaSize_ / cellSize / 2) * cellSize + gameAreaScreenCoordinates_.x,
                .y = (pos.y + gameAreaSize_ / cellSize / 2) * cellSize + gameAreaScreenCoordinates_.y,
                .width = cellSize,
                .height = cellSize
        };
        DrawRectangleRounded(cellRect, 0.2, 3, LIGHTGRAY);
    }
}