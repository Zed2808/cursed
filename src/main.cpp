#include <ncurses.h>
#include "gui.h"
#include "player.h"

int main() {
	char name[34];

	WINDOW *win_stats;
	int win_stats_height = 5;
	int win_stats_width = 36;

	Player player;
	player.set_health(87);
	player.set_mana(9);
	player.set_stamina(59);

	initscr();
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();

	WINDOW *win_name = create_newwin(4, 36, 0, 10);
	wattron(win_name, A_BOLD);
	mvwprintw(win_name, 1, 1, "Enter your name (up to 34 chars).");
	wattroff(win_name, A_BOLD);
	curs_set(1);
	mvwgetstr(win_name, 2, 1, name);
	player.set_name(name);
	curs_set(0);

	win_stats = create_newwin(win_stats_height, win_stats_width, 5, 10);
	draw_stats(win_stats, player.get_name(), player.get_health(), player.get_mana(), player.get_stamina());

	getch();
	endwin();
	return 0;
}
