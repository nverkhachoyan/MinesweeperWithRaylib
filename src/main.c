#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"

#include "Globals.h"
#include "GameLogic.h"

int main(int argc, char *argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My Counter");
    SetTargetFPS(60);

    run();

    CloseWindow();
    return 0;
}