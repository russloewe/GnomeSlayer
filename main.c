/*
 * file      : main.c
 * date      : 20 Feb 2018
 * Purpose:
 *          Final project for CS133 winter 2018.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "./headers/init.h"
#include "./headers/input.h"
#include "./headers/display.h"


int main(void){
    
    SDL_Surface* image = NULL;   //image for player 
    
    init_video();      //open the screen

    /*
     * Create a player piece add it to array
     */
    gamepiece * player;
    SDL_Surface * img;
    img = load_image("./img/player2.bmp");
    player = create_piece(50, 50, img, PLAYER_TYPE);
    gamepiece * objects[] = {player};
    
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

