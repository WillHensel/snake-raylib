//
// Created by will on 1/10/2025.
//

#include "AppleRenderComponent.h"
#include "raylib.h"
#include "Apple.h"
#include "GameInfo.h"

void AppleRenderComponent::draw(Apple& apple) {
    Vector2 pos = GameInfo::getScreenSpaceCoordinateOfCell(apple.getPosition());
    DrawCircle(pos.x, pos.y, GameInfo::getCellSize() / 2, RED);
}
