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
    }
    gamepiece * newpiece = (gamepiece *)malloc(sizeof(gamepiece));

    newpiece->x = x;
    newpiece->y = y;
    newpiece->type = type;
    newpiece->img = img;
    
    return newpiece;
}

int destroy_piece(gamepiece * piece){
    SDL_DestroyTexture(piece->img);
    free(piece);
    return 0;
}
 
int move_piece(gamepiece * piece, enum direction direc){
    switch(direc){
        case MVUP:
            (piece->y) -= 1;
            break;
        case MVDOWN:
            (piece->y) += 1;
            break;
        case MVLEFT:
            (piece->x) -= 1;
            break;
        case MVRIGHT:
            (piece->x) += 1;
            break;
            
        }
    return 0;
}

SDL_Texture * get_piece_image(gamepiece *p){
    SDL_Texture * image;
    
    image = p->img;
    
    return image;
}

int get_piece_x(gamepiece *piece){

    //interface to return a game piece's x position.
    int a = piece->x;

    return a;
}

int get_piece_y(gamepiece *piece){
    //interface to get gamepiece y coordinate
    int y = piece->y;
    return y;
}

int attack(gamepiece *attaker, gamepiece *defender){


}
