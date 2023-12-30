#include "GameScene.h"
#include "GameLogic.h"

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