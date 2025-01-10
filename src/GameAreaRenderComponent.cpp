//
// Created by will on 1/9/2025.
//

#include "GameAreaRenderComponent.h"
#include "GameInfo.h"

void GameAreaRenderComponent::draw() {
    ClearBackground(DARKGRAY);
    
    Rectangle outlineRect{
            .x =  GameInfo::getGameAreaScreenCoordinates().x,
            .y =  GameInfo::getGameAreaScreenCoordinates().y,
            .width =  GameInfo::getGameAreaSize(),
            .height =  GameInfo::getGameAreaSize()};
    DrawRectangleRoundedLinesEx(outlineRect, 0.025, 3, 4, LIGHTGRAY);
}