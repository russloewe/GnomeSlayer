/*
 * file: checker.c
 * date: 9 mar, 2018
 * purpose: functions to check various game states
 */

#include "./headers/checker.h"

enum piecetype player_on_item(room * curroom){
    //use direct access now, switch to interface when done with maps
    
   // gamepiece * player = get_player();  //function not defined yet in map interface
    gamepiece * player = curroom->monsters[0];
    int x = get_piece_x(player);
    int y = get_piece_y(player);
    
    //below will probably end up in map interface get_item() 
    for(int i = 0; i < 5; i++){
        if(curroom->bounty[i] != NULL){ //iterate through bounty list, examining a stat as we go
            int i_x = get_piece_x(curroom->bounty[i]);
            int i_y = get_piece_y(curroom->bounty[i]);
            
            if( (i_x == x) && (i_y == y) ){ //return the first item that matches x,y coords
                return get_piece_type(curroom->bounty[i]);
            }
        }
    }
    
    return PLAYER_TYPE;
}  

int is_player_dead(gamepiece * piece){
    /* check if player or monster is dead
     * return 1 if dead, 0 if not
     */
     
     int health = get_piece_health(piece);
     
     if(health <= 0){
         return 1;
     }else{
         return 0;
     }
 }
    
