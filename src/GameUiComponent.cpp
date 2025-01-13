//
// Created by will on 1/10/2025.
//

#include <string>
#include "GameUiComponent.h"
#include "raylib.h"
#include "GameInfo.h"
#include "Button.h"

void GameUiComponent::drawScore(int score) {
    const char* labelText = "score";
    
    std::string scoreString = std::to_string(score);
    const char* scoreText = scoreString.c_str();
    
    int labelFontSize = 30;
    int scoreFontSize = 50;
    
    int labelWidth = MeasureText(labelText, labelFontSize);
    int scoreWidth = MeasureText(scoreText, scoreFontSize);
            
    DrawText(labelText, GetRenderWidth() / 2 - labelWidth / 2, 20, labelFontSize, RAYWHITE);
    DrawText(scoreText, GetRenderWidth() / 2 - scoreWidth / 2, 55, scoreFontSize, RAYWHITE);
}

void GameUiComponent::drawStartScreen() {
    const int titleFontSize = 50;
    const char* titleText = "Snake";
    const int titleWidth = MeasureText(titleText, titleFontSize);
    
    DrawText(titleText, GetRenderWidth() / 2 - titleWidth / 2, GetRenderHeight() / 2 - 200, titleFontSize, RAYWHITE);
    
    const char* btnText = "Start game";
    DrawButton(btnText, GetRenderWidth() / 2.0f - 70, GetRenderHeight() / 2.0f, 140, 50);
}

void GameUiComponent::drawGameOverScreen() {
    
}