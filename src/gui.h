#ifndef GUI_H
#define GUI_H

#include <string>
#include "player.h"

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void draw_stats(WINDOW *stats_win, Player player);

#endif
