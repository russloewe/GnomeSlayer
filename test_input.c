/* author: russ loewe
 * date:   20 feb 2018
 * file:   input_test_suit.c
 * Purpose:
 *         This file contains all of the input_tests to run in this suit.
 *         each of these input_tests needs to  have their function name put 
 *         in the function pointer array of input_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"
#include "./headers/input.h"


int run_input_tests();
int cleaninput_test();
int input_test1();
int input_test2();
int input_test3();
int input_test4();
int input_test5();
int input_test6();
int input_test7();




int run_input_tests(){
    printf("running input_tests now\n");
    printf("**********************************************\n");
    int (*input_test_suit[])() = {input_test1,
                                  cleaninput_test};                      //array of all input_tests to run - cleaninput_test must be at the end of this array
    const int input_test_len = sizeof(input_test_suit) / sizeof(input_test_suit[0]);  //variable to tell input_test runner how many input_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < input_test_len; i++){
        int response;
        
        response = input_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last input_test is supposed to return 0 to indicate input_tests are done
                printf("Finished Runnig all input_tests. Success: %i\n", success);
                printf("                                 Failure: %i\n", failure);
                printf("**********************************************\n");
                return (success*1000) + failure;
            
            case 1:
                success++;
                break;
            
            default:
                failure++;
                break;
        }
    }
    printf("Error: input_test.c -> run_input_tests() -> not cleanup at end\n");
    printf("**********************************************\n");
    return 1;
}
/***************************** Begin input_test Functions ********************/
int cleaninput_test(){
    printf("cleaning up input_tests\n");
    return 0;
}

int input_test1(){
    /*
     * 
     */
     printf("input_testing   ");
   return 1;
}

int input_test2(){
    /*
     * 
     */
     printf("input_testing   ");
   return 1;
}

    
int input_test3(){
    /*
     * 
     */
     printf("input_testing   ");
   return 1;
}
    
int input_test4(){
    /*
     * 
     */
     printf("input_testing   ");
   return 1;
}

int input_test5(){
    /*
     * 
     */
     printf("input_testing   ");
   return 1;
}

int input_test6(){
      /*
     * 
     */
     printf("input_testing   ");
   return 1;
}
    
