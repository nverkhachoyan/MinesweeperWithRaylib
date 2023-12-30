#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "Renderer.h"
#include "Globals.h"
#include "Init.h"
#include "GameState.h"
#include "GameLogic.h"
#include "Utils.h"

// Scenes
#include "InputScene.h"
#include "GameScene.h"

void renderGame(GameState **gameState)
{
    initBoard(gameState);

    // Switch statement for all game scenes/screens
    while ((*gameState)->currentScene != QUIT_SCENE)
    {

        switch ((*gameState)->currentScene)
        {
        case INPUT_SCENE:
        {
            renderScene(inputScene, gameState);
            break;
        }
        case GAME_SCENE:
        {
            renderScene(gameScene, gameState);
            break;
        }
        case QUIT_SCENE:
        {
            return;
        }
        default:
            break;
        }
    }
}

void renderScene(scene_func_ptr scene_func, GameState **gameState)
{
    int responseFromScene = 0;
    while (responseFromScene == 0)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        responseFromScene = scene_func(gameState);

        if (WindowShouldClose())
        {
            (*gameState)->currentScene = QUIT_SCENE;
            break;
        }

        EndDrawing();
    }
}
