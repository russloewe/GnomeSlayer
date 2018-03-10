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
#include "./headers/gameobjects.h"
#include "./headers/maps.h"


int run_tests();
int cleantest();
int test1();
int test2();
int test3();
int test4();
int test5();
int test6();
int test7();

gamepiece * piece1;
gamepiece * piece2;

int main(void){
    
    printf("running tests now\n");
    run_tests();
    
    return 0;
}

int run_tests(){
    
    int (*test_suit[])() = {test1, test2, 
                            test3, test4, 
                            test5, test6,
                            cleantest};                      //array of all tests to run - cleantest must be at the end of this array
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
    return 0;
}

int test1(){
    /*
     * test create game piece and init the two test pieces
     */
     printf("Testing gameobjects->creat_piece()  ");
     
     piece1 = create_piece(5, 5, NULL, PLAYER_TYPE);
     piece2 = create_piece(5, 5, NULL, SWORD_TYPE);
     
     if((piece1 == NULL) || (piece2 == NULL)){
         printf("Fail 1\n");
         return -1;
     }
     
   return 1;
}

int test2(){
    /*
     * 
     */
     printf("Testing   ");
   return 1;
}

    
int test3(){
    /*
     * 
     */
     printf("Testing   ");
   return 1;
}
    
int test4(){
    /*
     * 
     */
     printf("Testing   ");
   return 1;
}

int test5(){
    /*
     * 
     */
     printf("Testing   ");
   return 1;
}

int test6(){
      /*
     * 
     */
     printf("Testing   ");
   return 1;
}
    
