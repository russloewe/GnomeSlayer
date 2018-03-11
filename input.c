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
                            
                        case SDLK_SPACE: ; //empty statement because of variable declared after label
                            //attempt to grab item on ground
                            gamepiece * item = player_on_item(get_current_room());
                            
                            if(item != NULL){ //check for item first
                                piecetype type = get_piece_type(item); //grab the type
                                
                                if( (type == SWORD_TYPE) || (type == SHIELD_TYPE) ){ //for sword and shield
                                    gamepiece * tmp_item = equip_item_to_player(current_room->monsters[0], item); //equip item and grab pointer to formeraly equipped item
                                    destroy_piece(tmp_item);
                                    
                                    //construct and add message to queue
                                    char message[40];                                    
                                    strncat(message, "Equipped: ", 11);
                                    strncat(message, get_piece_name(item), 20);
                                    add_message_queue(message);
                                }
                            }
                            return 1;
                            break;
                                
                    }
                break;
            }
        }
    return 1;
}
