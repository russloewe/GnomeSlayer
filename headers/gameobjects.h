#ifndef _GAMEOBJECTS_H_
#define _GAMEOBJECTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

enum piecetype{SWORD_TYPE, SHIELD_TYPE, POTION_TYPE, WALL_TYPE, PLAYER_TYPE, MONSTER_TYPE, DOOR_TYPE};
enum direction{MVUP, MVDOWN, MVLEFT, MVRIGHT};


struct gamepiece{
    char name[25];
    int x;
    int y;
    int val;
    SDL_Texture * img;
    enum piecetype type;
    struct gamepiece * shield;
    struct gamepiece * sword;
};


typedef struct gamepiece gamepiece;
typedef enum piecetype piecetype;

//create and destroy objects
gamepiece * create_piece(int x, int y, SDL_Texture * img, piecetype type);
int destroy_piece(gamepiece * piece);

//getters
int get_piece_x(gamepiece *piece);
int get_piece_y(gamepiece *piece);
int get_piece_val(gamepiece *piece);
char * get_piece_name(gamepiece * piece);

gamepiece * get_player_sword(gamepiece * piece);
gamepiece * get_player_shield(gamepiece * piece);
SDL_Texture * get_piece_image(gamepiece *p);
piecetype get_piece_type(gamepiece *piece);


//setters
int set_piece_x(gamepiece * piece, int x);
int set_piece_y(gamepiece * piece, int y);
int set_piece_val(gamepiece* player, int a);
int set_player_health(gamepiece* player, int a);
int set_piece_name(gamepiece * piece, char * string);
gamepiece * equip_item_to_player(gamepiece * player, gamepiece * item);

//actions
int move_piece(gamepiece * piece, enum direction direc);



int attack(gamepiece *attaker, gamepiece *defender);

#endif
