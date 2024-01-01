#ifndef MINESWEEPER_GAMESTATE_H
#define MINESWEEPER_GAMESTATE_H

#include <stdio.h>

#include "Globals.h"
#include "Cell.h"

typedef struct GameState
{
    int currentScene;
    Cell board[MAX_ROWS][MAX_COLS];
    int cellWidth;
    int cellHeight;
    int user_board_size;
    int user_mine_count;
} GameState;

enum GameScenes
{
    INPUT_SCENE = 0,
    GAME_SCENE,
    QUIT_SCENE
};

enum SCENE_RESPONSE {
    SCENE_FAIL = -1,
    SCENE_OK = 0,
    SCENE_ 
};

#endif // MINESWEEPER_GAMESTATE_H
