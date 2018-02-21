#include "./headers/display.h"

extern SDL_Surface * screen;

SDL_Surface * load_image(char * filename)
{
    /*
     * Takes a char pointer to the filename and returns pointer to
     * SDL_Surface containing loaded bitmap
     */
    SDL_Surface* temp = NULL;
    SDL_Surface* image = NULL;
    temp = SDL_LoadBMP(filename);
    if (temp == NULL)
    {
        printf("ERROR: display.c -> load_image -> SDL_loadBMP(): %s\n", SDL_GetError());
        return NULL;
    }
    //format the image
    
    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL),
                           SDL_MapRGB(temp->format, 0, 0, 0)); 
    image = SDL_DisplayFormat(temp);
    
    if(image == NULL){
        printf("ERROR: display.c -> load_image -> SDL_DisplayFormat(): %s\n", SDL_GetError());
        return NULL;
    }
    
    SDL_FreeSurface(temp);            

    return image;
}

int render_objects( gamepiece * pieces[]){
    //const int obj_count = sizeof(pieces) / sizeof(pieces[0]);
    
    for(int i = 0; i < 1; i++){
        if(SDL_BlitSurface(pieces[i]->img, NULL, screen, pieces[i]->rect) != 0){
            printf("display.c->render_objects.c->SDL_BlitSurface()");
            return 1;
        }
    }
    if(SDL_Flip(screen) != 0 ){
        printf("display.c->render_objects.c->SDL_Flip()");
        return 1;
    }

    return 0;
}
