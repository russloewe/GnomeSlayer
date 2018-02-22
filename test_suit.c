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
#define GAMESQUARE 16

int (*test_suit[])() = {test1, test2, test3, test4, test5, test6, test7, cleantest};                   //cleantest must be at the end of this array
const int test_len = sizeof(test_suit) / sizeof(test_suit[0]);      //global variable to tell test runner how many tests there are

int cleantest(){
    printf("cleaning up tests\n");
    cleanup();
    return 0;
}

int test1(){
    /*
     * Check that the graphics will initalize
     */
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
    /*
     * Check that we can open one of the images
     * Later I'll probably have it loop though all images for 
     * the game
     */
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
    /*
     * Test if game piece is correctly initialized 
     * a gamepiece can have a null pointer for img, it means it doesn't 
     * have an associated image
     */
    printf("Testing gameobjects.c -> createpiece() - ");
    
    gamepiece * player;

    player = create_piece(50, 50, load_image("./img/player.bmp"), PLAYER_TYPE);
    
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
    /*
     * create a couple of test pieces and see if the object renderer handles them
     * also make sure bad file name and missing image don't jam it up
     */
    printf("Testing display.c->render_objects - (this error message is expected for this test -->)");
    
    gamepiece * player;
    gamepiece * player2;
    gamepiece * player3;
    
    player = create_piece(50, 50, load_image("./img/player.bmp"), PLAYER_TYPE);
    player2 = create_piece(50, 50, load_image("badfilename"), PLAYER_TYPE); //make sure it handle bad filename
    player2 = create_piece(50, 50, NULL, PLAYER_TYPE); //no img

    gamepiece * objects[10] = {NULL};  // init array of null pointers
    objects[0] = player;               //add player to array
    objects[0] = player2;               //add player to array
    
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

    player = create_piece(50, 50, load_image("./img/player.bmp"), PLAYER_TYPE);
    
    move_piece(player, MVUP);
    move_piece(player, MVLEFT);
    
    if(player->rect->y != (50 - GAMESQUARE) ){
        printf("Fail 1\n");
        return -1;
    }else if(player->rect->x != (50 - GAMESQUARE) ){
        printf("Fail 2\n");
        return -1;
    }
    
    move_piece(player, MVDOWN);
    move_piece(player, MVRIGHT);
    move_piece(player, MVDOWN);
    move_piece(player, MVRIGHT);
    
    if(player->rect->y != (50 + GAMESQUARE)){
        printf("Fail 1\n");
        return -1;
    }else if(player->rect->x != (50 + GAMESQUARE)){
        printf("Fail 2\n");
        return -1;
    }
    
    printf("Pass\n");
    return 1;
}

int test6(){
    printf("Testing gameobjects -> destroy_piece() - ");
    
    gamepiece * player;
    
    player = create_piece(50, 50, load_image("./img/player.bmp"), PLAYER_TYPE);
    
    destroy_piece(player);
    
    printf("Pass \n");    
    return 1;
}
    
int test7(){
    printf("Testing display->render_background() - ");
    if(render_background() == 1){
        printf("Fail \n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}

