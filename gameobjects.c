/*
 * file  : gameobjects.c
 * date  : 20 feb 2018
 * purpose:
 *       functions for manipulating objects in the game. Header file
 *       contains struct defs for the game objects used.
 */
 
#include "./headers/gameobjects.h"

gamepiece * create_piece(int x, int y, SDL_Surface * img, enum piecetype type){
    gamepiece * newpiece = (gamepiece *)malloc(sizeof(gamepiece));
    SDL_Rect  * newrect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    
    newrect->x = x;
    newrect->y = y;
    newrect->w = 16;
    newrect->h = 16;
    
    newpiece->rect = newrect;
    newpiece->type = type;
    newpiece->img = img;
    
    return newpiece;
}

int move_piece(gamepiece * piece, enum direction direc){
    switch(direc){
        case MVUP:
            (piece->rect->y)--;
            break;
        case MVDOWN:
            (piece->rect->y)++;
            break;
        case MVLEFT:
            (piece->rect->x)--;
            break;
        case MVRIGHT:
            (piece->rect->x)++;
            break;
            
        }
    return 0;
}
