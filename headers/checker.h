#ifndef _CHECKER_H_
#define _CHECKER_H_


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "gameobjects.h"
#include "maps.h"
#include "checker.h"


int player_on_door();
gamepiece * player_on_item(room * curroom);
int is_player_dead(gamepiece *piece);

#endif
