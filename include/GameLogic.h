#ifndef MINESWEEPER_GAMELOGIC_H
#define MINESWEEPER_GAMELOGIC_H

#include "GameState.h"

void run();
void drawBoard(GameState **gameState);
void flagCell(GameState **gameState);
void drawInputScene(char inputText[], int *textSize);
void drawGameScene(GameState **gameState);

#endif // MINESWEEPER_GAMELOGIC_H