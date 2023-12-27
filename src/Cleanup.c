#include <stdlib.h>

#include "Cleanup.h"

void Cleanup(Board *board)
{
    free(board);
}