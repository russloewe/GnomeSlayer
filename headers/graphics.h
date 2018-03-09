#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "gameobjects.h"
#include "maps.h"

struct Textline{
    char text[50];
    struct Textline * nxt;
};
typedef struct Textline Textline;

int init_video(void);
void cleanup();
void render_all();
SDL_Texture * load_image(char * filename);
int render_objects( gamepiece * pieces[], int range);
SDL_Texture * make_colored_texture(int height, int width, Uint8 red, Uint8 blue, Uint8 green);
int render_background();
int render_background_image(SDL_Texture * img);
int render_room(room * cur_room);
int render_text_line(char * text, int x, int y);
SDL_Rect get_char_rect(char c);
int add_message_queue(char * string);
int render_message_queue(int lines, int x, int y);
Textline * get_message_queue();

#endif
