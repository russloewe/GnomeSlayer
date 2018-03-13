/* author: russ loewe
 * date:   20 feb 2018
 * file:   maps_test_suit.c
 * Purpose:
 *         This file contains all of the maps_tests to run in this suit.
 *         each of these maps_tests needs to  have their function name put 
 *         in the function pointer array of maps_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"


int run_maps_tests();
int cleanmaps_test();
int maps_test1();
int maps_test2();
int maps_test3();
int maps_test4();
int maps_test5();
int maps_test6();
int maps_test7();


int run_maps_tests(){
        printf("running maps_tests now\n");
    printf("**********************************************\n");
    int (*maps_test_suit[])() = {maps_test1, maps_test2, maps_test3,
                                 maps_test4, cleanmaps_test};                      //array of all maps_tests to run - cleanmaps_test must be at the end of this array
    const int maps_test_len = sizeof(maps_test_suit) / sizeof(maps_test_suit[0]);  //variable to tell maps_test runner how many maps_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < maps_test_len; i++){
        int response;
        
        response = maps_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last maps_test is supposed to return 0 to indicate maps_tests are done
                printf("Finished Runnig all maps_tests. Success: %i\n", success);
                printf("                                Failure: %i\n", failure);
                printf("**********************************************\n");
                return (success*1000) + failure;
            
            case 1:
                success++;
                break;
            
            default:
                failure++;
                break;
        }
    }
    printf("Error: maps_test.c -> run_maps_tests() -> not cleanup at end\n");
    printf("**********************************************\n");
    return 1;
}
/***************************** Begin maps_test Functions ********************/
int cleanmaps_test(){
    printf("cleaning up maps_tests\n");
    return 0;
}

int maps_test1(){
    /*
     * Setup current room
     */
     printf("maps_testing init_room()   ");
     int result = 1; // for testing return values
          /***********temp room hack***************/
        room room1 = {.walls = {NULL}, .monsters = {NULL}, .bounty = {NULL}}; //init walls array to null pointers
        room * roomc = (room*)malloc(sizeof(room));
        memcpy(roomc, &room1, sizeof(room));
        set_current_room(roomc);
                
        //make some walls
        for(int i = 0; i < 300; i++){
            int result;
            result= add_wall_to_current_room(create_piece(1, 0, "wall", 1, WALL_TYPE));  
            if(result != 0){
                printf("Fail 1\n");
                return -1;
            }
        }
        
        for(int i = 0; i < 300; i++){
            
            result= add_wall_to_current_room(create_piece(1, 0, "wall", 1, WALL_TYPE));
            if(result != 1){
                printf("Fail 1\n");
                return -1;
            }
        }        
        
        //spawn some monsters
        for(int i = 1; i < 9; i++){
            result = add_monster_to_current_room(create_piece(i+1, i+1, "monster", 100, MONSTER_TYPE));
            if(result != 0){
                printf("Fail 2\n");
                return -1;
            }
        }
        //add some items
        for(int i = 0; i < 9; i++){ 
            result = add_item_to_current_room(create_piece(i, i, "potion", 40, POTION_TYPE));
            if(result != 0){
                printf("Fail 3\n");
                return -1;
            }
        }      
       
        //add the two doors;
        room1.doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
        room1.doors[1] = create_piece(get_max_x(), 5, "door", 1, DOOR_TYPE);

    /******************end temp room hack**********/
    
    if(get_current_room() != roomc){
        printf("Fail 1\n");
        return -1;
    }
    printf("Pass \n");
   return 1;
}

int maps_test2(){
    /*
     * test set player get player 
     */
     printf("maps_testing  get/set_player(): ");
     
     gamepiece * player = create_piece(2, 3, "test", 100, PLAYER_TYPE);
     
     add_player_to_current_room(player);
     
     gamepiece * second = get_player();
     
     if(second == NULL){
         printf("Fail 1\n");
         return -1;
     }
     
      if(second != player){
         printf("Fail 2\n");
         return -1;
     }
     printf("Pass \n");
     
   return 1;
}

    
int maps_test3(){
    /*
     * test grab reference to item
     */
     printf("maps_testing grab_item_reference(): ");
     room * current_room = get_current_room();
     set_piece_x(current_room->bounty[0], 5);
     set_piece_y(current_room->bounty[0], 5);
     
     gamepiece * item = grab_item_reference(5, 5);
     
     if(item != current_room->bounty[0]){
         printf("Fail 1\n");
         return -1;
     }
     
     printf("Pass \n");
   return 1;
}
    
int maps_test4(){
    /*
     * test adjectent getter
     */
     printf("maps_testing get_adjacent_item():  ");
     
     room * current_room = get_current_room();
     gamepiece * player = get_player();
     
     //make sure player and item areadacent
     set_piece_x(player, 4);
     set_piece_y(player, 5);
     set_piece_x(current_room->bounty[0], 5);
     set_piece_y(current_room->bounty[0], 5);
     
     gamepiece * item = get_adjacent_item(player, RIGHT);
     
     if(item == NULL){
         printf("Fail 1\n");
         return -1;
     }
     
     if(item != current_room->bounty[0]){
         printf("Fail 2\n");
         return -1;
     }
   return 1;
}

int maps_test5(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}

int maps_test6(){
      /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}
    
