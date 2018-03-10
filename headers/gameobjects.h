#ifndef _GAMEOBJECTS_H_
#define _GAMEOBJECTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

enum piecetype{SWORD_TYPE, SHIELD_TYPE, POTION_TYPE, WALL_TYPE, PLAYER_TYPE, MONSTER_TYPE, DOOR_TYPE};
enum direction{MVUP, MVDOWN, MVLEFT, MVRIGHT};


struct Item{
    int val;
};

struct Player{
    int health;
    struct Item sword;
    struct Item shield;
};

struct gamepiece{
    char name[50];
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
enum piecetype get_piece_type(gamepiece *piece);

Item * get_player_sword(gamepiece * piece);
Item * get_player_shield(gamepiece * piece);


int attack(gamepiece *attaker, gamepiece *defender);

#endif
