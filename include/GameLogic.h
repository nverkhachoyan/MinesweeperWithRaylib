#ifndef MINESWEEPER_GAMELOGIC_H
#define MINESWEEPER_GAMELOGIC_H

#include "Board.h"

void run();
void drawBoard(Board **board);
void rightClick(Board **board);
void drawInputScene(char inputText[], int *textSize);
void drawGameScene(Board **board);

#endif // MINESWEEPER_GAMELOGIC_H