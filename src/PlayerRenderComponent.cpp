//
// Created by will on 1/9/2025.
//

#include <vector>
#include "PlayerRenderComponent.h"
#include "Player.h"
#include "GameInfo.h"

void PlayerRenderComponent::draw(Player &player) {
    std::vector<Vector2> cellPositions = player.getCellPositions();

    for (auto pos: cellPositions) {
        Vector2 screenCoord = GameInfo::getScreenSpaceCoordinateOfCell(pos);
        Rectangle cellRect{
                .x = screenCoord.x,
                .y = screenCoord.y,
                .width = GameInfo::getCellSize(),
                .height = GameInfo::getCellSize() 
        };
        DrawRectangleRounded(cellRect, 0.2, 3, LIGHTGRAY);
    }
}