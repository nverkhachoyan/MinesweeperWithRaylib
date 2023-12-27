#include <stdlib.h>

#include "Cleanup.h"

void cleanup(GameState **gameState)
{
    if (*gameState != NULL)
    {
        free(*gameState);
    }
}