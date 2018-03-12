/*************************************************************
Author: Rebecca Kennedy
Date: 3/7/18
Filename: maps.c
This is the room module for the final project in CS133u.
***************************************************************/

#include "./headers/maps.h"

/*
struct room create_room(void) {
    room room1 = {.walls = {NULL}}; //init walls array to null pointers
    //make some walls
        for(int i = 1; i < 11; i++){
        gamepiece * wall = create_piece(5, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i-1] = wall;
        }
        //spawn some monsters
        gamepiece * monst;
        for(int i = 0; i<5; i++){
        monst = create_piece(rand()%10+8, rand()%10+8, load_image("./img/player.bmp"), MONSTER_TYPE);
        room1.monsters[i] =monst;

    return room1;
    }
*/

struct room create_room(void) {

    struct room room1;

    room1 = {.walls = {NULL}}; //init walls array to null pointers

    //make some walls
        for(int i = 1; i < 11; i++){
        gamepiece * wall = create_piece(5, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i-1] = wall;
        }
        //spawn some monsters
        gamepiece * monst;
        for(int i = 0; i<5; i++){
        monst = create_piece(rand()%10+8, rand()%10+8, load_image("./img/player.bmp"), MONSTER_TYPE);
        room1.monsters[i] =monst;








    /*    gamepiece * wall = create_piece(5, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i-1] = wall;

        gamepiece * monst;
        monst = create_piece(rand()%10+8, rand()%10+8, load_image("./img/player.bmp"), MONSTER_TYPE);
        room1.monsters[0] =monst;
*/
         

        return room1;
}
