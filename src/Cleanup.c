#include <stdlib.h>

#include "Cleanup.h"

void Cleanup(GameState **gameState)
{
    if (*gameState != NULL)
    {
        free(*gameState);
    }
}