/* author: russ loewe
 * date:   20 feb 2018
 * file:   obj_test_suit.c
 * Purpose:
 *         This file contains all of the obj_tests to run in this suit.
 *         each of these obj_tests needs to  have their function name put 
 *         in the function pointer array of obj_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"


int run_obj_tests();
int cleanobj_test();
int obj_test1();
int obj_test2();
int obj_test3();
int obj_test4();
int obj_test5();
int obj_test6();
int obj_test7();

gamepiece * piece1;
gamepiece * piece2;



int run_obj_tests(){
    printf("running GameObject obj_tests now\n");
    printf("**********************************************\n");
    int (*obj_test_suit[])() = {obj_test1, obj_test2, 
                                obj_test3, obj_test4, 
                            cleanobj_test};                      //array of all obj_tests to run - cleanobj_test must be at the end of this array
    const int obj_test_len = sizeof(obj_test_suit) / sizeof(obj_test_suit[0]);  //variable to tell obj_test runner how many obj_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < obj_test_len; i++){
        int response;
        
        response = obj_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last obj_test is supposed to return 0 to indicate obj_tests are done
                printf("Finished Runnig all obj_tests. Success: %i\n", success);
                printf("                               Failure: %i\n", failure);
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
    printf("Error: obj_test.c -> run_obj_tests() -> not cleanup at end\n");
    printf("**********************************************\n");
    return 1;
}
/***************************** Begin obj_test Functions ********************/
int cleanobj_test(){
    printf("cleaning up obj_tests\n");
    return 0;
}

int obj_test1(){
    /*
     * obj_test create game piece and init the two obj_test pieces
     */
     printf("obj_testing gameobjects->create_piece()  ");
     
     piece1 = create_piece(5, 5, PLAYER_TYPE);
     piece2 = create_piece(5, 5, SWORD_TYPE);
     
     if((piece1 == NULL) || (piece2 == NULL)){
         printf("Fail 1\n");
         return -1;
     }
     printf("Pass \n");
   return 1;
}

int obj_test2(){
    /*
     * obj_test move piece
     */
     printf("obj_testing  gameobjects->move_piece() ");
     
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

    
int obj_test3(){
    /*
     * obj_test get gamepiece stats
     */
     printf("obj_testing  gameobjects->(various stats) ");
     
     //HEALTH
     if(set_player_health(piece1, 50) != 0){
         printf("Fail .5\n");
         return -1;
     }
     
     if(get_piece_val(piece1) != 50){
         printf("Fail 1\n");
         return -1;
     }
     
     //NAME
     if(set_piece_name(piece1, "name") != 0){
         printf("Fail 3\n");
         return -1;
     }
      if(set_piece_name(piece2, "name2") != 0){
         printf("Fail 4\n");
         return -1;
     }
     
     if(strncmp(get_piece_name(piece1), "name", 4) != 0){
         printf("Fail 5\n");
         return -1;
     }
     
      if(strncmp(get_piece_name(piece2), "name2", 5) != 0){
         printf("Fail 6\n");
         return -1;
     }
     
     //VAL
     
     if(set_piece_val(piece2, 25) != 0){
         printf("Fail 7\n");
         return -1;
     }
     
     if(get_piece_val(piece2) != 25){
         printf("Fail 8\n");
         return -1;
     }
     printf("Pass \n");
     
   return 1;
}
    
int obj_test4(){
    /*
     * obj_test getting shield or sword
     */
     printf("obj_testing  gameobjects->get_player_shield/sword() ");
     //create sword and shield
     gamepiece * sword = create_piece(5, 5,  SWORD_TYPE);
     gamepiece * shield = create_piece(5, 5,  SHIELD_TYPE);
     set_piece_name(sword, "Big Sword");
     set_piece_val(sword, 100);
     set_piece_name(shield, "Big Shield");
     set_piece_val(shield, 35);
     
     //equipe sword and shield to piece1
     if( (equip_item_to_player(piece1, sword) != NULL) ||
         (equip_item_to_player(piece1, shield) != NULL) ){
         printf("Fail 1\n:");
         return -1;
     }
     
     if( (get_piece_val(get_player_sword(piece1)) != 100) ||
         (get_piece_val(get_player_shield(piece1)) != 35)) {
        printf
        ("Fail 2\n");
        return -1;
    }

    printf("Pass \n");
   return 1;
}

int obj_test5(){
    /*
     * obj_test equip item to player
     */
     printf("obj_testing   ");
   return 1;
}

int obj_test6(){
      /*
     * 
     */
     printf("obj_testing   ");
   return 1;
}
    
