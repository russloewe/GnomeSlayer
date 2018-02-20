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

int test1(){
    printf("testing init_video() - ");
    if(init_video() != 0 ){
        printf("Fail\n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}

int test2(){
    
    return 1;
}

int cleantest(){
    printf("cleaning up tests\n");
    cleanup();
    return 0;
}

