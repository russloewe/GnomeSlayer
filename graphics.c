#include "./headers/graphics.h"


//internal data structures
struct Textline{
    char text[60];
    struct Textline * nxt;
};
typedef struct Textline Textline;
static int text_line_length = 60;

//function prototypes for internal functions
SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[], int range);
int load_images();
SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green);
int render_background();
int render_background_image(SDL_Texture * img);
int render_room(room * cur_room);
SDL_Rect get_char_rect(char c);
int trim_message_queue(int n);
int render_player_stats(room * curroom);
int render_message_queue(int lines, int x, int y);
Textline * get_message_queue();

//pointers to stuff internal stuff
static SDL_Window * Main_Screen = NULL;
static SDL_Renderer * Main_Renderer  = NULL;
static Textline * _text_head = NULL;          //message queue
static SDL_Texture * images[20] = {NULL};
static SDL_Texture * _bitmap_font;    //pointer for font sheet
static int _screen_width = 800;
static int _screen_height = 600;
static int _gamesquare = 25;

int init_video(void){
    /*
     * Initialize the SDL subsytem for video only. 
     */ 
    if( SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("ERROR: init.c -> init_video -> SDL_Init\n: %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    /*
     * Open a screen 800 by 600, with the double buffer feature 
     * to speed rendering.
     */
    Main_Screen = SDL_CreateWindow("PCC CS133 Final",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          _screen_width, _screen_height,
                          SDL_WINDOW_OPENGL);
                          
    if(Main_Screen == NULL){
        printf("ERROR: init.c -> init_video -> SDL_CreateWindow : %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    /*
     * inti the renderer
     */
     Main_Renderer = SDL_CreateRenderer(Main_Screen, -1, 0);
    
    if(Main_Renderer == NULL){
        printf("ERROR: init.c -> init_video -> SDL_CreateRenderer : %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    //laod images
    if(load_images() != 0){
        printf("Error loading game images \n");
    }
    
    //load font sheet
    _bitmap_font = load_image("./img/font2.bmp"); 
    
    return 0;
}

void cleanup(){
    /*
     * Close down whatever SDL is doing or you might get a runaway screen
     */
    SDL_DestroyRenderer(Main_Renderer);
    SDL_DestroyWindow(Main_Screen);
    SDL_Quit();
}

int get_screen_height(){
    return _screen_height;
}

int get_screen_width(){
    return _screen_width;
}

int get_max_x(){
    int width = get_screen_width();
    int square = get_gamesquare();
    int max = (width / square) - 1;
    return max;
}

int get_max_y(){
    int width = get_screen_height();
    int square = get_gamesquare();
    int max = (width / square) - 10;
    return max;
}

int get_gamesquare(){
    return _gamesquare;
}


int render_all(){
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
     
    if( render_background_image(images[BACKGROUND_ICO]) != 0){
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
    SDL_RenderPresent(Main_Renderer);
    return 0;
}

SDL_Texture * load_image(char * filename){
    /*
     * Takes a char pointer to the filename and returns pointer to
     * SDL_Surface containing loaded bitmap
     */
    SDL_Surface* image = NULL;
    SDL_Texture * texture = NULL;
    image = SDL_LoadBMP(filename);
    if (image == NULL)
    {
        //if the image doesn't load, draw a 
        printf("ERROR: display.c -> load_image -> SDL_loadBMP(): %s\n", SDL_GetError());
        texture = make_colored_texture(20, 20, 255, 255, 255);
    }else{
        //copy image surface to a texture
        texture = SDL_CreateTextureFromSurface(Main_Renderer, image);
       
       if (texture == NULL){  //fall back if error in creatng texture from image surface
            printf("Error: display.c->load_image()-> SDL_CreateTextureFromSurface()\n");
            texture = make_colored_texture(20, 20, 255, 255, 255);
       }
    }

    //free the surface
    SDL_FreeSurface(image);
    
    return texture;
}

int load_images(){
    //load an array of images that are going to be used in game
    images[BACKGROUND_ICO] = load_image("./img/background2.bmp");
    images[WALL_ICO] = load_image("./img/wall.bmp");
    images[DOOR_ICO] = load_image("./img/door.bmp");
    images[SWORD_ICO_1] = load_image("./img/sword.bmp");
    images[SWORD_ICO_2] = load_image("./img/sword.bmp");
    images[SWORD_ICO_3] = load_image("./img/sword.bmp");
    images[SHIELD_ICO_1] = load_image("./img/shield.bmp");
    images[SHIELD_ICO_2] = load_image("./img/shield.bmp");
    images[SHIELD_ICO_3] = load_image("./img/shield.bmp");
    images[POTION_ICO_1] = load_image("./img/potion.bmp");
    images[POTION_ICO_2] = load_image("./img/potion.bmp");
    images[POTION_ICO_3] = load_image("./img/potion.bmp");
    images[MONSTER_ICO_1] = load_image("./img/monster.bmp");
    images[MONSTER_ICO_2] = load_image("./img/monster.bmp");
    images[MONSTER_ICO_3] = load_image("./img/monster.bmp");
    images[PLAYER_ICO_1] = load_image("./img/player1.bmp");
    images[PLAYER_ICO_2] = load_image("./img/player2.bmp");
    images[PLAYER_ICO_3] = load_image("./img/player3.bmp");
    
    for(int i = 0; i < 8; i++){
        if(images[i] == NULL){
            return 1;
        }
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
    SDL_Rect  rect;             //holder for rect
    rect.w = get_gamesquare();                //height and width can be defiend now
    rect.h = get_gamesquare();
    
    for(int i = 0; i < range; i++){ 
        if(pieces[i] != NULL){
            //set dest rect x,y coords
            rect.x = get_piece_x(pieces[i]) * get_gamesquare(); //get rect.x and rect.y with gamepiece interface functions
            rect.y = get_piece_y(pieces[i]) * get_gamesquare(); // multiply by 16 to convert from game square to pixel coordinates
            
            //get piece ICON
            Icon icon = get_piece_icon(pieces[i]);
            if(SDL_RenderCopy(Main_Renderer, images[icon], NULL, &rect) != 0){
                printf("display.c->render_objects()->SDL_RenderCopy()\n");
                return 1;
            }
        }
    }
    return 0;
}

int render_background_image(SDL_Texture * image){
    /*
     * Draw a texture the size of the whole screen to the screen
     * use this in place of the original render_background(), since
     * there is no need to clear the screen or black the screen 
     */
    SDL_Rect  rect;             //holder for rect
    rect.w = 800;                //height and width can be defiend now
    rect.h = 608;
    rect.x = 0;
    rect.y = 0; 

    if(SDL_RenderCopy(Main_Renderer, image, NULL, &rect) != 0){
        printf("display.c->render_background()->SDL_RenderCopy()\n");
        return 1;
    }

    return 0;
}

int render_background(){
    /*
     * this draws the background. Every render cycle the screen starts off
     * fresh before objects are drawn. This function draws the background color
     * adn frames and stuff that are the basis for each new frame
     */
    if(SDL_SetRenderDrawColor(Main_Renderer, 0, 0, 0, 0) != 0){
        printf("Error display.c->render_background->SDL_SetRenderDrawColort()\n");
        return 1;
    }else if(SDL_RenderClear(Main_Renderer) != 0){
        printf("Error display.c->render_background->SDL_RenderCleart()\n");
        return 1;
    }else{
       // SDL_RenderPresent(Main_Renderer);
        return 0;
    }
}

SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green){
    /* Creates a colored texture of some color
     * returns pointer to it
     */
     
     //first create surface
     SDL_Surface * surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
     if(surface == NULL){
         printf("Error display.c->make_colored_texture()->SDL_CreateRGBSurface\n");
         return NULL;
     }
     //fill it with color
     SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, red, blue, green));
     //convert the surface to a texture
     SDL_Texture * texture = SDL_CreateTextureFromSurface(Main_Renderer, surface);
     if(texture == NULL){
         printf("Error: display.c->make_colored_tecture()->SDL_CreateTextureFromSurface\n");
         return NULL;
     }
    
    return texture;
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

int render_text_line(char * text, int x, int y){
    /*
     * draw a line of text to string starting at coodrinate x, y
     * renders letters by copying from a bitmap font sheet
     * 
     * ----returns 0 on success-------
     */
    SDL_Rect dest_rect = {.h = 15, .w = 8, .x = x*20, .y = y*20};  //set dest rect to where line will start
    SDL_Rect src_rect; 
    
    
    
    if( _bitmap_font == NULL){
        printf("graphics.c->render_text_line(): Error loading bitmap font image\n");
        return 1;
    }
    
    for(int i = 0; (i < strlen(text)) && (i < text_line_length); i++){
       // if(text[i] == '\0'){break;} //stop at end of line
        src_rect = get_char_rect(text[i]); // get the rect with coordinates that point to the letter we want to print on the font sheet
        if( SDL_RenderCopy(Main_Renderer, _bitmap_font, &src_rect, &dest_rect) != 0){
            printf("graphics.c->render_text_line(): Error copying font texture to main renderer\n");
        }
        dest_rect.x = dest_rect.x + 8;  //move over 1 before looping to draw next char
    }  
    
    return 0;
}

SDL_Rect get_char_rect(char c){
    /*
     * take a char and return the rect that represents that letter on the 
     * font bitmap. There is an equation that maps ascii code to (x,y) coordinate 
     * on the bitmap "font1.bmp" that is utilized in this function.
     */
    SDL_Rect rect;
    int ascii = (int)c;          //turn char into ascii code
    int index = ascii - 32;      //this maps ascii code to index of sprite map
    
    int sprite_x = 17 + (index % 10) * 61;     //map ascii index to x offest of sprite map
    int sprite_y = 10 + (index / 10) * 65;     //map ascii index to y offset of sprite map
    rect.h = 50;
    rect.w = 25;
    rect.x = sprite_x;
    rect.y = sprite_y;
    
    return rect;
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
