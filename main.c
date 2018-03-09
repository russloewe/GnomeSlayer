/*
 * file      : main.c
 * date      : 20 Feb 2018
 * Purpose:
 *          Final project for CS133 winter 2018.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "./headers/input.h"
#include "./headers/graphics.h"
#include "./headers/maps.h"

room * current_room;  //this needs to be parked in the maps module eventually

int main(void){
    
    init_video();      //open the screen
    set_background_image("./img/background2.bmp");
    int seed = time(NULL); // set random number gernerator
    srand(seed);

        /***********temp room hack***************/
        room room1 = {.walls = {NULL}}; //init walls array to null pointers
        current_room = &room1;          //set current room pointer to room1
        //make some walls
        for(int i = 0; i < 40; i++){
        gamepiece * wall = create_piece(i, 0, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i] = wall;
        }
        for(int i = 0; i < 17; i++){
        gamepiece * wall = create_piece(0, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i+50] = wall;
        }
        for(int i = 0; i < 40; i++){
        gamepiece * wall = create_piece(i, 17, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i+100] = wall;
        }
        for(int i = 0; i < 17; i++){
        gamepiece * wall = create_piece(39, i, load_image("./img/wall.bmp") , WALL_TYPE);
        room1.walls[i+150] = wall;
        }
        
        
        //spawn some monsters
        gamepiece * monst;
        for(int i = 0; i<5; i++){
            monst = create_piece(rand()%38+2, rand()%15+2, load_image("./img/monster.bmp"), MONSTER_TYPE);
            room1.monsters[i] =monst;
        }
        //add some items
        gamepiece * potion = create_piece(rand()%38+2, rand()%15+2, load_image("./img/potion.bmp"), POTION_TYPE);
        room1.bounty[0] = potion;
        gamepiece * sword = create_piece(rand()%38+2, rand()%15+2, load_image("./img/sword.bmp"), SWORD_TYPE);
        room1.bounty[1] = sword;
        gamepiece * shield = create_piece(rand()%38+2, rand()%15+2, load_image("./img/shield.bmp"), SHIELD_TYPE);
        room1.bounty[2] = shield;
       
        //add the two doors;
        gamepiece * d1 = create_piece(0, 10, load_image("./img/door.bmp"), DOOR_TYPE);
        gamepiece * d2 = create_piece(39, 5, load_image("./img/door.bmp"), DOOR_TYPE);
        
        room1.doors[0] = d1;
        room1.doors[1] = d2;
        
    /******************end temp room hack**********/
        

    /*
     * Create a player piece add it to array
     */
    room1.monsters[0] = create_piece(5, 5, load_image("./img/player.bmp"), PLAYER_TYPE);
    room1.monsters[0]->player.health = 50;
    //main loop 
    while(1){
        

        //parse input from sdl event, needs own function
        switch(get_input()){
            case 0:
                cleanup();
                return 0;
                break;
                
            case 2:
                move_piece(current_room->monsters[0], MVUP);
                add_message_queue("You Moved Up");
                break;
                
            case 3:
                move_piece(current_room->monsters[0], MVDOWN);
                add_message_queue("You Moved Down");
                break;
                
            case 5:
                move_piece(current_room->monsters[0], MVRIGHT);
                add_message_queue("You Moved Right");
                break;
                
            case 4:
                move_piece(current_room->monsters[0], MVLEFT);
                add_message_queue("You Moved Left");
                break;
        }
        
        render_all();
        //hold up a sec to not hog the cpu
        SDL_Delay(5);
    }
    
    
    cleanup();
    
    return 0;
}

