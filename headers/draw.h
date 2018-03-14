#ifndef _DRAW_H
#define _DRAW_H

int get_max_x();

int get_max_y();
int render_all();
int load_images();
int render_objects( gamepiece * pieces[], int range);
int render_background_image(SDL_Texture * image);
int render_room(room * cur_room);
SDL_Rect get_char_rect(char c);
Textline * get_message_queue();

int add_message_queue(char * string);
int trim_message_queue(int n);
int render_message_queue(int line, int x, int y);
int render_player_stats(room * curroom);
int render_text_line(char * text, int x, int y);
#endif
