/* author: russ loewe
 * date:   9 mar 2018
 * file:   
 * Purpose:
 *         This file contains all of the ai_tests to run in this suit.
 *         each of these ai_tests needs to  have their function name put 
 *         in the function pointer array of ai_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"
#include "./headers/checker.h"
#include "./headers/ai.h"

int run_ai_tests();
int cleanai_test();
int ai_test1();
int ai_test2();
int ai_test3();
int ai_test4();
int ai_test5();
int ai_test6();
int ai_test7();

//internal ai prototype
int move_monster_random(gamepiece * monster);



int run_ai_tests(){
    printf("running Checker ai_tests now\n");
    printf("**********************************************\n");
    
    int (*ai_test_suit[])() = {ai_test1, 
                                    cleanai_test};                      //array of all ai_tests to run - cleanai_test must be at the end of this array
    const int ai_test_len = sizeof(ai_test_suit) / sizeof(ai_test_suit[0]);  //variable to tell ai_test runner how many ai_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < ai_test_len; i++){
        int response;
        
        response = ai_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last ai_test is supposed to return 0 to indicate ai_tests are done
                printf("Finished Runnig all ai_tests. Success: %i\n", success);
                printf("                                   Failure: %i\n", failure);
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
    printf("Error: ai_test.c -> run_ai_tests() -> not cleanup at end\n");
    return 1;
}
/***************************** Begin ai_test Functions ********************/
int cleanai_test(){
    printf("cleaning up ai_tests\n");
    return 0;
}

int ai_test1(){
    /*
     * test random move
     */
     printf("ai_testing move_monster_rand():");
     
     gamepiece * monster = create_piece(5, 5, "monster", 1, MONSTER_TYPE);
     
     for(int i = 0; i < 100; i++){
         move_monster_random(monster);
     }
     if( (get_piece_x(monster) == 5) && (get_piece_x(monster) == 5) ){
         printf("Fail 1 \n");
         return -1;
     }    
   
     printf("Pass \n");
     return 1;
 }


int ai_test2(){
    /*
     * 
     */
     printf("ai_testing   ");
     
     
     printf("Pass \n");
   return 1;
}

    
int ai_test3(){
    /*
     * 
     */
     printf("ai_testing   ");
    
     
    
     
     printf("Pass\n");
   return 1;
}
    
int ai_test4(){
    /*
     * 
     */
     printf("ai_testing   ");
   return 1;
}

int ai_test5(){
    /*
     * 
     */
     printf("ai_testing   ");
   return 1;
}

int ai_test6(){
      /*
     * 
     */
     printf("ai_testing   ");
   return 1;
}
    
