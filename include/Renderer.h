#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

#include "GameState.h"

typedef int (*scenePointer)(GameState **gameState);

void renderGame(GameState **gameState, char inputText[MAX_INPUT_CHARS + 1], int *inputTextSize);
void renderBoard(GameState **gameState);
void renderInputScene(GameState **gameState, char inputText[], int *textSize);
void renderFlagSelectedCell(GameState **gameState);
void renderScene(scenePointer scene, GameState **gameState);

// Scenes
int inputScene(GameState **gameState);
int gameScene(GameState **gameState);

#endif // MINESWEEPER_RENDERER_H