//
// Created by will on 1/8/2025.
//

#include <functional>

#include "Player.h"
#include "Game.h"
#include "Apple.h"
#include "GameAreaRenderComponent.h"
#include "GameUiComponent.h"

Game::Game() {
    player_ = new Player();
    renderComponent_ = new GameAreaRenderComponent();
    uiComponent_ = new GameUiComponent();
    spawnNewApple();
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

        renderComponent_->draw();
        player_->update();
        
        if (apple_ != nullptr) {
            apple_->update();
        }
        
        uiComponent_->drawScore(score_);

        EndDrawing();
    }
}

void Game::updateScore() {
    delete apple_;
    apple_ = nullptr;
    score_ += 5;
    spawnNewApple();
    player_->addTail();
}

void Game::spawnNewApple() {
    if (apple_ == nullptr)
        apple_ = new Apple(*player_, [=] { updateScore(); });
}
