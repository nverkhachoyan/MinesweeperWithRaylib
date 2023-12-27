#include "raylib.h"

#include "Renderer.h"
#include "Globals.h"
#include "Init.h"
#include "GameState.h"
#include "Utils.h"

void renderGame(GameState **gameState, char inputText[MAX_INPUT_CHARS + 1], int *inputTextSize)
{
    initBoard(gameState);
    // Game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Switch statement for all game scenes/screens
        switch ((*gameState)->currentScene)
        {
        case INPUT_SCENE:
            renderInputScene(inputText, inputTextSize);

            break;
        case GAME_SCENE:
            // renderGameScene(*gameState);
            break;
        default:
            break;
        }

        EndDrawing();
    }
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

void renderInputScene(char inputText[], int *textSize)
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
