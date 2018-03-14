#include "./headers/ai.h"

int move_monster_random(gamepiece * monster);

int ai(){
    init_monster_iter();
    gamepiece * monster;
    room * curoom = get_current_room();
    for(int i = 1; i < 10; i++){
        monster = monster_iter();
        if(monster != NULL){
            move_monster_random(monster);
        }
    }
    return 0;
}

int move_monster_random(gamepiece * monster){
    int rand_dir = rand() % 8;
    int attk_result;
    char message[50];
    char message2[50];
    
    if(rand_dir > 3){
        return 0;
    }else{
        //see if there is a gamepiece in the way
        gamepiece * piece = get_adjacent_item(monster, rand_dir);
        if(piece == NULL){
            move_piece(monster, rand_dir);
        }else{
            piecetype type = get_piece_type(piece);
            switch(type){
                case WALL_TYPE:
                case DOOR_TYPE:
                case MONSTER_TYPE:
                return 0;      // don't travel into walls or other monsters
                
                default:
                move_piece(monster, rand_dir);
                return 0;
            }
        }
    }
    return 0;
}
