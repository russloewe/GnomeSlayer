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

int (*test_suit[])() = {test1, test2, cleantest};                   //cleantest must be at the end of this array
const int test_len = sizeof(test_suit) / sizeof(test_suit[0]);      //global variable to tell test runner how many tests there are

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
    
    SDL_Surface* image = NULL;
    if(load_image("./img/player.bmp") == NULL){
        printf("Failed\n");
        SDL_GetError();
        return -1;
    }else{
        printf("Pass\n");
        SDL_FreeSurface(image);  //only free if load_image is successful or segfault
    }
    return 1;
}

int cleantest(){
    printf("cleaning up tests\n");
    cleanup();
    return 0;
}

