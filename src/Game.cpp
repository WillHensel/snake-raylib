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
    renderComponent_ = new GameAreaRenderComponent();
    uiComponent_ = new GameUiComponent();
    initializeLevel();
}

Game::~Game() {
    delete apple_;
    delete player_;
    delete renderComponent_;
    delete uiComponent_;
}

void Game::initializeLevel() {
    player_ = new Player();
    spawnNewApple();
}

void Game::gameLoop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        renderComponent_->draw();

        if (gameStarted_) {
            
            if (player_ != nullptr) {
                player_->update();

                float areaSize = GameInfo::getNumCells();
                if (player_->getHeadPos().x < areaSize / 2 * -1
                    || player_->getHeadPos().y < areaSize / 2 * -1
                    || player_->getHeadPos().x > areaSize / 2
                    || player_->getHeadPos().y > areaSize / 2
                    || player_->isCellAt(player_->getHeadPos(), false)) {
                    gameOver();
                    gameOver_ = true;
                    gameStarted_ = false;
                }
            }

            if (apple_ != nullptr) {
                apple_->update();
            }

            uiComponent_->drawScore(score_);
        }
        else if (gameOver_) {
            uiComponent_->drawGameOverScreen();
        }
        else {
            uiComponent_->drawStartScreen();
        }
        

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

void Game::gameOver() {
    delete player_;
    player_ = nullptr;
    
    delete apple_;
    apple_ = nullptr;
    
    score_ = 0;
    
    initializeLevel();
}
