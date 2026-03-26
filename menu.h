#pragma once
#include "raylib.h"

enum MenuState {
    MAIN_MENU,
    PLAYER_SELECT,
    CONTROLS,
    SETTINGS,
    CREDITS
};

class Menu {
public:
    MenuState currentState = MAIN_MENU;

    int selectedOption = 0;
    int selectedPlayer = 0;

    void Update(int &gameState);
    void Draw();
};