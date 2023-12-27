#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "Globals.h"
#include "Init.h"

int initBoard(Board **board)
{
    if (*board == NULL)
    {
        *board = (Board *)malloc(1 * sizeof(Board));

        if (*board == NULL)
        {
            fprintf(stderr, "Failed to allocate memory for board.\n");
            return EXIT_FAILURE;
        }

        (*board)->numRows = 10;
        (*board)->numCols = 10;
        (*board)->cellWidth = 40;
        (*board)->cellHeight = 40;

        for (int i = 0; i < (*board)->numRows; i++)
        {
            for (size_t j = 0; j < (*board)->numCols; j++)
            {
                Cell cell = {
                    .x = j * (*board)->cellWidth,
                    .y = i * (*board)->cellHeight,
                    DEFAULT_LINE_COLOR,
                    DEFAULT_FILL_COLOR};
                (*board)->board[i][j] = cell;
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