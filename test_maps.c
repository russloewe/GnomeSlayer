/* author: russ loewe
 * date:   20 feb 2018
 * file:   maps_test_suit.c
 * Purpose:
 *         This file contains all of the maps_tests to run in this suit.
 *         each of these maps_tests needs to  have their function name put 
 *         in the function pointer array of maps_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"


int run_maps_tests();
int cleanmaps_test();
int maps_test1();
int maps_test2();
int maps_test3();
int maps_test4();
int maps_test5();
int maps_test6();
int maps_test7();


int run_maps_tests(){
        printf("running maps_tests now\n");
    printf("**********************************************\n");
    int (*maps_test_suit[])() = {maps_test1,
                            cleanmaps_test};                      //array of all maps_tests to run - cleanmaps_test must be at the end of this array
    const int maps_test_len = sizeof(maps_test_suit) / sizeof(maps_test_suit[0]);  //variable to tell maps_test runner how many maps_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < maps_test_len; i++){
        int response;
        
        response = maps_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last maps_test is supposed to return 0 to indicate maps_tests are done
                printf("Finished Runnig all maps_tests. Success: %i\n", success);
                printf("                                Failure: %i\n", failure);
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
    printf("Error: maps_test.c -> run_maps_tests() -> not cleanup at end\n");
    printf("**********************************************\n");
    return 1;
}
/***************************** Begin maps_test Functions ********************/
int cleanmaps_test(){
    printf("cleaning up maps_tests\n");
    return 0;
}

int maps_test1(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}

int maps_test2(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}

    
int maps_test3(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}
    
int maps_test4(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}

int maps_test5(){
    /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}

int maps_test6(){
      /*
     * 
     */
     printf("maps_testing   ");
   return 1;
}
    
