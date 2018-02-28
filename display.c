#include "./headers/display.h"



extern gamepiece ** objects_hd;

SDL_Window * Main_Screen = NULL;
SDL_Renderer * Main_Renderer  = NULL;

int init_video(void){
    /*
     * Initialize the SDL subsytem for video only. 
     * If initai
     */ 
    if( SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("ERROR: init.c -> init_video -> SDL_Init\n: %s\n", SDL_GetError());
        SDL_GetError();
        return 1;
    }
    
    /*
     * Open a screen 640 by 480, with the double buffer feature 
     * to speed rendering.
     */
    Main_Screen = SDL_CreateWindow("PCC CS133 Final",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
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


SDL_Texture * load_image(char * filename)
{
    /*
     * Takes a char pointer to the filename and returns pointer to
     * SDL_Surface containing loaded bitmap
     */
    SDL_Surface* image = NULL;
    image = SDL_LoadBMP(filename);
    if (image == NULL)
    {
        printf("ERROR: display.c -> load_image -> SDL_loadBMP(): %s\n", SDL_GetError());
        return NULL;
    }

   //copy image surface to a texture
   SDL_Texture * texture = SDL_CreateTextureFromSurface(Main_Renderer, image);
   
   if (texture == NULL){
       printf("Error: display.c->load_image()-> SDL_CreateTextureFromSurface()\n");
       return NULL;
   }
    
    SDL_FreeSurface(image);            

    return texture;
}

int render_objects( gamepiece * pieces[]){
    /*
     * This function takes an array of pointers to game pieces and
     * loops through, rendering each one that isn't NULL.
     */
    
    for(int i = 0; i < 10; i++){ 
        if(pieces[i] != NULL){
            if( pieces[i]->img == NULL){ 
                //if the piece doesn't have an image with it give it a blank square
                pieces[i]->img = make_colored_texture(16, 16, 255, 0, 0); 
            }
            if(SDL_RenderCopy(Main_Renderer, pieces[i]->img, NULL, pieces[i]->rect) != 0){
                printf("display.c->render_objects()->SDL_RenderCopy()\n");
                return 1;
            }
        }
    }
    
    SDL_RenderPresent(Main_Renderer);

    return 0;
}

int render_background(){
    /*
     * this draws the background. Every render cycle the screen starts off
     * fresh before objects are drawn. This function draws the background color
     * adn frames and stuff that are the basis for each new frame
     */
    if(SDL_SetRenderDrawColor(Main_Renderer, 0, 0, 0, 255) != 0){
        printf("Error display.c->render_background->SDL_SetRenderDrawColort()\n");
        return 1;
    }else if(SDL_RenderClear(Main_Renderer) != 0){
        printf("Error display.c->render_background->SDL_RenderCleart()\n");
        return 1;
    }else{
        SDL_RenderPresent(Main_Renderer);
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
