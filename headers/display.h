#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "gameobjects.h"

SDL_Surface * load_image(char * filename);
int render_objects( gamepiece * pieces[]);

#endif
