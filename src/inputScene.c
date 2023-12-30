#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"
#include "Globals.h"
#include "GameState.h"
#include "GameLogic.h"
#include "Utils.h"

#include "inputScene.h"

// Stores input for rows and cols
char inputRow[MAX_INPUT_CHARS + 1] = {'\0'};
char inputCol[MAX_INPUT_CHARS + 1] = {'\0'};
int inputRowSize = 0;
int inputColSize = 0;

int inputScene(GameState **gameState)
{
    // Used as positions for drawing text
    int posX = SCREEN_WIDTH / 7;
    int posY = SCREEN_HEIGHT / 3;

    // Get a key press
    int key = GetKeyPressed();

    // If key != 0 then a key is pressed
    if (key != 0)
    {
        // If input is numeric, process and store them in appropriate variables
        if (isNumeric((char)key))
        {
            if (inputRowSize < MAX_INPUT_CHARS &&
                inputColSize == 0)
            {
                inputRow[inputRowSize] = (char)key;
                inputRowSize++;
                inputRow[inputRowSize] = '\0';
            }
            else if (inputColSize < MAX_INPUT_CHARS)
            {
                inputCol[inputColSize] = (char)key;
                inputColSize++;
                inputCol[inputColSize] = '\0';
            }
        }
        // If input is KEY_BACKSPACE, remove a char accordingly
        else if (key == KEY_BACKSPACE)
        {
            if (inputColSize > 0)
            {
                inputColSize--;
                inputCol[inputColSize] = '\0';
            }
            else if (inputRowSize > 0)
            {
                (inputRowSize)--;
                inputRow[inputRowSize] = '\0';
            }
        }
        // If input is enter or keypad enter, set row and col size for game state
        // And change current scene to GAME_SCENE
        else if (key == KEY_ENTER || key == KEY_KP_ENTER)
        {
            if (atoi(inputRow) < 50 && atoi(inputCol) < 50)
            {
                (*gameState)->numRows = atoi(inputRow);
                (*gameState)->numCols = atoi(inputCol);
                (*gameState)->currentScene = GAME_SCENE;
                return -1;
            }
        }
    }

    // If row or col size over 50, show notice
    if (atoi(inputRow) >= 50 || atoi(inputCol) >= 50)
    {
        DrawText("Row and column must be less than 50!", posX * 0.5, posY * 2.3, 20, RED);
    }

    // Ask for input, print inputs
    DrawText("Input Size of Board", posX, posY, 32, BLACK);

    DrawText("Rows", posX * 2, posY * 1.5, 32, PURPLE);
    DrawText(inputRow, posX * 2.2, posY * 1.7, 32, BLACK);

    DrawText("Cols", posX * 4, posY * 1.5, 32, PURPLE);
    DrawText(inputCol, posX * 4.2, posY * 1.7, 32, BLACK);

    return 0;
}