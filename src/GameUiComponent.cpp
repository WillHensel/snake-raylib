//
// Created by will on 1/10/2025.
//

#include <string>
#include "GameUiComponent.h"
#include "raylib.h"
#include "GameInfo.h"

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