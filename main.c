/*
 * file      : main.c
 * date      : 20 Feb 2018
 * Purpose:
 *          Final project for CS133 winter 2018.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/input.h"
#include "./headers/graphics.h"
#include "./headers/maps.h"


int main(void){
    
       init_video();      //open the screen
        /***********temp room hack***************/
/*        room room1 = {.walls = {NULL}}; //init walls array to null pointers
        //make some walls
        for(int i = 1; i < 11; i++){
        gamepiece * wall = create_piece(5, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i-1] = wall;
        }
        //spawn some monsters
        gamepiece * monst;
        for(int i = 0; i<5; i++){
        monst = create_piece(rand()%10+8, rand()%10+8, load_image("./img/player.bmp"), MONSTER_TYPE);
        room1.monsters[i] =monst;
    }*/
    /******************end temp room hack**********/
       
//   room room1 = {.walls = {NULL}}; 
    room room1; 
   //RK: Attempting to call create_room function
    room1 = create_room();

    /*
     * Create a player piece add it to array
     */
    gamepiece * player;
    player = create_piece(5, 5, load_image("./img/player.bmp"), PLAYER_TYPE);
    gamepiece * objects[10] = {NULL};
    objects[0] = player;
    
    //main loop 
    while(1){
        

        //parse input from sdl event, needs own function
        switch(get_input()){
            case 0:
                cleanup();
                return 0;
                break;
                
            case 2:
                move_piece(player, MVUP);
                break;
                
            case 3:
                move_piece(player, MVDOWN);
                break;
                
            case 5:
                move_piece(player, MVRIGHT);
                break;
                
            case 4:
                move_piece(player, MVLEFT);
                break;
        }
        
        //render the background
        render_background();
        
        //render the objects to screen    
        if(render_objects(objects,1) != 0){
            printf("Failed\n");
            return -1;
        }
            //test function 

    
        render_room(&room1);
    
    //end test function
        //hold up a sec to not hog the cpu
        SDL_Delay(16);
    }
    
    
    cleanup();
    
    return 0;
}

