/* author: russ loewe
 * date:   20 feb 2018
 * file:   test_suit.c
 * Purpose:
 *         This file contains all of the tests to run in this suit.
 *         each of these tests needs to be prototyped in the header
 *         and have their function name put in the function pointer
 *         array of tests.
 */
#include "./headers/test_suit.h"

int (*test_suit[])() = {test1, test2, test3, test4, test5, cleantest};                   //cleantest must be at the end of this array
const int test_len = sizeof(test_suit) / sizeof(test_suit[0]);      //global variable to tell test runner how many tests there are

int cleantest(){
    printf("cleaning up tests\n");
    cleanup();
    return 0;
}

int test1(){
    printf("testing init.c->init_video() - ");
    if(init_video() != 0 ){
        printf("Fail\n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}

int test2(){
    printf("Testing display.c->Load_image() - ");
    
    if(load_image("./img/player.bmp") == NULL){
        printf("Failed\n");
        SDL_GetError();
        return -1;
    }else{
        printf("Pass\n");
    }
    return 1;
}

int test3(){
    printf("Testing gameobjects.c -> createpiece() - ");
    
    gamepiece * player;
    SDL_Surface * img;
    
    img = load_image("./img/player.bmp");
    
    player = create_piece(50, 50, img, PLAYER_TYPE);
    
    if( player->type != PLAYER_TYPE ){
        printf("Failed 1\n");
        return -1;
    }else if( player->rect->x != 50 ){
        printf("Failed 2\n");
        return -1;
    }else if(player->img == NULL){
        printf("Failed 3\n");
        return -1;
    }else {
        printf("Pass \n");
        return 1;
    }
    
}


int test4(){
    printf("Testing display.c->render_objects - ");
    
    gamepiece * player;
    SDL_Surface * img;
    
    img = load_image("./img/player.bmp");
    player = create_piece(50, 50, img, PLAYER_TYPE);

    gamepiece * objects[] = {player};
    
    if(render_objects(objects) != 0){
        printf("Failed\n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}

int test5(){
    printf("Testing gameobjects.c -> move_piece() - ");
    
    gamepiece * player;
    SDL_Surface * img;
    
    img = load_image("./img/player.bmp");
    player = create_piece(50, 50, img, PLAYER_TYPE);
    
    move_piece(player, MVUP);
    move_piece(player, MVLEFT);
    
    if(player->rect->y != 49){
        printf("Fail 1\n");
        return -1;
    }else if(player->rect->x != 49){
        printf("Fail 2\n");
        return -1;
    }
    
    move_piece(player, MVDOWN);
    move_piece(player, MVRIGHT);
    move_piece(player, MVDOWN);
    move_piece(player, MVRIGHT);
    
    if(player->rect->y != 51){
        printf("Fail 1\n");
        return -1;
    }else if(player->rect->x != 51){
        printf("Fail 2\n");
        return -1;
    }
    
    printf("Pass\n");
    return 1;
}
    
