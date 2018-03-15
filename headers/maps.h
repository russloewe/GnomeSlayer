#ifndef _MAPS_H_
#define _MAPS_H_

#include <stdio.h>
#include "gameobjects.h"
#include <stdlib.h>

//prototype for two functions that are needed here, but can't include te whole header

int get_max_x();
int get_max_y();

struct room{
    char name[50];
    gamepiece * monsters[10];
    gamepiece * bounty[10];
    gamepiece * walls[300];
    gamepiece * doors[2];
};



typedef struct room room;


/**************INIT************************/

room * create_room(void); //RK: Adding prototype for create_room

int init_monster_iter(); //Set monster index to begining of monster array

int create_map();   //generate some rooms and add them to the map

/*****************GETTERS*******************/

room * get_current_room();   //return pointer to current room

int load_next_room();       //copy player from current room to next room, then point current_room pointer to next room

gamepiece * get_player();   // copy pointer to player struct from current room and return it

gamepiece * grab_item_reference(int x, int y); //like pickup item, but leaves it on ground

gamepiece * get_adjacent_item(gamepiece * ref_piece, enum direction dir); //get adjacent item in "dir" direction

int remove_item_from_current_room(gamepiece * item);       //remove item pointer from bounty array, compares x,y coords to find item in list

gamepiece * monster_iter();  //returns a new monster on each call

int random_x();   //return a x coord that is in the map boundry

int random_y();   //return a y coord that is in the map boundry

/**************SETTERS************************/

int set_current_room(room * curroom);

int load_next_room();

int load_prev_room();

int add_item_to_current_room(gamepiece * item);             //look for empty slot for item

int add_monster_to_current_room(gamepiece * monster);      //look for empty slot for monster

int add_player_to_current_room(gamepiece * player);        //look for empty slot for player

int add_wall_to_current_room(gamepiece * wall);             //look for empty slot for walls


#endif
