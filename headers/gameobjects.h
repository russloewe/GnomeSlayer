#ifndef _GAMEOBJECTS_H_
#define _GAMEOBJECTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

enum piecetype{SWORD_TYPE, SHIELD_TYPE, POTION_TYPE, WALL_TYPE, PLAYER_TYPE, MONSTER_TYPE, DOOR_TYPE};
enum direction{MVUP, MVDOWN, MVLEFT, MVRIGHT};


struct Item{
    char name[25];
    int val;
};

struct Player{
    char name[25];
    int health;
    struct Item sword;
    struct Item shield;
};

struct gamepiece{    
    int x;
    int y;
    SDL_Texture * img;
    enum piecetype type;
    union{
        struct Player player;
        struct Item item;
    };
};


typedef struct gamepiece gamepiece;
typedef struct Item Item;
typedef enum piecetype piecetype;

gamepiece * create_piece(int x, int y, SDL_Texture * img, enum piecetype type);
int move_piece(gamepiece * piece, enum direction direc);
int destroy_piece(gamepiece * piece);

SDL_Texture * get_piece_image(gamepiece *p);
int get_piece_x(gamepiece *piece);
int get_piece_y(gamepiece *piece);
int get_piece_health(gamepiece *piece);
int set_piece_health(gamepiece* player, int a);
enum piecetype get_piece_type(gamepiece *piece);
char * get_piece_name(gamepiece * piece);
int set_piece_name(gamepiece * piece, char * string);
int set_item_val(gamepiece * piece,int val);
gamepiece * get_player_sword(gamepiece * piece);
gamepiece * get_player_shield(gamepiece * piece);
gamepiece * equip_item_to_player(gamepiece * player, gamepiece * item);
int get_item_val(gamepiece * item);
int attack(gamepiece *attaker, gamepiece *defender);

#endif
