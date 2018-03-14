#include "./headers/graphics.h"



//function prototypes for internal functions
SDL_Texture * load_image(char * filename);

//pointers to stuff internal stuff
static SDL_Window * Main_Screen = NULL;
static SDL_Renderer * Main_Renderer  = NULL;
static SDL_Texture * images[20] = {NULL};
static SDL_Texture * _bitmap_font;    //pointer for font sheet
static int _screen_width = 800;
static int _screen_height = 600;
static int _gamesquare = 25;


/***************INIT**************/
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
       }
    }

    //free the surface
    SDL_FreeSurface(image);
    
    return texture;
}

int render_object( int icon, int x, int y, int w, int h){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     * 
     * ---return 0 on success---
     */
    SDL_Rect  rect;             //holder for rect
    rect.w = w;                //height and width can be defiend now
    rect.h = h;
    

    rect.x = x;
    rect.y = y;
    
    if(SDL_RenderCopy(Main_Renderer, images[icon], NULL, &rect) != 0){
        printf("display.c->render_objects()->SDL_RenderCopy()\n");
        return 1;
}
    return 0;
}


