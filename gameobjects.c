/*
 * file  : gameobjects.c
 * date  : 20 feb 2018
 * purpose:
 *       functions for manipulating objects in the game. Header file
 *       contains struct defs for the game objects used.
 */
 
#include "./headers/gameobjects.h"
#define GAMESQUARE 16

gamepiece * create_piece(int x, int y, SDL_Texture * img, enum piecetype type){
    
    if(img == NULL){
        printf("Error: gameobjects.c->creat_piece()-> img is NULL\n");
        return NULL;
    }
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

int destroy_piece(gamepiece * piece){
    free(piece->rect);
    SDL_DestroyTexture(piece->img);
    free(piece);
    return 0;
}
 
int move_piece(gamepiece * piece, enum direction direc){
    switch(direc){
        case MVUP:
            (piece->rect->y) -= GAMESQUARE;
            break;
        case MVDOWN:
            (piece->rect->y) += GAMESQUARE;
            break;
        case MVLEFT:
            (piece->rect->x) -= GAMESQUARE;
            break;
        case MVRIGHT:
            (piece->rect->x) += GAMESQUARE;
            break;
            
        }
    return 0;
}

SDL_Texture * get_piece_image(gamepiece *p){
    return NULL;
}

int get_piece_x(gamepiece *p){
    return 1;
}

int get_piece_y(gamepiece *p){
    return 1;
}
