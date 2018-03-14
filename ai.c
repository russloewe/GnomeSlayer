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
    int rand_dir = rand() % 5;
    
    if(rand_dir > 3){
        return 0;
    }else{
        move_piece(monster, rand_dir);
    }
    return 0;
}
