#include "game.h"
#include "raylib.h"

void Game::Update() {

    // MENU STATE
    if (gameState == 0) {
        menu.Update(gameState);
    }

    // GAMEPLAY STATE
    else if (gameState == 1) {
        // For now just placeholder
        // Later: player, enemies, waves etc.
    }
}

void Game::Draw() {

    // MENU
    if (gameState == 0) {
        menu.Draw();
    }

    // GAMEPLAY
    else if (gameState == 1) {
        DrawText("GAME STARTED", 300, 300, 20, WHITE);
    }
}