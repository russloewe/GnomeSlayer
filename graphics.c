#include "./headers/graphics.h"



//function prototypes for internal functions
SDL_Texture * load_image(char * filename);

//pointers to stuff internal stuff
static SDL_Window * Main_Screen = NULL;
static SDL_Renderer * Main_Renderer  = NULL;
static SDL_Texture * _images[21] = {NULL};
//static SDL_Texture * _bitmap_font;    //pointer for font sheet
static int _screen_width = 800;
static int _screen_height = 600;
static int _gamesquare = 25;


/***************INIT**************/
int init_video(){
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
    /*
    if(img_loader() != 0){
        printf("Error loading game images \n");
    }*/
    
    //load font sheet
   // _bitmap_font = load_image("./img/font2.bmp"); 
    
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

/*********************SETTER*********************************/
int set_screen_height(){
    return _screen_height;
}

int set_screen_width(){
    return _screen_width;
}


/**************GETTERS**********************************/
int get_screen_height(){
    return _screen_height;
}

int get_screen_width(){
    return _screen_width;
}


int get_gamesquare(){
    return _gamesquare;
}


int render_all(){
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
        
    }else{
        //copy image surface to a texture
        texture = SDL_CreateTextureFromSurface(Main_Renderer, image);
       
       if (texture == NULL){  //fall back if error in creatng texture from image surface
            printf("Error: display.c->load_image()-> SDL_CreateTextureFromSurface()\n");
            SDL_GetError();
       }
    }

    //free the surface
    SDL_FreeSurface(image);
    
    return texture;
}

int render_object(int icon, int x, int y, int w, int h){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     * 
     * ---return 0 on success---
     */
    SDL_Rect  dest_rect;             //holder for rect
    dest_rect.w = w;                //height and width can be defiend now
    dest_rect.h = h;
    dest_rect.x = x;
    dest_rect.y = y;
    
    if(_images[icon] == NULL){
        printf("Error, no image at index location\n");
        return 1;
    }
    if(SDL_RenderCopy(Main_Renderer, _images[icon], NULL, &dest_rect) != 0){
        printf("display.c->render_object()->SDL_RenderCopy()\n");
        SDL_GetError();
        return 1;
}
    return 0;
}

int render_letter(int icon, int x_dest, int y_dest, int w_dest, int h_dest,
                            int x_src,  int y_src,  int w_src,  int h_src){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     * 
     * ---return 0 on success---
     */
    SDL_Rect  dest_rect;             //holder for rect
    dest_rect.w = w_dest;                //height and width can be defiend now
    dest_rect.h = h_dest;
    dest_rect.x = x_dest;
    dest_rect.y = y_dest;
    
    SDL_Rect  src_rect;             //holder for rect
    src_rect.w = w_src;                //height and width can be defiend now
    src_rect.h = h_src;
    src_rect.x = x_src;
    src_rect.y = y_src;
    
    if(SDL_RenderCopy(Main_Renderer, _images[icon], &src_rect, &dest_rect) != 0){
        printf("display.c->render_letter()->SDL_RenderCopy()\n");
        SDL_GetError();
        
        return 1;
}
    return 0;
}

int load_image_to_mem(char * filename, int index){
    if( (index > 21) || (index < 0) ){  //check boundry
        return 1;
    }
    SDL_Texture * img = load_image(filename);
    if(img == NULL){                //check load successfull
        return 1;
    }
    _images[index] = img;
    return 0;
}
