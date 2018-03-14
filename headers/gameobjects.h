#ifndef _GAMEOBJECTS_H_
#define _GAMEOBJECTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "SDL2/SDL.h"

enum piecetype{SWORD_TYPE, SHIELD_TYPE, POTION_TYPE, WALL_TYPE, PLAYER_TYPE, MONSTER_TYPE, DOOR_TYPE, LAST_TYPE};
enum Icon{BACKGROUND_ICO, WALL_ICO,   DOOR_ICO,  
          SWORD_ICO_1,  SWORD_ICO_2,  SWORD_ICO_3, 
          SHIELD_ICO_1, SHIELD_ICO_2, SHIELD_ICO_3,  
          POTION_ICO_1, POTION_ICO_2, POTION_ICO_3,
          MONSTER_ICO_1, MONSTER_ICO_2, MONSTER_ICO_3,
          PLAYER_ICO_1, PLAYER_ICO_2, PLAYER_ICO_3, LAST_ICO };
          
enum direction{UP, DOWN, LEFT, RIGHT, NONE};


struct gamepiece{
    char name[15];
    int x;
    int y;
    int val;
    enum Icon icon;
    enum piecetype type;
    struct gamepiece * shield;
    struct gamepiece * sword;
};


typedef struct gamepiece gamepiece;
typedef enum piecetype piecetype;
typedef enum Icon Icon;
typedef enum direction direction;

//create and destroy objects
gamepiece * create_piece(int x, int y, char * name, int val, piecetype type);
int destroy_piece(gamepiece * piece);

//getters
int get_piece_x(gamepiece *piece);
int get_piece_y(gamepiece *piece);
int get_piece_val(gamepiece *piece);
char * get_piece_name(gamepiece * piece);

gamepiece * get_player_sword(gamepiece * piece);
gamepiece * get_player_shield(gamepiece * piece);
piecetype get_piece_type(gamepiece *piece);
Icon get_piece_icon(gamepiece *piece);


//setters
int set_piece_x(gamepiece * piece, int x);
int set_piece_y(gamepiece * piece, int y);
int set_piece_val(gamepiece* player, int a);
int set_player_health(gamepiece* player, int a);
int set_piece_name(gamepiece * piece, char * string);
int set_piece_icon(gamepiece * piece, Icon icon);
gamepiece * equip_item_to_player(gamepiece * player, gamepiece * item);

//actions
int move_piece(gamepiece * piece, enum direction direc);
int animate(gamepiece * player);


int attack(gamepiece *attacker, gamepiece *defender);

#endif
