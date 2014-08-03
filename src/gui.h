#ifndef GUI_H
#define GUI_H

#include <string>
#include "player.h"
#include "monster.h"

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void draw_player_stats(WINDOW *win_player_stats, Player player);
void draw_monster_stats(WINDOW *win_monster_stats, Monster monster);

#endif
