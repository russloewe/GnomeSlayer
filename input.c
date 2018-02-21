#include "./headers/input.h"

int get_input(void){
    
    SDL_Event event;    //event handler or something
        
    while(SDL_PollEvent(&event)){

            switch(event.type){
                case SDL_QUIT:
                    return 0;
                    break;
                    
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        
                        case SDLK_ESCAPE:         //exit key
                            return 0;
                            break;
                            
                        case SDLK_UP:
                            return 2;
                            break;
                            
                        case SDLK_DOWN:
                            return 3;
                            break;

                        case SDLK_LEFT:
                            return 4;
                            break;
                        
                        case SDLK_RIGHT:
                            return 5;
                            break;
                    }
                break;
            }
        }
    return 1;
}
