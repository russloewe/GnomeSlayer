/* author: russ loewe
 * date:   20 feb 2018
 * file:   graph_test_suit.c
 * Purpose:
 *         This file contains all of the graph_tests to run in this suit.
 *         each of these graph_tests needs to  have their function name put 
 *         in the function pointer array of graph_tests.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "./headers/graphics.h"
#include "./headers/gameobjects.h"
#include "./headers/maps.h"

/**********Internal functions and data structures from graphics.c*****/
//internal data structures
struct Textline{
    char text[40];
    struct Textline * nxt;
};
typedef struct Textline Textline;

//function prototypes for internal functions
SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[], int range);
SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green);
int render_background();
int render_background_image(SDL_Texture * img);
int render_room(room * cur_room);
SDL_Rect get_char_rect(char c);
int trim_message_queue(int n);
int render_player_stats(room * curroom);
int render_message_queue(int lines, int x, int y);
Textline * get_message_queue();

/***************End of internal functions and data structures*******/

int run_graph_tests();
int cleangraph_test();
int graph_test1();
int graph_test2();
int graph_test3();
int graph_test4();
int graph_test5();
int graph_test6();
int graph_test7();
int graph_test8();
int graph_test9();
int graph_test10();
int graph_test11();
int graph_test12();



int graph_test_graphics(void){
    
    printf("running Graphics graph_tests now\n");
    printf("*****************************\n");
    run_graph_tests();
    printf("*****************************\n");
    return 0;
}

int run_graph_tests(){
    printf("running Graphics graph_tests now\n");
    printf("**********************************************\n");
    int (*graph_test_suit[])() = {graph_test1,  graph_test2,  graph_test3,  graph_test4, 
                                  graph_test5,  graph_test6,  graph_test7,  graph_test8,
                                  graph_test9,  graph_test10, graph_test11, graph_test12, cleangraph_test};                      //array of all graph_tests to run - cleangraph_test must be at the end of this array
    const int graph_test_len = sizeof(graph_test_suit) / sizeof(graph_test_suit[0]);  //variable to tell graph_test runner how many graph_tests there are

    
    int success = 0;
    int failure = 0;
    
    for(int i = 0; i < graph_test_len; i++){
        int response;
        
        response = graph_test_suit[i]();
        
        switch(response){
            
            case 0:
                //Last graph_test is supposed to return 0 to indicate graph_tests are done
                printf("Finished Runnig all graph_tests. Success: %i\n", success);
                printf("                                 Failure: %i\n", failure);
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
    printf("Error: graph_test.c -> run_graph_tests() -> not cleanup at end\n");
    printf("**********************************************\n");
    return 1;
}
/***************************** Begin graph_test Functions ********************/
int cleangraph_test(){
    printf("cleaning up graph_tests\n");
    cleanup();
    return 0;
}

int graph_test1(){
    /*
     * Check that the graphics will initalize
     */
    printf("graph_testing init.c->init_video() - ");
    if(init_video() != 0 ){
        printf("Fail\n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}

int graph_test2(){
    /*
     * Check that we can open one of the images
     * Later I'll probably have it loop though all images for 
     * the game
     */
    printf("graph_testing display.c->Load_image() - ");
    
    if(load_image("./img/player.bmp") == NULL){
        printf("Failed\n");
        SDL_GetError();
        return -1;
    }else{
        printf("Pass\n");
    }
    return 1;
}

    
int graph_test3(){
    printf("graph_testing display->render_background() - ");
    if(render_background() == 1){
        printf("Fail \n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}
    
int graph_test4(){
    /*Check if the function that renders a colored square works */
    printf("graph_testing display->make_colored_texture(): ");
    
    SDL_Texture * blank_square;
    
    blank_square = make_colored_texture(16, 16, 255, 255, 255);
    
    if(blank_square == NULL){
        printf("Fail 1\n");
        return -1;
    }
    printf("Pass \n");
    return 1;
}

int graph_test5(){
    /*graph_test the render objects function
     */
     printf("graph_testing graphics->render_objects(): ");
    gamepiece * player;
    player = create_piece(50, 50, "player1", 100, PLAYER_TYPE);
    gamepiece * objects[10] = {NULL};
    objects[0] = player;
    
    render_objects(objects, 10);
    printf("Pass\n");
    
    return 1;
}

int graph_test6(){
    /*
     * graph_test the room renderer
     */
     
     printf("graph_testing graphics->room_render() ");
        /***********temp room hack***************/
        room room1 = {.walls = {NULL}}; //init walls array to null pointers
        set_current_room(&room1);
        room * current_room = &room1;          //set current room pointer to room1
        
        //make some walls
        for(int i = 0; i < 40; i++){
            room1.walls[i] = create_piece(i, 0, "wall", 1, WALL_TYPE);;
        }
        for(int i = 0; i < 17; i++){        
            room1.walls[i+50] = create_piece(0, i, "wall", 1, WALL_TYPE);
        }
        for(int i = 0; i < 40; i++){
            room1.walls[i+100] = create_piece(i, 17, "wall", 1, WALL_TYPE);
        }
        for(int i = 0; i < 17; i++){
            room1.walls[i+150] = create_piece(39, i, "wall", 1, WALL_TYPE);
        }
        
        
        //spawn some monsters
        for(int i = 0; i<5; i++){
            room1.monsters[i] = create_piece(rand()%38+2, rand()%15+2, "monster", 100, MONSTER_TYPE);
        }
        //add some items 
        room1.bounty[0] = create_piece(rand()%38+2, rand()%15+2, "potion", 40, POTION_TYPE);
       
        //make 2 swords
        room1.bounty[1] = create_piece(rand()%38+2, rand()%15+2, "Big Sword", 25, SWORD_TYPE);
        room1.bounty[2] = create_piece(rand()%38+2, rand()%15+2, "Big Dagger", 25,  SWORD_TYPE);
        
        //make two shields
        room1.bounty[3] = create_piece(rand()%38+2, rand()%15+2, "Iron Shield", 20, SHIELD_TYPE);
        room1.bounty[4] = create_piece(rand()%38+2, rand()%15+2, "Bronze Shield", 40, SHIELD_TYPE);
       
        //add the two doors;
        room1.doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
        room1.doors[1] = create_piece(39, 5, "door", 1, DOOR_TYPE);
        
    /******************end temp room hack**********/
    if( render_room(&room1) != 0){
        printf("Fail 2\n");
        return -1;
    }else{
        printf("Pass\n");
        return 1;
    }
}
    
int graph_test7(){
    /*
     * graph_testing the text string render function
     */
    printf("graph_testing graphics->render_text_line(): ");
    
    char * text = "hello";
    
    if(render_text_line(text, 2, 20) != 0){
        printf("Fail \n");
        return -1;
    }    
    printf("Pass \n");
    return 1;
}

int graph_test8(){
    /*
     * graph_test adding text to the message queue
     */
     printf("graph_testing graphics->add_message_queue(): ");
     

   //add three messages to the message queue
    if(add_message_queue("Hddtt234 234$%^&(*&^%$") != 0){
         printf("Fail 3\n");
         return -1;
     }
    if(add_message_queue("graph_test") != 0){
         printf("Fail 2\n");
         return -1;
     }
    if(add_message_queue("hello") != 0){
         printf("Fail 1\n");
         return -1;
     }
     
     Textline * cur = get_message_queue();  //grab the head of the queue
     
     if(strncmp(cur->text, "hello", strlen("hello")) != 0){  //check first message
         printf("Fail 4 \n");
         return -1;
     }
     
     cur = cur->nxt;     //get next message
         
     if( strncmp(cur->text, "graph_test", strlen("graph_test")) != 0){
         printf("Fail 5 \n");
         return -1;
     }
     
     cur = cur->nxt;  //get third message
     
     if( strncmp(cur->text, "Hddtt234 234$%^&(*&^%$", strlen("Hddtt234 234$%^&(*&^%$")) != 0){
         printf("Fail 6 \n");
         return -1;
     }
     
     printf("Pass \n");
     return 1;
 }
 
int graph_test9(){
    /*
     * graph_test render message queue
     */
     printf("graph_testing graphics.c->render_message_queue(): ");
     char matrix[5][15];
     strcpy(matrix[0], "hello");
     strcpy(matrix[1], "Tom23");
     strcpy(matrix[2], "graph_test34");
     strcpy(matrix[3], "!@graph_test");
     strcpy(matrix[1], "graph_test graph_test 45");
    
    for(int i = 0; i < 5; i++){
        if( add_message_queue(matrix[i]) != 0){
            printf("Fail 1\n");
            return -1;
        }
    }
    
    if(render_message_queue(5, 10 , 20) != 0){
        printf("Fail 2 \n");
        return -1;
    }
    printf("Pass \n");
    return 1;
}

int graph_test10(){
    /*
     * graph_test trim message queue
     */
     
     printf("graph_testing graphics->trim_message_queue(): ");
     
     add_message_queue("graph_test"); //put at least 1 message in queue
     if(trim_message_queue(0) < 1){   //clear queue
         printf("Fail .5\n");
         return -1;
     }
     if(trim_message_queue(1) != 0){  //make sure queue is empty
         printf("Fail .6\n");
         return -1;
     }
     for(int i = 0 ; i < 20; i++){
         for(int j = 0; j < 20; j++){
             add_message_queue("graph_test message");
         }
         if(trim_message_queue(5) != 14){
             printf("Fail 1\n");
             return -1;
         }
         if(trim_message_queue(6) > 0){
             printf("Fail 2\n");
             return -1;
         }
         if(trim_message_queue(4) > 0){
             printf("Fail 3\n");
             return -1;
         }
         
         //clear queue before loop repeats
         trim_message_queue(0);
     }
     
     
     printf("Pass \n");
     return 1;
 }

int graph_test11(){
    /*
     * graph_test render all function
     */
     printf("graph_testing graphics->render_all() ");
     
           /***********temp room hack***************/
        room room1 = {.walls = {NULL}}; //init walls array to null pointers
        set_current_room(&room1);
        room * current_room = &room1;          //set current room pointer to room1
        
        //make some walls
        for(int i = 0; i < 40; i++){
            room1.walls[i] = create_piece(i, 0, "wall", 1, WALL_TYPE);;
        }
        for(int i = 0; i < 17; i++){        
            room1.walls[i+50] = create_piece(0, i, "wall", 1, WALL_TYPE);
        }
        for(int i = 0; i < 40; i++){
            room1.walls[i+100] = create_piece(i, 17, "wall", 1, WALL_TYPE);
        }
        for(int i = 0; i < 17; i++){
            room1.walls[i+150] = create_piece(39, i, "wall", 1, WALL_TYPE);
        }
        
        
        //spawn some monsters
        for(int i = 0; i<5; i++){
            room1.monsters[i] = create_piece(rand()%38+2, rand()%15+2, "monster", 100, MONSTER_TYPE);
        }
        //add some items 
        room1.bounty[0] = create_piece(rand()%38+2, rand()%15+2, "potion", 40, POTION_TYPE);
       
        //make 2 swords
        room1.bounty[1] = create_piece(rand()%38+2, rand()%15+2, "Big Sword", 25, SWORD_TYPE);
        room1.bounty[2] = create_piece(rand()%38+2, rand()%15+2, "Big Dagger", 25,  SWORD_TYPE);
        
        //make two shields
        room1.bounty[3] = create_piece(rand()%38+2, rand()%15+2, "Iron Shield", 20, SHIELD_TYPE);
        room1.bounty[4] = create_piece(rand()%38+2, rand()%15+2, "Bronze Shield", 40, SHIELD_TYPE);
       
        //add the two doors;
        room1.doors[0] = create_piece(0, 10, "door", 1, DOOR_TYPE);
        room1.doors[1] = create_piece(39, 5, "door", 1, DOOR_TYPE);
        
    /******************end temp room hack**********/

    if (render_all() != 0){
        printf("Fail \n");
        return -1;
    }
    
    printf("Pass \n");
    return 1;
}

int graph_test12(){
    //try to overload message render
    printf("Testing graphics->render_message_queue(stress test) ");
    
    for(int i = 0; i < 200000; i++){
        if( add_message_queue("test mesage") != 0){
            printf("Fail 1\n");
            return -1;
        }
        if(i%1000 == 0){
            if(render_message_queue(5, 10 , 1000) != 0){
                printf("Fail 2 \n");
                return -1;
            }
            trim_message_queue(20);
        }
        
    }
    
    printf("Pass\n");
    return 1;
}

