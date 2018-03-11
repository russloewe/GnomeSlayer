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
                            move_piece(current_room->monsters[0], MVUP);
                            add_message_queue("You Moved Up");
                            return 1;
                            break;
                            
                        case SDLK_DOWN:
                            move_piece(current_room->monsters[0], MVDOWN);
                            add_message_queue("You Moved Down");
                            return 1;
                            break;

                        case SDLK_LEFT:
                            move_piece(current_room->monsters[0], MVLEFT);
                            add_message_queue("You Moved Left");
                            return 1;
                            break;
                        
                        case SDLK_RIGHT:
                            move_piece(current_room->monsters[0], MVRIGHT);
                            add_message_queue("You Moved Right");
                            return 1;
                            break;
                    }
                break;
            }
        }
    return 1;
}
