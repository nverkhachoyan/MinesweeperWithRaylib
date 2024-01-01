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
    GameState *gameState = NULL;

    renderGame(&gameState);
    cleanup(&gameState);
}

void flagCurrentCell(GameState **gameState)
{
    Vector2 mousePos = GetMousePosition();
    int board_size = (*gameState)->user_board_size;

    int xIndex = mousePos.x / (SCREEN_WIDTH / board_size);
    int yIndex = mousePos.y / (SCREEN_HEIGHT / board_size);

    (*gameState)->board[yIndex][xIndex].fillColor = FLAGGED_FILL_COLOR;

    printf("POSITION: X = %d, Y = %d\n", xIndex, yIndex);
}
