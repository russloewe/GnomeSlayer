#ifndef _MAPS_H_
#define _MAPS_H_

#include <stdio.h>
#include "gameobjects.h"
#include "graphics.h"


struct room{
    char name[50];
    gamepiece * monsters[10];
    gamepiece * bounty[10];
    gamepiece * walls[300];
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

int remove_item_from_map(gamepiece * item);       //remove item pointer from bounty array, compares x,y coords to find item in list

int add_item_to_map(gamepiece * item);             //look for empty slot for item

int add_monster_to_map(gamepiece * monster);      //look for empty slot for monster

int add_player_to_map(gamepiece * player);        //look for empty slot for player

int add_wall_to_map(gamepiece * wall);             //look for empty slot for walls

#endif
