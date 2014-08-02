#include <ncurses.h>
#include "gui.h"
#include "player.h"

int main() {
	WINDOW *win_stats;
	int win_stats_height = 5;
	int win_stats_width = 36;

	Player player;
	//player.set_name("Default Player");
	player.set_health(87);
	player.set_mana(9);
	player.set_stamina(59);

	initscr();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();

	win_stats = create_newwin(win_stats_height, win_stats_width, 5, 10);
	draw_stats(win_stats, player.get_name(), player.get_health(), player.get_mana(), player.get_stamina());

	getch();
	endwin();
	return 0;
}
