//
// Created by will on 1/10/2025.
//

#ifndef SNAKE_RAYLIB_GAMEINFO_H
#define SNAKE_RAYLIB_GAMEINFO_H

#include "raylib.h"

class GameInfo {
public:
    GameInfo() = delete;
    
    static float getGameAreaSize() {
        return 500;
    }
    static Vector2 getGameAreaScreenCoordinates() {
        return {  
                (float) GetRenderWidth() / 2.0f - getGameAreaSize() / 2.0f,
                (float) GetRenderHeight() / 2.0f - getGameAreaSize() / 2.0f
        };
    }
    static int getNumCells() {
        return 20;
    }
    static float getCellSize() {
        return GameInfo::getGameAreaSize() / getNumCells();
    }
    static Vector2 getScreenSpaceCoordinateOfCell(Vector2 cellCoordinate) {
        return Vector2{
                .x = (cellCoordinate.x + GameInfo::getGameAreaSize() / getCellSize() / 2) * getCellSize() +
                     getGameAreaScreenCoordinates().x,
                .y = (cellCoordinate.y + GameInfo::getGameAreaSize() / getCellSize() / 2) * getCellSize() +
                     getGameAreaScreenCoordinates().y,
        };
    }
};

#endif //SNAKE_RAYLIB_GAMEINFO_H
