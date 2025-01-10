//
// Created by will on 1/9/2025.
//

#include "GameAreaRenderComponent.h"

void GameAreaRenderComponent::draw() {
    ClearBackground(DARKGRAY);
    
    Rectangle outlineRect{
            .x =  gameAreaScreenCoordinates_.x,
            .y =  gameAreaScreenCoordinates_.y,
            .width =  gameAreaSize_,
            .height =  gameAreaSize_};
    DrawRectangleRoundedLinesEx(outlineRect, 0.025, 3, 4, LIGHTGRAY);
}