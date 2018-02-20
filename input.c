#include "./headers/input.h"

int get_input(void){
    
    SDL_Event event;    //event handler or something
        
    while(SDL_PollEvent(&event)){

            switch(event.type){
                    
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        
                        case SDLK_ESCAPE:         //exit key
                            return 0;
                            break;
                    }
            }
        }
    return 1;
}
