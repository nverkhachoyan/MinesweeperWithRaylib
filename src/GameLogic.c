#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "Globals.h"
#include "GameLogic.h"
#include "Cell.h"
#include "Init.h"
#include "Cleanup.h"
#include "GameState.h"
#include "Utils.h"
#include "Renderer.h"

void run()
{
    char inputText[MAX_INPUT_CHARS + 1] = "\0";
    int textSize = 0;

    GameState *gameState = NULL;

    renderGame(&gameState, inputText, &textSize);

    Cleanup(&gameState);
}

void flagSelectedCell(GameState **gameState)
{
    renderFlagSelectedCell(gameState);
}
