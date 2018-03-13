/*
 * file  : gameobjects.c
 * date  : 20 feb 2018
 * purpose:
 *       functions for manipulating objects in the game. Header file
 *       contains struct defs for the game objects used.
 */
 
#include "./headers/gameobjects.h"


gamepiece * create_piece(int x, int y, char * name, int val, piecetype type){
//need to check alloc
    gamepiece * newpiece = (gamepiece *)malloc(sizeof(gamepiece));

    newpiece->x = x;
    newpiece->y = y;
    newpiece->val = val;
    newpiece->type = type;
    newpiece->sword = NULL; //init pointers to null
    newpiece->shield = NULL;    
    strncpy(newpiece->name, name, 15);
    
    //auto set icon
    switch(type){
        case PLAYER_TYPE:
            newpiece->icon = PLAYER_ICO_1;
            break;
        
        case MONSTER_TYPE:
            newpiece->icon = MONSTER_ICO_1;
            break;
        
        case DOOR_TYPE:
            newpiece->icon = DOOR_ICO;
            break;
            
        case SWORD_TYPE:
            newpiece->icon = SWORD_ICO_1;
            break;
            
        case SHIELD_TYPE:
            newpiece->icon = SHIELD_ICO_1;
            break;
            
        case POTION_TYPE:
            newpiece->icon = POTION_ICO_1;
            break;
            
        case WALL_TYPE:
            newpiece->icon = WALL_ICO;
            break;
    }
    
    return newpiece;
}

int destroy_piece(gamepiece * piece){
    if(piece == NULL){
        return 1;
    }
    //recusicly free sub structs
    if(piece->sword != NULL){
        destroy_piece(piece->sword);
    }
    if(piece->shield != NULL){
        destroy_piece(piece->shield);
    }
    free(piece);
    return 0;
}
 
/********GETTERS*************************/

int get_piece_x(gamepiece *piece){
    //interface to return a game piece's x position.
    if(piece == NULL){
        return -1;
    }
    int a = piece->x;
    return a;
}

int get_piece_y(gamepiece *piece){
    //interface to get gamepiece y coordinate
    if(piece == NULL){
        return -1;
    }
    int y = piece->y;
    return y;
}

int get_piece_val(gamepiece * item){
    //interface to access a gamepiece's val
    if(item == NULL){
        return 0;
    }
    return item->val;
}

char * get_piece_name(gamepiece * piece){
    //interface to access gamepieces name
    
    if(piece == NULL){return NULL;}
    
    return piece->name;
}

gamepiece * get_player_sword(gamepiece * piece){
    //return gamepieces sword
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){ //only for action character
         if(piece->sword != NULL){
             gamepiece * psword = piece->sword;
             
             //copy coords from player to sword
             set_piece_x(psword, get_piece_x(piece)); 
             set_piece_y(psword, get_piece_y(piece)); 
             return psword;
         }else{
             return NULL;
         }
    }else{
        return NULL;
    }
}

gamepiece * get_player_shield(gamepiece * piece){
    //return gamepieces shield
    //return null on failer or empty
    
    if( (get_piece_type(piece) == PLAYER_TYPE) ||
        (get_piece_type(piece) == MONSTER_TYPE) ){ //only for action character
         if(piece->shield != NULL){
             gamepiece * pshield = piece->shield;
             
             //copy coords from player to shield
             set_piece_x(pshield, get_piece_x(piece)); 
             set_piece_y(pshield, get_piece_y(piece)); 
             return pshield;
         }else{
             return NULL;
         }
    }else{
        return NULL;
    }
}

piecetype get_piece_type(gamepiece *piece){
    //super quick dirty function
    return piece->type;
 
}

Icon get_piece_icon(gamepiece *piece){
    //super quick dirty function
    return piece->icon;
 
}

/****************SETTERS**********************/

int set_piece_x(gamepiece * piece, int x){
    //interface to set the piece x coord
    if(piece == NULL){
        return 1;
    }
    if(x < 0 ){
        return -1;
    }
    piece->x = x;
    return 0;
}

int set_piece_y(gamepiece * piece, int y){
    //interface to set the piece x coord
    if(piece == NULL){
        return 1;
    }
    if(y < 0 ){
        return -1;
    }
    piece->y = y;
    return 0;
}
    
int set_piece_val(gamepiece * piece, int val){
    //interface to set item value
    if(piece == NULL){ return 1;}
    piece->val = val;
    return 0;
}

int set_player_health(gamepiece* player, int a){
    //set the health stat of a player or monster health
    
    //check for correct type first
    if( (get_piece_type(player) != PLAYER_TYPE) && (get_piece_type(player) != MONSTER_TYPE) ){
        return -1;
    }
    if(a <= 100){
        player->val = a;
    }
    if(a > 100){
        player->val = 100;
    }
    return 0;
}
    
int set_piece_name(gamepiece * piece, char * string){
    //interface to set gamepieces name
    
    if(piece == NULL){return 1;}
    
        if(strncpy(piece->name, string, 15) == NULL){
            return 1;
        }else{
            return 0;
        }
}

int set_piece_icon(gamepiece * piece, Icon icon){
    //change icon
    
    if(piece == NULL){return 1;}
    piece->icon = icon;
    return 0;
}

    
gamepiece * equip_item_to_player(gamepiece * player, gamepiece * item){
    //take an item and add it to player stuct, pop current item and return
    if( (item == NULL) || (player == NULL) ){
        return NULL;
    }
    if( (get_piece_type(player) != PLAYER_TYPE) && (get_piece_type(player) != MONSTER_TYPE) ){
        return NULL;
    }
    
    if(get_piece_type(item) == SWORD_TYPE){
        //copy the pointer to player's current shield
        gamepiece * new_sword;        
        new_sword = get_player_sword(player);  
        
        //assign incoming item to player slot
        player->sword = item;
        
        //return popped sword
        return new_sword;   
    }
    if(get_piece_type(item) == SHIELD_TYPE){
        //copy the pointer to player's current shield
        gamepiece * new_shield;        
        new_shield = get_player_shield(player);  
        
        //assign incoming item to player slot
        player->shield = item;
        
        //return popped shield
        return new_shield;   
    }
    if(get_piece_type(item) == POTION_TYPE){
        //grab values and claculate new health level
        int cur_health = get_piece_val(player);
        int potion_val = get_piece_val(item);
        
        //set health, setter function will handle healh value bounds
        set_piece_val(player, cur_health + potion_val);
        
        //free poition struct
        destroy_piece(item);
        return NULL;
    }else{
        return NULL;
    }
}        

/************ACTION ***********************/

int move_piece(gamepiece * piece, enum direction direc){
    animate(piece);
    switch(direc){
        case UP:
            (piece->y) -= 1;
            break;
        case DOWN:
            (piece->y) += 1;
            break;
        case LEFT:
            (piece->x) -= 1;
            break;
        case RIGHT:
            (piece->x) += 1;
            break;
            
        }
        
    return 0;
}

int animate(gamepiece * player){
    //animate the player icon with the  three difffernt icons
    Icon current_ico = get_piece_icon(player);
    switch(current_ico){
        case PLAYER_ICO_1:
            set_piece_icon(player, PLAYER_ICO_2);
            break;
        case PLAYER_ICO_2:
            set_piece_icon(player, PLAYER_ICO_3);
            break;
        case PLAYER_ICO_3:
            set_piece_icon(player, PLAYER_ICO_1);
            break;
    }
    return 0;
}

int attack(gamepiece *attacker, gamepiece *defender){
    int valS;   //sword
    int valSH;  //shield
    int damage;
    int healthD;    //defender health
    int healthA;    //attacker health
    int new_healthD;
    srand(time(NULL));
    int r = (rand()% 100) + 1;      //Generates random numbers between 1 & 100

    gamepiece * sword = get_player_sword(attacker);
    if(sword == NULL){
        valS = 2;}
    else{
        valS = get_piece_val(sword);
    }

    gamepiece * shield = get_player_shield(defender);
    if(shield == NULL){
        valSH = 0;}
    else{
        valSH = get_piece_val(shield);
    }

    if(valS == 0 && valSH == 0){
        damage = 0;
    }
    else{
        damage = valS - valSH;
    }

    healthD = get_piece_val(defender);
    healthD = healthD - damage;
    new_healthD = set_player_health(defender, healthD);

    return damage;
}
