#ifndef MINESWEEPER_GAMESTATE_H
#define MINESWEEPER_GAMESTATE_H

enum GameScenes
{
    INPUT_SCENE = 0,
    GAME_SCENE,
    QUIT_SCENE
};

typedef struct GameState
{
    int currentScene;
} GameState;

#endif // MINESWEEPER_GAMESTATE_H