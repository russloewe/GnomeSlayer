/*
 * file      : main.c
 * date      : 20 Feb 2018
 * Purpose:
 *          Final project for CS133 winter 2018.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "./headers/input.h"
#include "./headers/maps.h"
#include "./headers/ai.h"
#include "./headers/checker.h"

//room * current_room;  //this needs to be parked in the maps module eventually

int main(void){
    
    start_graphics_module();      //open the screen
    int running = 1;

   int seed = time(NULL); // set random number gernerator
    srand(seed);

    create_map();
   //RK: Attempting to call create_room function
    room * room1 = get_current_room();


    /*
     * Create a player piece add it to array
     */

    room1->monsters[0] = create_piece(5, 5, "Toby", 50, PLAYER_TYPE);
    
    //main loop 
    while(1){   
        int input_result;     
    
        input_result = get_input();
        check_for_dead_monsters();
        if(input_result == 0){
            break;
        }else if(input_result == 2){
            ai();
        }
        
        draw_all();
        
        //break the main loop if player is dead
        if(is_player_dead(get_player())){
            draw_loosing_screen();
            break;
        }

        //hold up a sec to not hog the cpu
        SDL_Delay(5);
    }
    
    while(1){//loop until player hits exit
        if(get_i() == 0){
            break;
        }
    }
        
    
    cleanup();
    
    return 0;
}

