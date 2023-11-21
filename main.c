#include "cgame/game.h"
#include "clib/logger.h"

int main(void) {
    LOG_DEBUG("Hello world!");

    return game_create();
} 
