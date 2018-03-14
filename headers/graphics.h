#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

int init_video(void);
void cleanup();
int render_all();
int get_screen_height();
int get_screen_width();
int get_gamesquare();
int render_object( Icon icon, int x, int y, int w, int h);
#endif
