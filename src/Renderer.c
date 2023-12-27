#include "raylib.h"

#include "Renderer.h"
#include "Globals.h"
#include "Board.h"

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