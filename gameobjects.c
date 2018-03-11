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
    //need to auto add image to this function, remove imge input
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

int set_piece_health(gamepiece* player, int a){
    if(a <= 100){
        player->player.health = a;
    }
    if(a > 100){
        player->player.health = 100;
    }
    return 0;
}

gamepiece * get_player_sword(gamepiece * piece){
    //return gamepieces sword
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){ //only for action character
         gamepiece * item_piece ;
         
         //copy x,y coords from player
         int x = get_piece_x(piece);
         int y = get_piece_y(piece);
         item_piece = create_piece(x, y, NULL, SWORD_TYPE); //create new gameobject
         if(item_piece == NULL){return NULL;}
        
         item_piece->item.val = piece->player.sword.val;  //copy sword's val to new objects
         strncpy(item_piece->item.name, piece->player.sword.name, 25); //copy sword name
         
        return item_piece;
    }else{
        return NULL;
    }
}

gamepiece * get_player_shield(gamepiece * piece){
    //return gamepieces shield
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){ //only for action character
         gamepiece * item_piece ;
         //get x,y coords
         int x = get_piece_x(piece);
         int y = get_piece_y(piece);
         
         item_piece = create_piece(x, y, NULL, SHIELD_TYPE); //create new gameobject
         if(item_piece == NULL){return NULL;}
         
         item_piece->item.val = piece->player.shield.val;  //copy shield value to new object
         strncpy(item_piece->item.name, piece->player.shield.name, 25); //copy name
         
        return item_piece;
    }else{
        return NULL;
    }
}

int get_item_val(gamepiece * item){
    if(item == NULL){
        return 0;
    }
    if( (get_piece_type(item) == SWORD_TYPE) ||
        (get_piece_type(item) == SHIELD_TYPE) ||
        (get_piece_type(item) == POTION_TYPE) ){
            return item->item.val;
    }else{
        return 0;
    }
}
    
gamepiece * equip_item_to_player(gamepiece * player, gamepiece * item){
    //take an item and add it to player stuct 
    if(item == NULL){
        return NULL;
    }
    
    if(get_piece_type(item) == SWORD_TYPE){
        gamepiece * new_sword;        
        new_sword = get_player_sword(player);
        player->player.sword.val = item->item.val;
        return new_sword;
    }
    if(get_piece_type(item) == SHIELD_TYPE){
        gamepiece * new_shield;        
        new_shield = get_player_shield(player);
        player->player.shield.val = item->item.val;
        return new_shield;
    }
    if(get_piece_type(item) == POTION_TYPE){
        int cur_health = get_piece_health(player);
        int potion_val = get_item_val(item);
        set_piece_health(player, cur_health + potion_val);
        return NULL;
    }else{
        return NULL;
    }
}        
     

int attack(gamepiece *attaker, gamepiece *defender){


}
