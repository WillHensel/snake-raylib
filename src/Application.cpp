//
// Created by will on 1/9/2025.
//

#include "Application.h"

Application::Application() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(windowSize_.x, windowSize_.y, "Snake");
    SetTargetFPS(2);
    
    game_ = new Game{};
}

Application::~Application() {
    delete game_;
    CloseWindow();
}

Vector2 Application::getWindowSize() {
    return windowSize_;
}

void Application::startGame() {
    game_->gameLoop();
}