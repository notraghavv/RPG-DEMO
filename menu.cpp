#include "menu.h"

void Menu::Update(int &gameState) {

    // MAIN MENU
    if (currentState == MAIN_MENU) {

        if (IsKeyPressed(KEY_DOWN)) selectedOption++;
        if (IsKeyPressed(KEY_UP)) selectedOption--;

        if (selectedOption < 0) selectedOption = 3;
        if (selectedOption > 3) selectedOption = 0;

        if (IsKeyPressed(KEY_ENTER)) {
            switch (selectedOption) {
                case 0: currentState = PLAYER_SELECT; break;
                case 1: currentState = CONTROLS; break;
                case 2: currentState = SETTINGS; break;
                case 3: currentState = CREDITS; break;
            }
        }
    }

    // PLAYER SELECT
    else if (currentState == PLAYER_SELECT) {

        if (IsKeyPressed(KEY_RIGHT)) selectedPlayer++;
        if (IsKeyPressed(KEY_LEFT)) selectedPlayer--;

        if (selectedPlayer < 0) selectedPlayer = 4;
        if (selectedPlayer > 4) selectedPlayer = 0;

        if (IsKeyPressed(KEY_ENTER)) {
            gameState = 1; // start game
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            currentState = MAIN_MENU;
        }
    }

    // OTHER SCREENS
    else if (currentState == CONTROLS ||
             currentState == SETTINGS ||
             currentState == CREDITS) {

        if (IsKeyPressed(KEY_BACKSPACE)) {
            currentState = MAIN_MENU;
        }
    }
}

void Menu::Draw() {

    if (currentState == MAIN_MENU) {

        const char* options[4] = {
            "Play",
            "Controls",
            "Settings",
            "Credits"
        };

        for (int i = 0; i < 4; i++) {
            Color color = (i == selectedOption) ? YELLOW : WHITE;
            DrawText(options[i], 350, 200 + i * 40, 20, color);
        }
    }

    else if (currentState == PLAYER_SELECT) {

        DrawText("Select Player", 320, 100, 30, WHITE);

        for (int i = 0; i < 5; i++) {
            Color color = (i == selectedPlayer) ? GREEN : GRAY;
            DrawCircle(200 + i * 100, 300, 30, color);
        }

        DrawText("ENTER to Start", 300, 400, 20, WHITE);
        DrawText("BACKSPACE to go back", 250, 450, 20, GRAY);
    }

    else if (currentState == CONTROLS) {
        DrawText("WASD to move, SPACE to attack", 200, 300, 20, WHITE);
    }

    else if (currentState == SETTINGS) {
        DrawText("Settings (placeholder)", 300, 300, 20, WHITE);
    }

    else if (currentState == CREDITS) {
        DrawText("Made by YOU 😎", 300, 300, 20, WHITE);
    }
}