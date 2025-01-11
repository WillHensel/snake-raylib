//
// Created by will on 1/8/2025.
//

#include "Player.h"
#include "Game.h"
#include "Apple.h"
#include "GameAreaRenderComponent.h"
#include "GameUiComponent.h"

Game::Game() {
    player_ = new Player();
    apple_ = new Apple(*player_);
    renderComponent_ = new GameAreaRenderComponent();
    uiComponent_ = new GameUiComponent();
}

Game::~Game() {
    delete apple_;
    delete player_;
    delete renderComponent_;
    delete uiComponent_;
}

void Game::gameLoop() {
    while (!WindowShouldClose()) {
        BeginDrawing();

        renderComponent_.draw();
        player_.update();
        apple_.update();

        EndDrawing();
    }
}
