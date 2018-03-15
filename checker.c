/*
 * file: checker.c
 * date: 9 mar, 2018
 * purpose: functions to check various game states
 */

#include "./headers/checker.h"

int monster_alive(){
    //return 1 if there is a monster alive in current room
    init_monster_iter();
    for(int i = 0; i <10; i++){
        if(monster_iter() != NULL){
            return 1;
        }
    }
    return 0;
}



int player_on_item(){
    
    room * curroom = get_current_room();
    
    gamepiece * player = get_player();  //function not defined yet in map interface
    
    
    int x = get_piece_x(player);
    int y = get_piece_y(player);
    
    //below will probably end up in map interface get_item() 
    for(int i = 0; i < 5; i++){
        if(curroom->bounty[i] != NULL){ //iterate through bounty list, examining a stat as we go
            int i_x = get_piece_x(curroom->bounty[i]);
            int i_y = get_piece_y(curroom->bounty[i]);
            
            if( (i_x == x) && (i_y == y) ){ //return the first item that matches x,y coords
                return 1;
            }
        }
    }
    
    return 0;
}  

int is_player_dead(gamepiece * piece){
    /* check if player or monster is dead
     * return 1 if dead, 0 if not
     */
     if( (get_piece_type(piece) == PLAYER_TYPE) || (get_piece_type(piece) == MONSTER_TYPE) ){
          //get health   
         int health = get_piece_val(piece);         
         if(health <= 0){
             return 1;     //dead
         }else{
             return 0;     //not dead
         }
    }else{
        return 1;  //inanimate objects return dead
    }
}
    
    
int check_for_dead_monsters(){
    int killcount = 0;
    room * room1 = get_current_room();
    
    gamepiece * monster;
    
    for(int i = 1; i < 10; i++){
        monster = room1->monsters[i];
        if(monster != NULL){
            if(is_player_dead(monster)){
                destroy_piece(monster);
                room1->monsters[i] = NULL;
                killcount++;
            }
        }
    }
    return killcount;
}

direction is_player_near(gamepiece * monster, int i){
    if(monster == NULL){
        return NONE;
    }
    gamepiece * player = get_player();
    
    int px = get_piece_x(player);
    int py = get_piece_y(player);
    int mx = get_piece_x(monster);
    int my = get_piece_y(monster);
    
    if( ( (mx > px) && (abs(mx - px) <= i) ) && (abs(my - py) <= i) ) {
        return LEFT;
    }
    if( ( (mx < px) && (abs(mx - px) <= i) ) && (abs(my - py) <= i) ) {
        return RIGHT;
    }
    if( ( (my > py) && (abs(my - py) <= i) ) && (abs(mx - px) <= i) ) {
        return UP;
    }
    if( ( (my < py) && (abs(my - py) <= i) ) && (abs(mx - px) <= i)) {
        return DOWN;
    }
    
    return NONE;
}
    
    

