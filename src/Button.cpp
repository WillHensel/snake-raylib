//
// Created by will on 1/12/2025.
//

#include <iostream>
#include "Button.h"
#include "raylib.h"

void DrawButton(const char* text, float x, float y, float width, float height) {
    const int fontSize = 20;
    const int textWidth = MeasureText(text, fontSize);
    const int textHeight = 10;
    Rectangle btnBounds{x, y, width, height};
    DrawText(text, x + width / 2 - textWidth / 2, y + height / 2 - textHeight / 2, fontSize, RAYWHITE);

    DrawRectangleRoundedLines(btnBounds, 0.2, 10, RAYWHITE);
    
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(GetMousePosition(), btnBounds)) {
            std::cout << "Button clicked" << std::endl;
        }
    }
}
