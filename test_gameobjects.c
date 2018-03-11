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
     printf("Testing gameobjects->create_piece()  ");
     
     piece1 = create_piece(5, 5, NULL, PLAYER_TYPE);
     piece2 = create_piece(5, 5, NULL, SWORD_TYPE);
     
     if((piece1 == NULL) || (piece2 == NULL)){
         printf("Fail 1\n");
         return -1;
     }
     printf("Pass \n");
   return 1;
}

int test2(){
    /*
     * test move piece
     */
     printf("Testing  gameobjects->move_piece() ");
     
     move_piece(piece1, MVRIGHT);
     move_piece(piece1, MVUP);
     
     if( (get_piece_x(piece1) != 6 ) || (get_piece_y(piece1) != 4)){
         printf("Fail 1\n");
         return -1;
     }
     
     move_piece(piece2, MVLEFT);
     move_piece(piece2, MVDOWN);
     
    if( (get_piece_x(piece2) != 4 ) || (get_piece_y(piece2) != 6)){
         printf("Fail 2\n");
         return -1;
     }
     
     printf("Pass \n");
   return 1;
}

    
int test3(){
    /*
     * test get gamepiece stats
     */
     printf("Testing  gameobjects->(various stats) ");
     
     set_piece_health(piece1, 50);
     
     if(get_piece_health(piece1) != 50){
         printf("Fail 1\n");
         return -1;
     }
     if(get_piece_health(piece2) != -1){
         printf("Fail 2 \n");
         return -1;
     }
     
     printf("Pass \n");
     
   return 1;
}
    
int test4(){
    /*
     * test getting shield or sword
     */
     printf("Testing  gameobjects->get_player_shield/sword() ");
     gamepiece * sword;
     gamepiece * shield;
     piece1->player.sword.val = 10;
     piece1->player.shield.val = 11;
     
     sword = get_player_sword(piece1);
     shield = get_player_shield(piece1);
     
     if( (sword == NULL) || (shield == NULL)){
         printf("Fail 1\n");
         return -1;
     }
     if( (sword->item.val != 10) || (shield->item.val != 11) ){
         printf("Fail\n");
         return -1;
     }
    printf("Pass \n");
   return 1;
}

int test5(){
    /*
     * test equip item to player
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
    
