/*author    : russ loewe
 * date     : 20 feb 2018
 * file     : init.c
 * purpose:
 *          Initialize the SDL video whatever and open a screen. Largly
 *          taken from SDL's doc pages.
 */
#include "./headers/init.h"

SDL_Window * Main_Screen = NULL;
SDL_Renderer * Main_Renderer  = NULL;

int init_video(void){
    
      //declar pointer to SDL Surface
    
    /*
     * Initialize the SDL subsytem for video only. 
     * If initai
     */ 
    if( SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("ERROR: init.c -> init_video -> SDL_Init\n: %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    /*
     * Open a screen 640 by 480, with the double buffer feature 
     * to speed rendering.
     */
    Main_Screen = SDL_CreateWindow("PCC CS133 Final",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          SDL_WINDOW_OPENGL);
                          
    if(Main_Screen == NULL){
        printf("ERROR: init.c -> init_video -> SDL_CreateWindow : %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    /*
     * inti the renderer
     */
     Main_Renderer = SDL_CreateRenderer(Main_Screen, -1, 0);
    
    if(Main_Renderer == NULL){
        printf("ERROR: init.c -> init_video -> SDL_CreateRenderer : %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    
    return 0;
}

void cleanup(){
    /*
     * Close down whatever SDL is doing or you might get a runaway screen
     */
    SDL_DestroyRenderer(Main_Renderer);
    SDL_DestroyWindow(Main_Screen);
    SDL_Quit();
}
