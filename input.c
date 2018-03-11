#include "./headers/input.h"



int get_input(void){
    
    SDL_Event event;    //event handler or something
        
    while(SDL_PollEvent(&event)){
        room * current_room = get_current_room();
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
                        move_piece(current_room->monsters[0], MVUP); //ned to replace with room interface to get player
                        return 1;
                        break;
                        
                    case SDLK_DOWN:
                        move_piece(current_room->monsters[0], MVDOWN);
                        return 1;
                        break;

                    case SDLK_LEFT:
                        move_piece(current_room->monsters[0], MVLEFT);
                        return 1;
                        break;
                    
                    case SDLK_RIGHT:
                        move_piece(current_room->monsters[0], MVRIGHT);
                        return 1;
                        break;
                         
                    case SDLK_SPACE: ;
                        if(player_on_item(current_room)){
                            pickup_item();                            
                        } 
                        return 1;
                        break;
                            
                }
            break;
        }
        }
    return 1;
}


