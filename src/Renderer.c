#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "Renderer.h"
#include "Globals.h"
#include "Init.h"
#include "GameState.h"
#include "GameLogic.h"
#include "Utils.h"

void renderGame(GameState **gameState)
{
    initBoard(gameState);

    // Switch statement for all game scenes/screens
    while ((*gameState)->currentScene != QUIT_SCENE)
    {

        switch ((*gameState)->currentScene)
        {
        case INPUT_SCENE:
        {
            renderScene(inputScene, gameState);
            break;
        }
        case GAME_SCENE:
        {
            renderScene(gameScene, gameState);
            break;
        }
        case QUIT_SCENE:
        {
            return;
        }
        default:
            break;
        }
    }
}

void renderScene(scenePointer scene_func, GameState **gameState)
{
    int responseFromScene = 0;
    while (responseFromScene == 0)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        responseFromScene = scene_func(gameState);

        if (WindowShouldClose())
        {
            (*gameState)->currentScene = QUIT_SCENE;
            break;
        }

        EndDrawing();
    }
}

int inputScene(GameState **gameState)
{
    int posX = SCREEN_WIDTH / 7;
    int posY = SCREEN_HEIGHT / 3;

    char *inputRow = (*gameState)->inputRow;
    int *inputRowSize = &((*gameState)->inputRowSize);

    char *inputCol = (*gameState)->inputCol;
    int *inputColSize = &((*gameState)->inputColSize);

    int key = GetKeyPressed();

    if (key != 0)
    {
        if (isNumeric((char)key))
        {
            if (*inputRowSize < MAX_INPUT_CHARS &&
                *inputColSize == 0)
            {
                inputRow[*inputRowSize] = (char)key;
                (*inputRowSize)++;
            }
            else if (*inputColSize < MAX_INPUT_CHARS)
            {
                printf("Hello");
                inputCol[*inputColSize] = (char)key;
                (*inputColSize)++;
            }
        }
        else if (key == KEY_BACKSPACE)
        {
            if (*inputColSize > 0)
            {
                (*inputColSize)--;
                inputCol[*inputColSize] = '\0';
            }
            else if (*inputRowSize > 0)
            {
                (*inputRowSize)--;
                inputRow[*inputRowSize] = '\0';
            }
        }
        else if (key == KEY_ENTER || key == KEY_KP_ENTER)
        {
            if (atoi(inputRow) < 50 && atoi(inputCol) < 50)
            {
                (*gameState)->currentScene = GAME_SCENE;
                return -1;
            }
        }
    }

    if (atoi(inputRow) >= 50 && atoi(inputCol) >= 50)
    {
        DrawText("Row and column must be less than 50!", posX * 1.8, posY * 2.3, 12, RED);
    }

    DrawText("Input Size of Board", posX, posY, 32, BLACK);
    DrawText(inputRow, posX * 2, posY * 2, 32, BLACK);
    DrawText(inputCol, posX * 4, posY * 2, 32, BLACK);

    return 0;
}

int gameScene(GameState **gameState)
{
    renderBoard(gameState);

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        flagCurrentCell(gameState);
    }

    return 0;
}

void renderBoard(GameState **gameState)
{
    int numRows = (*gameState)->numRows;
    int numCols = (*gameState)->numCols;
    int cellWidth = SCREEN_WIDTH / (*gameState)->numRows;
    int cellHeight = SCREEN_HEIGHT / (*gameState)->numCols;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Color lineColor = (*gameState)->board[i][j].lineColor;
            Color fillColor = (*gameState)->board[i][j].fillColor;
            Rectangle rec = {j * cellWidth, i * cellHeight, cellWidth, cellHeight};

            // Draw the filled rectangle with fill color
            DrawRectangle(rec.x, rec.y, rec.width, rec.height, fillColor);
            // Draw rectangle lines with line color
            DrawRectangleLinesEx(rec, 0.6f, lineColor);
        }
    }
}
