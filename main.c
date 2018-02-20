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


int main(void){
    
       
    
    init_video();      //open the screen
    
    while(1){
        
        if( get_input() == 0 ){
            cleanup();
            return 0;
        }
        SDL_Delay(16);
    }
    
    
    cleanup();
    
    return 0;
}

