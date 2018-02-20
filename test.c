/*
 * author    : russ loewe
 * date      : 20 feb 2018
 * file      : test.c
 * purpose:
 *          This is the entry point for the unit testing. This calls all
 *          the test functions defined in test_suit.h .
 *          To invoke the test, run
 * 
 *               make test
 * 
 *          This is compile all of the included source files except main.c
 *          with the testing code. Main in test.c will replace main.c.
 *          The exceutable 'test' will be made. 
 * 
 *          build and then run the test automaically:
 * 
 *              make runtest
 * 
 *          build test, upload it to the PCC linux server, then run the
 *          test remotly, displying result on local terminal
 * 
 *              make uptest
 * 
 *          Good idea to run clean with all of these test commands
 * 
 *              make clean uptest
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "./headers/init.h"
#include "./headers/input.h"

extern int (*test_suit[])();   //array of function points to he tests
extern const int test_len;     //number of tests in the array
int run_tests();


int main(){
    
    printf("running tests now\n");
    run_tests();
    
    return 0;
}

int run_tests(){
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < test_len; i++){
        int response;
        
        response = test_suit[i]();
        
        switch(response){
            
            case 0:
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
