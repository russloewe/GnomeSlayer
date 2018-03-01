/* author: russ loewe
 * date:   20 feb 2018
 * file:   test_suit.c
 * Purpose:
 *         This file contains all of the tests to run in this suit.
 *         each of these tests needs to  have their function name put 
 *         in the function pointer array of tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/graphics.h"
#define GAMESQUARE 16

int run_tests();
int cleantest();
int test1();
int test2();
int test3();
int test4();
int test5();
int test6();
int test7();



int main(void){
    
    printf("running tests now\n");
    run_tests();
    
    return 0;
}

int run_tests(){
    
    int (*test_suit[])() = {test1, test2, 
                            test3, test4, cleantest};                      //array of all tests to run - cleantest must be at the end of this array
    const int test_len = sizeof(test_suit) / sizeof(test_suit[0]);  //variable to tell test runner how many tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < test_len; i++){
        int response;
        
        response = test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last test is supposed to return 0 to indicate tests are done
                printf("Finished Runnig all tests. Success: %i\n", success);
                printf("                           Failure: %i\n", failure);
                return 0;
            
            case 1:
                success++;
                break;
            
            default:
                failure++;
                break;
        }
    }
    printf("Error: test.c -> run_tests() -> not cleanup at end\n");
    return 1;
}
/***************************** Begin Test Functions ********************/
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
    printf("Testing display->render_background() - ");
    if(render_background() == 1){
        printf("Fail \n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}
    
int test4(){
    /*Check if the function that renders a colored square works */
    printf("Testing display->make_colored_texture(): ");
    
    SDL_Texture * blank_square;
    
    blank_square = make_colored_texture(16, 16, 255, 255, 255);
    
    if(blank_square == NULL){
        printf("Fail 1\n");
        return -1;
    }
    
    return 1;
}

