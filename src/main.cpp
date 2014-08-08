#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <ctime>
#include "gui.h"
#include "player.h"
#include "wolf.h"

int main() {
	char name[24];

	int win_stats_height = 5;
	int win_stats_width = 39;

	initscr();
	start_color();

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();
	curs_set(0);

	/* Draw splash thingy */
	splash();

	/* Get player's name */
	WINDOW *win_name = create_newwin(4, 36, (LINES-4)/2, (COLS-36)/2);
	wattron(win_name, A_BOLD);
	mvwprintw(win_name, 1, 1, "Enter your name (up to 24 chars).");
	wattroff(win_name, A_BOLD);
	curs_set(1);
	mvwgetstr(win_name, 2, 1, name);
	curs_set(0);

	/* Create player object and set example stats values*/
	Player player;
	player.set_name(name);

	clear_to_border();

	/* Display player stats window */
	WINDOW *win_player = create_newwin(win_stats_height, win_stats_width, LINES-win_stats_height, 0);
	draw_character_stats(win_player, player);

	/* Create wolf object that's level 4 */
	Wolf wolf1(4);

	/* Display wolf stats window */
	WINDOW *win_wolf1 = create_newwin(win_stats_height, win_stats_width, LINES-win_stats_height, COLS-win_stats_width);
	draw_character_stats(win_wolf1, wolf1);

	getch();
	endwin();
	return 0;
}
