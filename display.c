#include "./headers/display.h"


extern SDL_Renderer * Main_Renderer;
extern gamepiece ** objects_hd;

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
    //const int obj_count = sizeof(pieces) / sizeof(pieces[0]);
    
    for(int i = 0; i < 1; i++){ //hardcoded number of gamepieces for now
        if(SDL_RenderCopy(Main_Renderer, pieces[i]->img, NULL, pieces[i]->rect) != 0){
            printf("display.c->render_objects()->SDL_RenderCopy()\n");
            return 1;
        }
    }
    
    SDL_RenderPresent(Main_Renderer);

    return 0;
}

int render_background(){
    //First draw balck, clear the screen, then render buffer.
    //later we can use this function to draw the game board to screen.
    
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
