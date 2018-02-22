#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "gameobjects.h"

SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[]);
int render_background();

#endif
