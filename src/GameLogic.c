#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "Globals.h"
#include "GameLogic.h"
#include "Cell.h"
#include "Board.h"
#include "Init.h"
#include "Cleanup.h"
#include "GameState.h"
#include "Utils.h"
#include "Renderer.h"

void run()
{
    char inputText[MAX_INPUT_CHARS + 1] = "\0";
    int textSize = 0;
    Board *board = NULL;
    GameState gameState = {INPUT_SCENE};

    initBoard(&board);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (gameState.currentScene)
        {
        case INPUT_SCENE:

            drawInputScene(inputText, &textSize);
            break;
        case GAME_SCENE:
            drawGameScene(&board);
        default:
            break;
        }

        EndDrawing();
    }

    Cleanup(board);
}

void drawInputScene(char inputText[], int *textSize)
{
    int posX = SCREEN_WIDTH / 7;
    int posY = SCREEN_HEIGHT / 3;

    int key = GetKeyPressed();

    if (key != 0)
    {
        if (isNumeric((char)key) && *textSize < MAX_INPUT_CHARS)
        {
            inputText[*textSize] = (char)key;
            (*textSize)++;
        }
        else if (key == KEY_BACKSPACE)
        {
            if (*textSize > 0)
            {
                (*textSize)--;
                inputText[*textSize] = '\0';
            }
        }
    }

    DrawText("Input Size of Board", posX, posY, 32, BLACK);
    DrawText(inputText, posX * 2, posY * 2, 32, BLACK);
}

void drawGameScene(Board **board)
{
    drawBoard(board);

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        rightClick(board);
    }
}

void rightClick(Board **board)
{
    Vector2 mousePos = GetMousePosition();
    int numRows = (*board)->numRows;
    int numCols = (*board)->numCols;

    int xIndex = mousePos.x / (SCREEN_WIDTH / numRows);
    int yIndex = mousePos.y / (SCREEN_HEIGHT / numCols);

    (*board)->board[yIndex][xIndex].fillColor = FLAGGED_FILL_COLOR;

    printf("POSITION: X = %d, Y = %d\n", xIndex, yIndex);
}