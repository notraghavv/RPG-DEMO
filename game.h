#pragma once
#include "menu.h"

class Game {
public:
    int gameState = 0; // 0 = menu, 1 = gameplay

    Menu menu;

    void Update();
    void Draw();
};