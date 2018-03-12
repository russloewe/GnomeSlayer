#include "./headers/maps.h"

//local protytypes



static room * _current_room;        //this points to current room


room * get_current_room(){
    //interface to get room
    return _current_room;
}

int set_current_room(room * curroom){
    //interface to set room
    _current_room = curroom;
    return 1;
}

int remove_item_from_current_room(gamepiece * item){
    int x = get_piece_x(item);
    int y = get_piece_y(item);
    
    for(int i = 0; i < 5; i++){
        gamepiece * temp = _current_room->bounty[i];
        if( temp != NULL){
            int it_x = get_piece_x(temp);
            int it_y = get_piece_y(temp);
            
            if( (it_x == x) && (it_y == y) ){
                _current_room->bounty[i] = NULL;
                return 0;
            }
        }
    }
    return 1;
}

int add_item_to_current_room(gamepiece * item){
    //look for empty slot to add item to room struct
    for(int i = 0; i < 10; i++){
        if(_current_room->bounty[i] == NULL){
            _current_room->bounty[i] = item;   //look for empty slot to add item
            return 0;
        }
    }
    return 1;
}

int add_monster_to_current_room(gamepiece * monster){
    //look for empty slot to add monster to room    
    for(int i = 1; i < 10; i++){
        if(_current_room->monsters[i] == NULL){
            _current_room->monsters[i] = monster;   //look for empty slot to add item
            return 0;
        }
    }
    return 1;
}

int add_wall_to_current_room(gamepiece * wall){
    //look for empty slot to add monster to room    
    for(int i = 0; i < 300; i++){
        if(_current_room->walls[i] == NULL){
            _current_room->walls[i] = wall;   //look for empty slot to add item
            return 0;
        }
    }
    return 1;
}

int add_player_to_current_room(gamepiece * player){
    //add player to front of monster aray
    _current_room->monsters[0] = player;   //look for empty slot to add item
    return 1;
}



gamepiece * grab_item_reference(int x, int y){
    //look for item at x,y and return pointer, leave in bounty list
    for(int i = 0; i < 5; i++){
        gamepiece * temp = _current_room->bounty[i];
        if( temp != NULL){
            int it_x = get_piece_x(temp);
            int it_y = get_piece_y(temp);
            
            if( (it_x == x) && (it_y == y) ){
                return temp;
            }
        }
    }
    return NULL;
}

gamepiece * get_player(){
    //super quick interface
    return _current_room->monsters[0];
}

int random_x(){
    int max = get_max_x();
    int random =  ( rand() % (max - 2) ) + 1;
    return random;
}

int random_y(){
    int max = get_max_y();
    int random =  ( rand() % (max - 2) ) + 1;
    return random;
}
    
