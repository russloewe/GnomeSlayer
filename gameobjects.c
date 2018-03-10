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
       // printf("Error: gameobjects.c->creat_piece()-> img is NULL\n");
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
enum piecetype get_piece_type(gamepiece *piece){
    //super quick dirty function
        return piece->type;
}

int get_piece_health(gamepiece * piece){
    if(piece == NULL){
        return -1;
    }else{
        if( (get_piece_type(piece) == PLAYER_TYPE) || 
            (get_piece_type(piece) == MONSTER_TYPE)){
            return piece->player.health;
        }else{
            return -1;
        }
    }
}

Item * get_player_sword(gamepiece * piece){
    //return gamepieces shield
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){
        return &(piece->player.sword);
    }else{
        return NULL;
    }
}

Item * get_player_shield(gamepiece * piece){
    //return gamepieces shield
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){
        return &(piece->player.shield);
    }else{
        return NULL;
    }
}
        

int attack(gamepiece *attaker, gamepiece *defender){


}
