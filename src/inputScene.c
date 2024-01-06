#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "InputScene.h"

#include "raylib.h"
#include "Globals.h"
#include "GameState.h"
#include "GameLogic.h"
#include "Utils.h"

// Used as positions for drawing text
int posX = SCREEN_WIDTH / 7;
int posY = SCREEN_HEIGHT / 3;

#define MAX_INPUT_LEN 2

// Stores input for board and mine count
char board_size_input[MAX_INPUT_LEN + 1] = {'\0'};
char mine_count_input[MAX_INPUT_LEN + 1] = {'\0'};
int board_size_input_len = 0;
int mine_count_input_len = 0;
bool failValidation = false;

void inputScene(GameState **gameState)
{
    // Get a key press
    int key = GetKeyPressed();

    // If key != 0 then a key is pressed
    if (key != 0)
    {
        if (isNumeric((char)key))
        {
            handle_numeric_input(key);
        }
        else if (key == KEY_BACKSPACE)
        {
            handle_backspace_input(key);
        }
        else if (key == KEY_ENTER || key == KEY_KP_ENTER)
        {
            if (handle_enter_input(gameState, board_size_input, mine_count_input, key) == 0)
            {
                return;
            }
        }
    }

    draw_UI();
}

void handle_numeric_input(int key)
{
    if (board_size_input_len < MAX_INPUT_LEN && mine_count_input_len == 0)
    {
        board_size_input[board_size_input_len] = (char)key;
        board_size_input_len++;
        board_size_input[board_size_input_len] = '\0';
    }
    else if (mine_count_input_len < MAX_INPUT_LEN)
    {
        mine_count_input[mine_count_input_len] = (char)key;
        mine_count_input_len++;
        mine_count_input[mine_count_input_len] = '\0';
    }
}

void handle_backspace_input(int key)
{
    if (mine_count_input_len > 0)
    {
        (mine_count_input_len)--;
        mine_count_input[mine_count_input_len] = '\0';
    }
    else if (board_size_input_len > 0)
    {
        board_size_input_len--;
        board_size_input[board_size_input_len] = '\0';
    }
}

int handle_enter_input(GameState **game_state, char *board_input, char *mine_input, int key)
{
    if (validate_input(board_input, mine_input) == 0)
    {
        (*game_state)->user_board_size = atoi(board_size_input);
        (*game_state)->user_mine_count = atoi(mine_count_input);
        (*game_state)->currentScene = GAME_SCENE;
        return 0;
    }

    return -1;
}

int validate_input(char *board_size, char *mine_count)
{
    if (atoi(board_size_input) <= 50 || atoi(mine_count_input) <= 25)
    {
        return 0;
    }

    failValidation = true;
    return -1;
}

void draw_UI()
{
    // Ask for input, print inputs
    DrawText("Input Size of Board", posX, posY * 0.7, 32, BLACK);
    DrawText("Then Press \"Enter\"", posX * 2.2, posY, 16, BLACK);

    // Ask and draw board size
    DrawText("Board Size",
             posX * 2.3,
             posY * 1.5,
             32,
             PURPLE);
    DrawText(board_size_input,
             posX * 3.1,
             posY * 1.75,
             32,
             BLACK);

    // Ask and draw number of mines
    DrawText("# Mines",
             posX * 2.3,
             posY * 2.0,
             32,
             PURPLE);
    DrawText(mine_count_input,
             posX * 3.1,
             posY * 2.2,
             32,
             BLACK);

    if (failValidation)
    {
        DrawText("Row and column must be less than 50!", posX * 0.5, posY * 2.5, 20, RED);
    }
}
