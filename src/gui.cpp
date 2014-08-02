#include <ncurses.h>
#include "gui.h"
#include "player.h"

/*
 * Function: create_newwin
 * -----------------------
 *   Creates new window
 *
 *   height: height of the new window
 *   width: width of the new window
 *   starty: y coordinate of the window's top left corner
 *   startx: x coordinate of the window's top left corner
 *
 *   Returns newly created window
 */
WINDOW *create_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);

	return local_win;
}

/*
 * Function: destroy_win
 * ---------------------
 *   Destroys window
 *
 *   local_win: window to destroy
 */
void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

/*
 * Function: draw_stats
 * --------------------
 *   Draws player's stats (health, mana, stamina)
 *
 *   stats_win: window to write stats on
 *   health: player's health
 *   mana: player's mana
 *   stamina: player's stamina
 */
void draw_stats(WINDOW *stats_win, Player player) {
	// Print name
	wattron(stats_win, A_BOLD);
	mvwprintw(stats_win, 0, 1, player.get_name().c_str());
	wattroff(stats_win, A_BOLD);

	// Print health
	mvwprintw(stats_win, 1, 1, "HLTH ");

	wattron(stats_win, COLOR_PAIR(1));
	for(int i = 1; i <= player.get_health(); i += 4) {	/* Print 1 block for every 4 health, plus 1 */
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(1));

	if(player.get_health() <= 10) {				/* If health is 10 or less, print percent in red */
		wattron(stats_win, COLOR_PAIR(1));
		mvwprintw(stats_win, 1, 31, "%3d%%", player.get_health());
		wattroff(stats_win, COLOR_PAIR(1));
	} else {
		mvwprintw(stats_win, 1, 31, "%3d%%", player.get_health());
	}

	// Print mana
	mvwprintw(stats_win, 2, 1, "MANA ");

	wattron(stats_win, COLOR_PAIR(2));
	for(int i = 1; i <= player.get_mana(); i += 4) {	/* Print 1 block for every 4 mana, plus 1 */
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(2));

	if(player.get_mana() <= 10) {				/* If mana is 10 or less, print percent in red */
		wattron(stats_win, COLOR_PAIR(1));
		mvwprintw(stats_win, 2, 31, "%3d%%", player.get_mana());
		wattroff(stats_win, COLOR_PAIR(1));
	} else {
		mvwprintw(stats_win, 2, 31, "%3d%%", player.get_mana());
	}

	// Print stamina
	mvwprintw(stats_win, 3, 1, "STAM ");

	wattron(stats_win, COLOR_PAIR(3));
	for(int i = 1; i <= player.get_stamina(); i += 4) {	/* Print 1 block for every 4 stamina, plus 1 */
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(3));

	if(player.get_stamina() <= 10) {			/* If stamina is 10 or less, print percent in red */
		wattron(stats_win, COLOR_PAIR(1));
		mvwprintw(stats_win, 3, 31, "%3d%%", player.get_stamina());
		wattroff(stats_win, COLOR_PAIR(1));
	} else {
		mvwprintw(stats_win, 3, 31, "%3d%%", player.get_stamina());
	}

	wrefresh(stats_win);
}
