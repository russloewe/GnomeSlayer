/* author: russ loewe
 * date:   9 mar 2018
 * file:   
 * Purpose:
 *         This file contains all of the checker_tests to run in this suit.
 *         each of these checker_tests needs to  have their function name put 
 *         in the function pointer array of checker_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"
#include "./headers/checker.h"


int run_checker_tests();
int cleanchecker_test();
int checker_test1();
int checker_test2();
int checker_test3();
int checker_test4();
int checker_test5();
int checker_test6();
int checker_test7();





int run_checker_tests(){
    printf("running Checker checker_tests now\n");
    printf("**********************************************\n");
    
    int (*checker_test_suit[])() = {checker_test1, checker_test2, 
                                    cleanchecker_test};                      //array of all checker_tests to run - cleanchecker_test must be at the end of this array
    const int checker_test_len = sizeof(checker_test_suit) / sizeof(checker_test_suit[0]);  //variable to tell checker_test runner how many checker_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < checker_test_len; i++){
        int response;
        
        response = checker_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last checker_test is supposed to return 0 to indicate checker_tests are done
                printf("Finished Runnig all checker_tests. Success: %i\n", success);
                printf("                                   Failure: %i\n", failure);
                printf("**********************************************\n");
                return 0;
            
            case 1:
                success++;
                break;
            
            default:
                failure++;
                break;
        }
    }
    printf("Error: checker_test.c -> run_checker_tests() -> not cleanup at end\n");
    return 1;
}
/***************************** Begin checker_test Functions ********************/
int cleanchecker_test(){
    printf("cleaning up checker_tests\n");
    return 0;
}

int checker_test1(){
    /*
     * checker_test player_on_item checker, and get item type
     */
     printf("checker_testing checker->player_on_item  ");
     
     room room1 = {.walls = {NULL}}; //init walls array to null pointers
     set_current_room(&room1);
     
     room1.monsters[0] = create_piece(5, 5, "player", 100, PLAYER_TYPE); // add player to (5,5)
     room1.bounty[0] = create_piece(5, 5, "sword", 22, SWORD_TYPE);
     room1.bounty[1] = create_piece(6, 6, "potion", 12, POTION_TYPE);
     room1.bounty[2] = create_piece(6, 5, "sdf", 23, SHIELD_TYPE);
     room1.bounty[3] = create_piece(5, 6, "234e", 23, SWORD_TYPE);
     
     int  temp_item;
     temp_item = player_on_item(&room1);
     
     if(temp_item != 1){
         printf("Fail 1\n");
         return -1;
     }

     room1.monsters[0]->x = 6;
     room1.monsters[0]->y = 6;
     temp_item = player_on_item();
     
      if(temp_item != 1){
         printf("Fail 2\n");
         return -1;
     }
          
     room1.monsters[0]->x = 10;
     room1.monsters[0]->y = 10;
     temp_item = player_on_item();
     
     if(temp_item != 0){
         printf("Fail 3\n");
         return -1;
     }
     
     printf("Pass \n");
     return 1;
 }


int checker_test2(){
    /*
     * checker_test is_player_dead function
     */
     printf("checker_testing  checker->is_player_dead ");
     
     gamepiece * piece1 = create_piece(5, 5, "ert", 34, PLAYER_TYPE);
     gamepiece * piece2 = create_piece(5, 5, "sg", 45,  MONSTER_TYPE);
     gamepiece * piece3 = create_piece(5, 5, "asdf", 34, SWORD_TYPE);
     
     set_player_health(piece1, 50);
     set_player_health(piece2, 50);
     
     if(is_player_dead(piece1) != 0){
         printf("Fail 1\n");
         return -1;
     }
      if(is_player_dead(piece2) != 0){
         printf("Fail 2\n");
         return -1;
     }
     
     set_player_health(piece1, 0);
     set_player_health(piece2, 0);
     
    if(is_player_dead(piece1) != 1){
         printf("Fail 3\n");
         return -1;
     }
    if(is_player_dead(piece2) != 1){
         printf("Fail 4\n");
         return -1;
     }
     
     if(is_player_dead(piece3) != 1){
         printf("Fail 5\n");
         return -1;
     }
     printf("Pass \n");
   return 1;
}

    
int checker_test3(){
    /*
     * 
     */
     printf("checker_testing   ");
   return 1;
}
    
int checker_test4(){
    /*
     * 
     */
     printf("checker_testing   ");
   return 1;
}

int checker_test5(){
    /*
     * 
     */
     printf("checker_testing   ");
   return 1;
}

int checker_test6(){
      /*
     * 
     */
     printf("checker_testing   ");
   return 1;
}
    
