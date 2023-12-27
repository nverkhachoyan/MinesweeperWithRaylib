#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

#include "GameState.h"

typedef int (*scenePointer)(GameState **gameState);

void renderGame(GameState **gameState);
void renderBoard(GameState **gameState);

// Renders scenes (callback functions)
void renderScene(scenePointer scene, GameState **gameState);

// Scenes
int inputScene(GameState **gameState);
int gameScene(GameState **gameState);

#endif // MINESWEEPER_RENDERER_H