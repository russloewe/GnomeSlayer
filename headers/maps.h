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



room * get_current_room();   //return pointer to current room

int set_current_room(room * curroom);

int load_next_room();       //copy player from current room to next room, then point current_room pointer to next room

gamepiece * get_player();   // copy pointer to player struct from current room and return it

gamepiece * get_item(int x, int y); // return item located at (x,y), null if empty

gamepiece * get_adjacent_item(enum direction dir); //get adjacent item in "dir" direction

gamepiece * swap_item(gamepiece * in_item, int x, int y); //pop item from coord (x,y) and return, replace with in item. if no item return in_item

#endif
