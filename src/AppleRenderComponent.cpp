//
// Created by will on 1/10/2025.
//

#include "AppleRenderComponent.h"
#include "raylib.h"
#include "Apple.h"
#include "GameInfo.h"

void AppleRenderComponent::draw(Apple& apple) {
    Vector2 renderPosition = Vector2{apple.getPosition().x + 0.5f, apple.getPosition().y + 0.5f};
    Vector2 screenPosition = GameInfo::getScreenSpaceCoordinateOfCell(renderPosition);
    DrawCircle(screenPosition.x, screenPosition.y, GameInfo::getCellSize() / 2, RED);
}
