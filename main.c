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
#include "SDL2/SDL.h"
#include "./headers/input.h"
#include "./headers/graphics.h"
#include "./headers/maps.h"

//room * current_room;  //this needs to be parked in the maps module eventually

int main(void){
    
    init_video();      //open the screen
    int running = 1;

    int seed = time(NULL); // set random number gernerator
    srand(seed);

        /***********temp room hack***************/
        room room1 = {.walls = {NULL}, .monsters = {NULL}, .bounty = {NULL}}; //init walls array to null pointers
        set_current_room(&room1);
        room * current_room = &room1;          //set current room pointer to room1
        
        //make some walls
        for(int i = 0; i < 40; i++){
            add_wall_to_map(create_piece(i, 0, "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < 17; i++){        
            add_wall_to_map(create_piece(0, i, "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < 40; i++){
            add_wall_to_map(create_piece(i, 17, "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < 17; i++){
            add_wall_to_map(create_piece(39, i, "wall", 1, WALL_TYPE));
        }
        
        
        //spawn some monsters
        for(int i = 0; i < 9; i++){
            add_monster_to_map(create_piece(rand()%37+2, rand()%14+2, "monster", 100, MONSTER_TYPE));
        }
        //add some items 
        add_item_to_map(create_piece(rand()%37+2, rand()%14+2, "potion", 40, POTION_TYPE));
       
        //make 2 swords
        add_item_to_map(create_piece(rand()%37+2, rand()%14+2, "Big Sword", 25, SWORD_TYPE));
        add_item_to_map(create_piece(rand()%37+2, rand()%14+2, "Big Dagger", 25,  SWORD_TYPE));
        
        //make two shields
        add_item_to_map(create_piece(rand()%37+2, rand()%14+2, "Iron Shield", 20, SHIELD_TYPE));
        add_item_to_map(create_piece(rand()%37+2, rand()%14+2, "Bronze Shield", 40, SHIELD_TYPE));
       
        //add the two doors;
        room1.doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
        room1.doors[1] = create_piece(39, 5, "door", 1, DOOR_TYPE);
        
    /******************end temp room hack**********/
        

    /*
     * Create a player piece add it to array
     */
    room1.monsters[0] = create_piece(5, 5, "Toby", 100, PLAYER_TYPE);
    
    //main loop 
    while(1){        

        if(get_input() == 0){
            break;
        }
        
        render_all();

        //hold up a sec to not hog the cpu
        SDL_Delay(5);
    }
    
    
    cleanup();
    
    return 0;
}

