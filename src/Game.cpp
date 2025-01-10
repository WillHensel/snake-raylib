//
// Created by will on 1/8/2025.
//

#include <vector>
#include "Player.h"
#include "Game.h"


void Game::gameLoop() {
    while (!WindowShouldClose()) {
        BeginDrawing();

        renderComponent.draw();
        player_.update();

        EndDrawing();
    }
}
