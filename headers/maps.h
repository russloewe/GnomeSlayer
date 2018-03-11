#ifndef _MAPS_H_
#define _MAPS_H_

#include <stdio.h>
#include "gameobjects.h"
#include "graphics.h"


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

int pickup_item();          // swap item on ground with item in player inventory 

gamepiece * grab_item_reference(int x, int y); //like pickup item, but leaves it on ground

gamepiece * get_adjacent_item(enum direction dir); //get adjacent item in "dir" direction

int remove_item_from_map(gamepiece * item);

int add_item_to_map(gamepiece * item);

#endif
