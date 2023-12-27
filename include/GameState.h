#ifndef MINESWEEPER_GAMESTATE_H
#define MINESWEEPER_GAMESTATE_H

#include "Globals.h"
#include "Cell.h"

enum GameScenes
{
    INPUT_SCENE = 0,
    GAME_SCENE,
    QUIT_SCENE
};

typedef struct GameState
{
    int currentScene;
    Cell board[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
    int cellWidth;
    int cellHeight;
} GameState;

#endif // MINESWEEPER_GAMESTATE_H