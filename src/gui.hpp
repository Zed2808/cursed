#ifndef GUI_H
#define GUI_H

#include "character.hpp"
#include "maps.hpp"

void init_gui();
void splash();
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void clear_to_border();
void draw_character_stats(Character character);
void draw_character_inventory(Character character);
void draw_character_equipslot(Character character);
void set_character_name(Character &character);
void set_main_attributes(Character &character);
void draw_map(Map map);

#endif
