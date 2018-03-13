#include "./headers/maps.h"

//local protytypes



static room * _current_room;        //this points to current room

room * create_room(void) {

//    struct room room1;

//need to check alloc
    room * newroom = (room *)malloc(sizeof(room));

//Second attempt
  //OLD     room room1 = {.walls = {NULL}, .monsters = {NULL}, .bounty = {NULL}}; //init walls array to null pointers
     //   room1 = {.walls = {NULL}, .monsters = {NULL}, .bounty = {NULL}}; //init walls array
     struct room room_tmp = {.walls = {NULL}, .monsters = {NULL}, .bounty = {NULL}};
     memcpy(newroom, &room_tmp, sizeof(struct room));
    //    set_current_room(&room1);
        set_current_room(newroom);
        room * current_room = newroom;          //set current room pointer to room1
   //     room * current_room = &room1;          //set current room pointer to room1
    //    room * current_room;
    //    current_room = room1;          //set current room pointer to room1
        //make some walls
        for(int i = 0; i < get_max_x(); i++){
            add_wall_to_current_room(create_piece(i, 0, "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < get_max_y(); i++){        
            add_wall_to_current_room(create_piece(0, i, "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < get_max_x(); i++){
            add_wall_to_current_room(create_piece(i, get_max_y(), "wall", 1, WALL_TYPE));
        }
        for(int i = 0; i < get_max_y()+1; i++){
            add_wall_to_current_room(create_piece(get_max_x(), i, "wall", 1, WALL_TYPE));
        }
        
        
        //spawn some monsters
        for(int i = 0; i < 6; i++){
            add_monster_to_current_room(create_piece(random_x(), random_y(), "monster", 100, MONSTER_TYPE));
        }
        //add some items 
        add_item_to_current_room(create_piece(random_x(), random_y(), "potion", 40, POTION_TYPE));
       
        //make 2 swords
        add_item_to_current_room(create_piece(random_x(), random_y(), "Big Sword", 25, SWORD_TYPE));
        add_item_to_current_room(create_piece(random_x(), random_y(), "Big Dagger", 25,  SWORD_TYPE));
        
        //make two shields
        add_item_to_current_room(create_piece(random_x(), random_y(), "Iron Shield", 20, SHIELD_TYPE));
        add_item_to_current_room(create_piece(random_x(), random_y(), "Bronze Shield", 40, SHIELD_TYPE));
       
        //add the two doors;        
     //   room1.doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
     //   room1.doors[1] = create_piece(get_max_x(), 5, "door", 1, DOOR_TYPE);  
        newroom->doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
        newroom->doors[1] = create_piece(get_max_x(), 5, "door", 1, DOOR_TYPE); 



//First attempt

 /*   room1 = {.walls = {NULL}}; //init walls array to null pointers

    //make some walls
        for(int i = 1; i < 11; i++){
        gamepiece * wall = create_piece(5, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i-1] = wall;
        }
        //spawn some monsters
        gamepiece * monst;
        for(int i = 0; i<5; i++){
        monst = create_piece(rand()%10+8, rand()%10+8, load_image("./img/player.bmp"), MONSTER_TYPE);
        room1.monsters[i] =monst; */
        
        return newroom;
}
        
        

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


gamepiece * get_adjacent_item(gamepiece * ref_piece, enum direction dir){
    return NULL;
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
    
