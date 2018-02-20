#include "./headers/display.h"

SDL_Surface * load_image(char * filename)
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
    }else{
        return image;
    }
}
