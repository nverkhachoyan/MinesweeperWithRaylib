#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

#include "GameState.h"

typedef int (*scene_func_ptr)(GameState **gameState);

void renderGame(GameState **gameState);
void renderBoard(GameState **gameState);

// Renders scenes (callback functions)
void renderScene(scene_func_ptr scene_func, GameState **gameState);

// Scenes
int inputScene(GameState **gameState);
int gameScene(GameState **gameState);

#endif // MINESWEEPER_RENDERER_H