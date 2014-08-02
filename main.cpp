#include <ncurses.h>
#include "gui.h"

int main() {
	WINDOW *win_stats;
	int win_stats_height = 5;
	int win_stats_width = 36;

	/* Temporary until player class is created */
	int health = 100;
	int mana = 49;;
	int stamina = 73;

	initscr();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();

	win_stats = create_newwin(win_stats_height, win_stats_width, 5, 10);
	draw_stats(win_stats, health, mana, stamina);

	getch();
	endwin();
	return 0;
}
