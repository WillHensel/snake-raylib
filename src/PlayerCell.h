//
// Created by will on 1/8/2025.
//

#ifndef SNAKE_RAYLIB_PLAYERCELL_H
#define SNAKE_RAYLIB_PLAYERCELL_H

#include "raylib.h"

struct PlayerCell {
    Vector2 pos;
    PlayerCell* next = nullptr;
    bool isNew = false;
};

#endif // SNAKE_RAYLIB_PLAYERCELL_H
