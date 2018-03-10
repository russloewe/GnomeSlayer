/* author: russ loewe
 * date:   9 mar 2018
 * file:   
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
#include "./headers/checker.h"


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
     * test player_on_item checker, and get item type
     */
     printf("Testing checker->player_on_item  ");
     
     room room1 = {.walls = {NULL}}; //init walls array to null pointers
     
     room1.monsters[0] = create_piece(5, 5, NULL, PLAYER_TYPE); // add player to (5,5)
     room1.bounty[0] = create_piece(5, 5, NULL, SWORD_TYPE);
     room1.bounty[1] = create_piece(6, 6, NULL, POTION_TYPE);
     room1.bounty[2] = create_piece(6, 5, NULL, SHIELD_TYPE);
     room1.bounty[3] = create_piece(5, 6, NULL, SWORD_TYPE);
     
     if( player_on_item(&room1) != SWORD_TYPE){
         printf("Fail 1\n");
         return -1;
     }
     room1.monsters[0]->x = 6;
     room1.monsters[0]->y = 6;
     if(player_on_item(&room1) != POTION_TYPE){
         printf("Fail 2\n");
         return -1;
     }
     room1.monsters[0]->x = 10;
     room1.monsters[0]->y = 10;
     if(player_on_item(&room1) != PLAYER_TYPE){
         printf("Fail 3\n");
         return -1;
     }
     
     printf("Pass \n");
     return 1;
 }


int test2(){
    /*
     * test is_player_dead function
     */
     printf("Testing  checker->is_player_dead ");
     
     gamepiece * piece1 = create_piece(5, 5, NULL, PLAYER_TYPE);
     gamepiece * piece2 = create_piece(5, 5, NULL, MONSTER_TYPE);
     gamepiece * piece3 = create_piece(5, 5, NULL, SWORD_TYPE);
     
     piece1->player.health = 50;
     piece2->player.health = 50;
     
     if(is_player_dead(piece1) != 0){
         printf("Fail 1\n");
         return -1;
     }
      if(is_player_dead(piece2) != 0){
         printf("Fail 2\n");
         return -1;
     }
     
     piece1->player.health = 0;
     piece2->player.health = 0;
     
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
    
