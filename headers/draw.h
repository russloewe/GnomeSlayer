#ifndef _DRAW_H
#define _DRAW_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameobjects.h"
#include "graphics.h"
#include "maps.h"
#include "checker.h"

int get_max_x();
int get_max_y();
int draw_all();
int load_images();
int render_objects( gamepiece * pieces[], int range);
int start_graphics_module();
int render_room(struct room * cur_room);
int  get_char_rect_x(char c);
int  get_char_rect_y(char c);

int add_message_queue(char * string);
int trim_message_queue(int n);
int render_message_queue(int line, int x, int y);
int render_player_stats(struct room * curroom);
int render_text_line(char * text, int x, int y);

#endif
