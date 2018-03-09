#include "./headers/graphics.h"

SDL_Window * Main_Screen = NULL;
SDL_Renderer * Main_Renderer  = NULL;
Textline * _text_head = NULL;

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
                          800, 600,
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

void render_all(){
    /*
     * this function is called by main loop to render the screen.
     * I like this better then having to use extern Main_Renderer
     * in main.c
     */
    SDL_RenderPresent(Main_Renderer);
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

int render_objects( gamepiece * pieces[], int range){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     * 
     * ---return 0 on success---
     */
    SDL_Texture * image;        //holder for image
    SDL_Rect  rect;             //holder for rect
    rect.w = 20;                //height and width can be defiend now
    rect.h = 20;
    
    for(int i = 0; i < range; i++){ 
        if(pieces[i] != NULL){
            image = get_piece_image(pieces[i]);
            rect.x = get_piece_x(pieces[i]) * 20; //get rect.x and rect.y with gamepiece interface functions
            rect.y = get_piece_y(pieces[i]) * 20; // multiply by 16 to convert from game square to pixel coordinates
            if( image == NULL){ 
                //if the piece doesn't have an image with it give it a blank square
                image = make_colored_texture(20, 20, 255, 0, 0); 
            }
            if(SDL_RenderCopy(Main_Renderer, image, NULL, &rect) != 0){
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
    if( render_objects(cur_room->walls, 200) != 0){
        printf("graphics.c->render_room(): Error rendering walls\n");
        return 1;
    }
    if( render_objects(cur_room->monsters, 5) != 0){
        printf("graphics.c->render_room(): Error rendering monsters\n");
        return 1;
    }
    if( render_objects(cur_room->bounty, 5) != 0){
        printf("graphics.c->render_room(): Error rendering bounty\n");
        return 1;
    }
    if( render_objects(cur_room->doors, 2) != 0){
        printf("graphics.c->render_room(): Error rendering doors\n");
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
    SDL_Rect dest_rect = {.h = 20, .w = 12, .x = x*20, .y = y*20};  //set dest rect to where line will start
    SDL_Rect src_rect; 
    
    SDL_Texture * bitmap_font = load_image("./img/font2.bmp"); //load font sheet
    
    if( bitmap_font == NULL){
        printf("graphics.c->render_text_line(): Error loading bitmap font image\n");
        return 1;
    }
    
    for(int i = 0; (i < strlen(text)) && (i < 40); i++){
       // if(text[i] == '\0'){break;} //stop at end of line
        src_rect = get_char_rect(text[i]); // get the rect with coordinates that point to the letter we want to print on the font sheet
        if( SDL_RenderCopy(Main_Renderer, bitmap_font, &src_rect, &dest_rect) != 0){
            printf("graphics.c->render_text_line(): Error copying font texture to main renderer\n");
        }
        dest_rect.x = dest_rect.x + 12;  //move over 1 before looping to draw next char
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
     
     strncpy(newline->text, string, 40); //copy text to new struct
     newline->nxt = NULL;
     
    if(_text_head == NULL){
        _text_head = newline;
    }else{
        newline->nxt = _text_head;   // newline points to first node after head
        _text_head = newline;        // head points to newline
    }    
    return 0;
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
