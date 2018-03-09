#ifndef _MAPS_H_
#define _MAPS_H_

#include <stdio.h>
#include "gameobjects.h"


struct room{
    char name[50];
    gamepiece * monsters[5];
    gamepiece * bounty[5];
    gamepiece * walls[200];
    gamepiece * doors[2];
};



typedef struct room room;


#endif
