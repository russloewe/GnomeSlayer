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


int main(void){
    
    
    init_video();      //open the screen

    /*
     * Create a player piece add it to array
     */
    gamepiece * player;
    player = create_piece(5, 5, load_image("./img/wall.bmp"), PLAYER_TYPE);
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
        if(render_objects(objects) != 0){
            printf("Failed\n");
            return -1;
        }
        
        //hold up a sec to not hog the cpu
        SDL_Delay(16);
    }
    
    
    cleanup();
    
    return 0;
}

