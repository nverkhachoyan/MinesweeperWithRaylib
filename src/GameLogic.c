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

void drawBoard(Board **board)
{
    int numRows = (*board)->numRows;
    int numCols = (*board)->numCols;
    int cellWidth = SCREEN_WIDTH / (*board)->numRows;
    int cellHeight = SCREEN_HEIGHT / (*board)->numCols;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Color lineColor = (*board)->board[i][j].lineColor;
            Color fillColor = (*board)->board[i][j].fillColor;
            Rectangle rec = {j * cellWidth, i * cellHeight, cellWidth, cellHeight};

            // Draw the filled rectangle with fill color
            DrawRectangle(rec.x, rec.y, rec.width, rec.height, fillColor);
            // Draw rectangle lines with line color
            DrawRectangleLinesEx(rec, 0.6f, lineColor);
        }
    }
}