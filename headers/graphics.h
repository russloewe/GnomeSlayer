#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

int init_video();
void cleanup();
int render_all();
int get_screen_height();
int get_screen_width();
int get_gamesquare();
int render_object( int icon, int x, int y, int w, int h);
int load_image_to_mem(char * filename, int index);
int render_letter(int icon, int x_dest, int y_dest, int w_dest, int h_dest, int x_src,  int y_src,  int w_src,  int h_src);
#endif
