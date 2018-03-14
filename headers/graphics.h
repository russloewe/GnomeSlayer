#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "gameobjects.h"
#include "maps.h"
#include "checker.h"

int init_video(void);
void cleanup();
int render_all();
int render_text_line(char * text, int x, int y);
int add_message_queue(char * string);
int get_screen_height();
int get_screen_width();
int get_gamesquare();
int get_max_x();
int get_max_y();
#endif
