#include "raylib.h"
#include "Game.h"
#include "Application.h"

int main() {
    srand(time(NULL));
    Application application = Application{};
    application.startGame();
    return 0;
}
