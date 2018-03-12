#include "./headers/input.h"

int pickup_item();          // swap item on ground with item in player inventory 

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


int pickup_item(){
    //grab player reference
   gamepiece * player = get_player();
   
   //grab x, y coords
   int x = get_piece_x(player);
   int y = get_piece_y(player);
    
    //pick up the item
    gamepiece * item = grab_item_reference(x, y);                         
    
    //grab the type
    if(item != NULL){
        piecetype type = get_piece_type(item);                          
    
        //for swords and shields
        if( (type == SWORD_TYPE) || (type == SHIELD_TYPE) ){    
            //equip item and grab pointer to formerly equipped item         
            gamepiece * tmp_item = equip_item_to_player(player, item);   
            
            if(remove_item_from_current_room(item) != 0){
                printf("couldn't remove item from map\n");
                return 1;
            }
            
            if(tmp_item != NULL){
                //copy coords to item being dropped
                set_piece_x(tmp_item, x);                                
                set_piece_y(tmp_item, y);
                add_item_to_current_room(tmp_item);
            }
            
            //construct and add message to queue
            char message[40];                                    
            strncat(message, "Equipped: ", 11);
            strncat(message, get_piece_name(item), 20);
            add_message_queue(message);
        }
        //for potions
        if(type == POTION_TYPE){
            int player_health = get_piece_val(player);
            int potion_val = get_piece_val(item);
            
            //calculate new player health and apply new value
            player_health = player_health + potion_val;
            set_player_health(player, player_health);
            
            //make message
            char message[40];
            char * potion_name = get_piece_name(item);
            sprintf(message, "You drank %s for %d LP", potion_name, potion_val);
            add_message_queue(message);
            
            //remove item from map and destroy potion
            remove_item_from_current_room(item);
            destroy_piece(item);            
        }
    }
        
    return 0;
}


