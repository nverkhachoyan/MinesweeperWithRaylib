#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "Globals.h"
#include "Cell.h"
#include "Init.h"

int initBoard(GameState **gameState)
{
    if (*gameState == NULL)
    {
        *gameState = (GameState *)malloc(sizeof(GameState));

        if (*gameState == NULL)
        {
            fprintf(stderr, "Failed to allocate memory for board.\n");
            return EXIT_FAILURE;
        }

        (*gameState)->cellWidth = 40;
        (*gameState)->cellHeight = 40;

        // Using MAX_BOARD_SIZE for both rows and cols to have a square board
        for (int i = 0; i < MAX_BOARD_SIZE; i++)
        {
            for (size_t j = 0; j < MAX_BOARD_SIZE; j++)
            {
                Cell cell = {
                    .x = j * (*gameState)->cellWidth,
                    .y = i * (*gameState)->cellHeight,
                    DEFAULT_LINE_COLOR,
                    DEFAULT_FILL_COLOR};
                (*gameState)->board[i][j] = cell;
            }
        }
    }
    else
    {
        printf("Failed to create board. Board already exists.\n");
        return 0;
    }

    return 0;
}