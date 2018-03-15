#ifndef _CHECKER_H_
#define _CHECKER_H_


#include <stdio.h>
#include <stdlib.h>
#include "gameobjects.h"
#include "maps.h"

int player_on_door();
int player_on_item();
int is_player_dead(gamepiece *piece);
int check_for_dead_monsters();
direction is_player_near(gamepiece * monster, int i);

#endif
