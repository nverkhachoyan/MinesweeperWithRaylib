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

void drawGameScene(GameState **gameState)
{
    renderBoard(gameState);

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        flagCell(gameState);
    }
}

void flagCell(GameState **gameState)
{
    Vector2 mousePos = GetMousePosition();
    int numRows = (*gameState)->numRows;
    int numCols = (*gameState)->numCols;

    int xIndex = mousePos.x / (SCREEN_WIDTH / numRows);
    int yIndex = mousePos.y / (SCREEN_HEIGHT / numCols);

    (*gameState)->board[yIndex][xIndex].fillColor = FLAGGED_FILL_COLOR;

    printf("POSITION: X = %d, Y = %d\n", xIndex, yIndex);
}
