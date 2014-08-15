#ifndef GUI_H
#define GUI_H

#include <string>
#include "character.h"

void splash();
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void clear_to_border();
void draw_character_stats(WINDOW *win_character_stats, Character character);
void set_main_attributes(Character &character);

#endif
