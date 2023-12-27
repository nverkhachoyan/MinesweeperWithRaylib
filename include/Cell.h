#ifndef MINESWEEPER_CELL_H
#define MINESWEEPER_CELL_H

#include "raylib.h"

typedef struct Cell
{
    int x;
    int y;
    Color lineColor;
    Color fillColor;
} Cell;

#endif // MINESWEEPER_CELL_H