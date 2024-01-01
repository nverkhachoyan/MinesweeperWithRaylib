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
    int user_board_size = (*gameState)->user_board_size;
    int user_mine_count = (*gameState)->user_mine_count;
    int cellWidth = SCREEN_WIDTH / MAX_BOARD_SIZE;
    int cellHeight = SCREEN_HEIGHT / MAX_BOARD_SIZE;

    for (int i = 0; i < user_board_size; i++)
    {
        for (int j = 0; j < user_board_size; j++)
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