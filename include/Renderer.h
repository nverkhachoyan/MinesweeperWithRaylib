#ifndef MINESWEEPER_RENDERER_H
#define MINESWEEPER_RENDERER_H

#include "GameState.h"

void renderGame(GameState **gameState, char inputText[MAX_INPUT_CHARS + 1], int *inputTextSize);
void renderBoard(GameState **gameState);
void renderInputScene(char inputText[], int *textSize);

#endif // MINESWEEPER_RENDERER_H