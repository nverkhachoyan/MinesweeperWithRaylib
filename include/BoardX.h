#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include "Globals.h"
#include "Cell.h"

typedef struct Board
{
    Cell board[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
    int cellWidth;
    int cellHeight;
} Board;

#endif // MINESWEEPER_BOARD_H