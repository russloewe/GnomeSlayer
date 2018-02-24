#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "gameobjects.h"

SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[]);
SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green);
int render_background();

#endif
