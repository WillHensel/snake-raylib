#include "raylib.h"

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(1280, 800, "Hello Raylib");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        float gameAreaSize = 500.0f;
        float gameAreaOffsetX = (float)GetRenderWidth() / 2.0f - gameAreaSize / 2.0f;
        float gameAreaOffsetY = (float)GetRenderHeight() / 2.0f - gameAreaSize / 2.0f;

        float cellSize = gameAreaSize / 20;

        Rectangle outlineRect{
            .x =  gameAreaOffsetX,
            .y =  gameAreaOffsetY,
            .width =  gameAreaSize,
            .height =  gameAreaSize};
        DrawRectangleRoundedLinesEx(outlineRect, 0.025, 3, 4, LIGHTGRAY);

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                Rectangle cellRect{
                        .x = (float)i * cellSize + gameAreaOffsetX,
                        .y = (float)j * cellSize + gameAreaOffsetY,
                        .width = cellSize,
                        .height = cellSize
                };
                DrawRectangleRounded(cellRect, 0.2, 3, LIGHTGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
