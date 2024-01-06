#ifndef MINESWEEPER_INPUT_SCENE_H
#define MINESWEEPER_INPUT_SCENE_H

#include "GameState.h"

void inputScene(GameState **gameState);
void handle_numeric_input(int key);
void handle_backspace_input(int key);
int handle_enter_input(GameState **game_state, char *board_input, char *mine_input, int key);
int validate_input(char *board_size, char *mine_count);
void draw_UI();

#endif // MINESWEEPER_INPUT_SCENE_H
