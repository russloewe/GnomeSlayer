#ifndef _MAPS_H_
#define _MAPS_H_

#include <stdio.h>
#include "gameobjects.h"

//RK: Adding prototype for create_room
//struct room create_room(void);

struct room{
    char name[50];
    gamepiece * monsters[5];
    gamepiece * bounty[5];
    gamepiece * walls[200];
    struct door * lastroom;
    struct door * nextroom;
};

struct door{
    struct room * room1;
    struct room * room2;
};

typedef struct room room;
typedef struct door door;

//RK: Adding prototype for create_room
struct room create_room(void);

#endif
