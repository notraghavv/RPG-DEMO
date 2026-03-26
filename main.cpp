#include "raylib.h"
#include "game.h"

int main() {

    InitWindow(800, 600, "RPG Demo");

    Game game;

    while (!WindowShouldClose()) {

        game.Update();

        BeginDrawing();
        ClearBackground(BLACK);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}