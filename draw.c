#include "./headers/draw.h"
//internal data structures


struct Textline{
    char text[60];
    struct Textline * nxt;
};
typedef struct Textline Textline;
static int text_line_length = 60;
static Textline * _text_head = NULL;          //message queue

Textline * get_message_queue();


int get_max_x(){
    int width = get_screen_width();
    int square = get_gamesquare();
    int max = (width / square) - 1;
    return max;
}

int get_max_y(){
    int height = get_screen_height();
    int square = get_gamesquare();
    int max = (height / square) - 10;
    return max;
}
int draw_all(){
    /*
     * this function is called by main loop to render the screen.
     * I like this better then having to use extern Main_Renderer
     * in main.c
     */
     room * current_room = get_current_room();
     
     if(current_room == NULL){
         printf("No room context, unable to render \n");
         return 1;
     }
     
    if( render_object(BACKGROUND_ICO, 0, 0, get_screen_width(), get_screen_height()) != 0){
        printf("graphics->render all: Error rendering background image\n");
        return 1;
    }
    if(render_room(current_room) != 0){
        printf("graphics->render_all(): Error rending room\n");
        return 1;
    }
    if(render_message_queue(10, 1, 29) != 0){   //print messages to the screen
        printf("graphics->render_all(): Error rendering message queue\n");
        return 1;
    }
    trim_message_queue(20);
    if(render_player_stats(current_room) != 0){ 
        printf("graphics->render_all(): Error rendering player stats\n");
        return 1;
    }
   render_all();
    return 0;
}
int start_graphics_module(){
   if(init_video() != 0){
        printf("Error loading graphics layer\n");
        return 1;
    }
    if(load_images() != 0){
        printf("Error loading game icons\n");
        return 1;
    }
 
    return 0;
}

int load_images(){
    //load an array of images that are going to be used in game
    if( load_image_to_mem("./img/font2.bmp", FONT_ICO) ||
        load_image_to_mem("./img/background2.bmp", BACKGROUND_ICO) ||
        load_image_to_mem("./img/dialogloose.bmp", DIALOG_ICO_L) ||
        load_image_to_mem("./img/dialogwin.bmp", DIALOG_ICO_W) ||
        load_image_to_mem("./img/wall.bmp",   WALL_ICO )           ||
        load_image_to_mem("./img/door.bmp",   DOOR_ICO )           ||
        load_image_to_mem("./img/sword1.bmp" , SWORD_ICO_1)         ||
        load_image_to_mem("./img/sword2.bmp",  SWORD_ICO_2)         ||
        load_image_to_mem("./img/sword3.bmp",  SWORD_ICO_3 )        ||
        load_image_to_mem("./img/shield1.bmp", SHIELD_ICO_1 )       ||
        load_image_to_mem("./img/shield2.bmp", SHIELD_ICO_2)        ||
        load_image_to_mem("./img/shield3.bmp", SHIELD_ICO_3 )       ||
        load_image_to_mem("./img/potion1.bmp", POTION_ICO_1)        ||
        load_image_to_mem("./img/potion2.bmp", POTION_ICO_2 )       ||
        load_image_to_mem("./img/potion3.bmp", POTION_ICO_3 )       ||
        load_image_to_mem("./img/king.bmp",   KING_ICO )           ||
        load_image_to_mem("./img/monster1.bmp",MONSTER_ICO_1 )      ||
        load_image_to_mem("./img/monster2.bmp",MONSTER_ICO_2)       ||
        load_image_to_mem("./img/monster3.bmp",MONSTER_ICO_3 )      ||
        load_image_to_mem("./img/player1.bmp",PLAYER_ICO_1 )  ){
        return 1;
    }
    
    return 0;
} 
   
int render_objects( gamepiece * pieces[], int range){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     * 
     * ---return 0 on success---
     */
     int x = 0;
     int y = 0;
     int w = get_gamesquare();
     int h = get_gamesquare();
    
    for(int i = 0; i < range; i++){ 
        if(pieces[i] != NULL){
            //set dest rect x,y coords
            x = get_piece_x(pieces[i]) * w; //get rect.x and rect.y with gamepiece interface functions
            y = get_piece_y(pieces[i]) * h; // multiply by 16 to convert from game square to pixel coordinates
            
            //get piece ICON
            Icon icon = get_piece_icon(pieces[i]);
            if(render_object(icon, x, y, w, h) != 0){
                printf("display.c->render_objects()->render_object()\n");
                return 1;
            }
        }
    }
    return 0;
}


int render_room(room * cur_room){
    /*
     * take a pointer to a room and render all of the parts of the room to the screen
     * test return value each time render_objects is called
     */
    if( render_objects(cur_room->walls, 300) != 0){
        printf("graphics.c->render_room(): Error rendering walls\n");
        return 1;
    }
    if( render_objects(cur_room->bounty, 10) != 0){
        printf("graphics.c->render_room(): Error rendering bounty\n");
        return 1;
    }
    if( render_objects(cur_room->doors, 2) != 0){
        printf("graphics.c->render_room(): Error rendering doors\n");
        return 1;
    }
    if( render_objects(cur_room->monsters, 10) != 0){
        printf("graphics.c->render_room(): Error rendering monsters\n");
        return 1;
    }
    return 0;
}

int get_char_rect_x(char c){
    /*
     * take a char and return the rect that represents that letter on the 
     * font bitmap. There is an equation that maps ascii code to (x,y) coordinate 
     * on the bitmap "font1.bmp" that is utilized in this function.
     */
    int ascii = (int)c;          //turn char into ascii code
    int index = ascii - 32;      //this maps ascii code to index of sprite map
    
    int sprite_x = 17 + (index % 10) * 61;     //map ascii index to x offest of sprite map

    return sprite_x;
}

int get_char_rect_y(char c){
    /*
     * take a char and return the rect that represents that letter on the 
     * font bitmap. There is an equation that maps ascii code to (x,y) coordinate 
     * on the bitmap "font1.bmp" that is utilized in this function.
     */
    int ascii = (int)c;          //turn char into ascii code
    int index = ascii - 32;      //this maps ascii code to index of sprite map
    
    int sprite_y = 10 + (index / 10) * 65;     //map ascii index to y offset of sprite map
    
    return sprite_y;
}

Textline * get_message_queue(){
    return _text_head;
}

int add_message_queue(char * string){
    /*
     * take a sting of text and add it to a linked list, add new
     * struct to the end of the list
     */
     
     Textline * newline = (Textline*)malloc(sizeof(Textline));  //put the new node on heap
     if( newline == NULL){
         printf("graphics.c->add_textline(): Error, unable to allocate new tetline\n");
         return 1;
     }
     
     strncpy(newline->text, string, text_line_length); //copy text to new struct
     newline->nxt = NULL;
     
    if(_text_head == NULL){
        _text_head = newline;
    }else{
        newline->nxt = _text_head;   // newline points to first node after head
        _text_head = newline;        // head points to newline
    }    
    return 0;
}

int trim_message_queue(int n){
    //leave the first n nodes in queue, free the rest
    Textline * cur = _text_head;
    
    for(int i = 0; i < n; i++){ //step n steps through linked list
        if(cur == NULL){return 0;}
        if(cur->nxt == NULL){return 0;}
        if(cur->nxt == cur){
            cur->nxt = NULL;
            return 0;
        }
         cur = cur->nxt;
     }
     
     if(cur->nxt == NULL){return 0;} //make sure we aren't on end node before next step
     
     Textline * prv = cur; //prv and cur point to same struct here and when loop repeats
     cur = cur->nxt; // advanced cur pointer
     prv->nxt = NULL;  //make current node end of list before freeing rest of list
     
     int i = 0;                  //count how many structs are freed
     while(1){
         prv = cur;   //
         if(cur == NULL){break;}
         if(prv == NULL){break;}
         if(cur->nxt == NULL){break;}
         if(cur->nxt == cur){break;}
         cur = cur->nxt; // advance cur pointer
         free(prv);     //free prev pointer
         i++;
     }
     return i;
 }
         
int render_message_queue(int line, int x, int y){
    /*
     * render the messages in the queue 
     * line = how many lines to draw from queue
     * x, y = where to start the messages at, messages grow upward
     */
     Textline * cur = _text_head;
     int i = 0;  //counter
     while(( i < line) && (cur != NULL) ){   //stop if end of list or counter max 
         y = y - 1;                          //each iteration, sub from y coordinate, to go upward
         render_text_line(cur->text, x, y);  
         cur = cur->nxt;
         i++;
     }
     return 0;
 }   

int render_player_stats(room * curroom){
    /*
     * Draw the player health and stuff to stat box on screen
     */
    
    char  player_health_text[15];    
    char  player_sword_text[40];
    char  player_shield_text[40];
    gamepiece * player = get_player(); 
    
    //render health
    int health = get_piece_val(player);    
    sprintf(player_health_text, "Health: %d", health);    
    if (render_text_line(player_health_text, 26, 19) != 0){
        printf("graphics->render_player_sats(): Error with render text line\n");
        return 1;
    }
    //render sword
    gamepiece * sword = get_player_sword(player);
    if(sword != NULL){
        char * sword_name = get_piece_name(sword);       //grab item atttributes
        int sword_val = get_piece_val(sword);
        sprintf(player_sword_text, "%s : %d hp",sword_name, sword_val );  //format text
        if (render_text_line(player_sword_text, 26, 20) != 0){
            printf("graphics->render_player_sats(): Error with render text line\n");
            return 1;
        }
    } 
    
    //render shield
    gamepiece * shield = get_player_shield(player);
    if(shield != NULL){
        char * shield_name = get_piece_name(shield);    //grab item attributes
        int shield_val = get_piece_val(shield);
        sprintf(player_shield_text, "%s : %d hp",shield_name, shield_val );  //format text
        if (render_text_line(player_shield_text, 26, 21) != 0){
            printf("graphics->render_player_sats(): Error with render text line\n");
            return 1;
        }
    }     
    
    //render pick up message
    int on_item = player_on_item(curroom);
    if(on_item == 0){
        return 0;
    }else{
        gamepiece * item = grab_item_reference(get_piece_x(player), get_piece_y(player)); //grab pointer to item player is on
        if((get_piece_type(item) == SWORD_TYPE)  ||
           (get_piece_type(item) == SHIELD_TYPE) ||
           (get_piece_type(item) == POTION_TYPE)){
            render_text_line("Press Space Bar to", 26, 27);
            render_text_line("pick up item", 26, 28);
        }
    }
            
    return 0;
}


int render_text_line(char * text, int x_pos, int y_pos){
    /*
     * draw a line of text to string starting at coodrinate x, y
     * renders letters by copying from a bitmap font sheet
     * 
     * ----returns 0 on success-------
     */
     int h_dest = 15;
     int w_dest = 8;
     int x_dest = x_pos * 20;
     int y_dest = y_pos * 20;
     
     int h_src = 50;
     int w_src = 25;
     int x_src;
     int y_src;

    for(int i = 0; (i < strlen(text)) && (i < text_line_length); i++){
        x_src = get_char_rect_x(text[i]);
        y_src = get_char_rect_y(text[i]);
        if( render_letter(FONT_ICO, x_dest, y_dest, w_dest, h_dest, x_src, y_src, w_src, h_src) != 0){
            printf("graphics.c->render_text_line(): Error copying font texture to main renderer\n");
        }
        x_dest = x_dest + 8;  //move over 1 before looping to draw next char
    }  
    
    return 0;
}

int draw_loosing_screen(){
    
    // get the sreen width and height
    int x = 5 * get_gamesquare();
    int y = 10 * get_gamesquare();
    int w = 20 * get_gamesquare();
    int h = 10 * get_gamesquare();
    render_object(DIALOG_ICO_L, x, y, w, h);
    render_all();
    
    return 0;
}

int draw_winning_screen(){
    
    // get the sreen width and height
    int x = 5 * get_gamesquare();
    int y = 10 * get_gamesquare();
    int w = 20 * get_gamesquare();
    int h = 10 * get_gamesquare();
    render_object(DIALOG_ICO_W, x, y, w, h);
    render_all();
    
    return 0;
}
