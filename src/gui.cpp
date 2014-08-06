#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <unistd.h>
#include "gui.h"
#include "player.h"
#include "enemy.h"

/*
 * Function: splash
 * ----------------
 *   Draws splash screen
 */
void splash() {
	attron(COLOR_PAIR(2));
	for(int i = 0; i < LINES; i++) {
		for(int j = 0; j < COLS; j++) {
			mvaddch(i, j, ACS_CKBOARD);
		}
		refresh();
		usleep(20000);
	}
	attroff(COLOR_PAIR(2));

	for(int i = 0; i < LINES; i++) {
		move(i, 0);
		clrtoeol();
		refresh();
		usleep(20000);
	}
}

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
 * Function: clear_border
 * ----------------------
 *   Clears the screen to just a border
 */
void clear_border() {
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}

/*
 * Function: draw_player_stats
 * --------------------
 *   Draws player's stats (health, mana, stamina)
 *
 *   win_player_stats: window to write stats on
 *   player: player whose stats should be drawn
 */
void draw_player_stats(WINDOW *win_player_stats, Player player) {
	// Print name
	wattron(win_player_stats, A_BOLD);
	mvwprintw(win_player_stats, 0, 1, player.get_name().c_str());
	wattroff(win_player_stats, A_BOLD);

	// Print health
	mvwprintw(win_player_stats, 1, 1, "HLTH ");

	wattron(win_player_stats, COLOR_PAIR(1));
	for(double i = 0; i <= player.get_health(); i += player.get_maxhealth()/25.0) { /* Print 1 block for every full 4% of health, plus 1 */
		waddch(win_player_stats, ACS_CKBOARD);
	}
	wattroff(win_player_stats, COLOR_PAIR(1));

	if(player.get_health() <= player.get_maxhealth()/10) { /* If health is 10% or less, print percent in red */
		wattron(win_player_stats, COLOR_PAIR(1));
		mvwprintw(win_player_stats, 1, 31, "%3d", player.get_health());
		wattroff(win_player_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_player_stats, 1, 31, "%3d", player.get_health());
	}
	wprintw(win_player_stats, "/%3d", player.get_maxhealth());

	// Print mana
	mvwprintw(win_player_stats, 2, 1, "MANA ");

	wattron(win_player_stats, COLOR_PAIR(2));
	for(double i = 0; i <= player.get_mana(); i += player.get_maxmana()/25.0) { /* Print 1 block for every full 4% of mana, plus 1 */
		waddch(win_player_stats, ACS_CKBOARD);
	}
	wattroff(win_player_stats, COLOR_PAIR(2));

	if(player.get_mana() <= player.get_maxmana()/10) { /* If mana is 10% or less, print percent in red */
		wattron(win_player_stats, COLOR_PAIR(1));
		mvwprintw(win_player_stats, 2, 31, "%3d", player.get_mana());
		wattroff(win_player_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_player_stats, 2, 31, "%3d", player.get_mana());
	}
	wprintw(win_player_stats, "/%3d", player.get_maxmana());

	// Print stamina
	mvwprintw(win_player_stats, 3, 1, "STAM ");

	wattron(win_player_stats, COLOR_PAIR(3));
	for(double i = 0; i <= player.get_stamina(); i += player.get_maxstamina()/25.0) { /* Print 1 block for every full 4% of stamina, plus 1 */
		waddch(win_player_stats, ACS_CKBOARD);
	}
	wattroff(win_player_stats, COLOR_PAIR(3));

	if(player.get_stamina() <= player.get_maxstamina()/10) { /* If stamina is 10% or less, print percent in red */
		wattron(win_player_stats, COLOR_PAIR(1));
		mvwprintw(win_player_stats, 3, 31, "%3d", player.get_stamina());
		wattroff(win_player_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_player_stats, 3, 31, "%3d", player.get_stamina());
	}
	wprintw(win_player_stats, "/%3d", player.get_maxstamina());

	// Print level
	mvwprintw(win_player_stats, 0, 29, "Level %3d", player.get_level());

	// Refresh window
	wrefresh(win_player_stats);
}

/*
 * Function: draw_enemy_stats
 * ----------------------------
 *   Draws enemy's stats (level, health, mana, stamina)
 *
 *   win_enemy_stats: window to write stats on
 *   enemy: monster whose stats should be drawn
 */
void draw_enemy_stats(WINDOW *win_enemy_stats, Enemy enemy) {
	// Print name
	wattron(win_enemy_stats, A_BOLD);
	mvwprintw(win_enemy_stats, 0, 1, enemy.get_name().c_str());
	wattroff(win_enemy_stats, A_BOLD);

	// Print health
	mvwprintw(win_enemy_stats, 1, 1, "HLTH ");

	wattron(win_enemy_stats, COLOR_PAIR(1));
	for(double i = 0; i <= enemy.get_health(); i += enemy.get_maxhealth()/25.0) { /* Print 1 block for every full 4% of health, plus 1 */
		waddch(win_enemy_stats, ACS_CKBOARD);
	}
	wattroff(win_enemy_stats, COLOR_PAIR(1));

	if(enemy.get_health() <= enemy.get_maxhealth()/10) { /* If health is 10% or less, print percent in red */
		wattron(win_enemy_stats, COLOR_PAIR(1));
		mvwprintw(win_enemy_stats, 1, 31, "%3d", enemy.get_health());
		wattroff(win_enemy_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_enemy_stats, 1, 31, "%3d", enemy.get_health());
	}
	wprintw(win_enemy_stats, "/%3d", enemy.get_maxhealth());

	// Print mana (only if monster has magical capabilities)
	if(enemy.get_maxmana() > 0) {
		mvwprintw(win_enemy_stats, 2, 1, "MANA ");

		wattron(win_enemy_stats, COLOR_PAIR(2));
		for(double i = 0; i <= enemy.get_mana(); i += enemy.get_maxmana()/25.0) { /* Print 1 block for every full 4% of mana, plus 1 */
			waddch(win_enemy_stats, ACS_CKBOARD);
		}
		wattroff(win_enemy_stats, COLOR_PAIR(2));

		if(enemy.get_mana() <= enemy.get_maxmana()/10) { /* If mana is 10% or less, print percent in red */
			wattron(win_enemy_stats, COLOR_PAIR(1));
			mvwprintw(win_enemy_stats, 2, 31, "%3d", enemy.get_mana());
			wattroff(win_enemy_stats, COLOR_PAIR(1));
		} else {
			mvwprintw(win_enemy_stats, 2, 31, "%3d", enemy.get_mana());
		}
		wprintw(win_enemy_stats, "/%3d", enemy.get_maxmana());
	}

	// Print stamina
	mvwprintw(win_enemy_stats, 3, 1, "STAM ");

	wattron(win_enemy_stats, COLOR_PAIR(3));
	for(double i = 0; i <= enemy.get_stamina(); i += enemy.get_maxstamina()/25.0) { /* Print 1 block for every full 4% of stamina, plus 1 */
		waddch(win_enemy_stats, ACS_CKBOARD);
	}
	wattroff(win_enemy_stats, COLOR_PAIR(3));

	if(enemy.get_stamina() <= enemy.get_maxstamina()/10) { /* If stamina is 10% or less, print percent in red */
		wattron(win_enemy_stats, COLOR_PAIR(1));
		mvwprintw(win_enemy_stats, 3, 31, "%3d", enemy.get_stamina());
		wattroff(win_enemy_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_enemy_stats, 3, 31, "%3d", enemy.get_stamina());
	}
	wprintw(win_enemy_stats, "/%3d", enemy.get_maxstamina());

	// Print level
	mvwprintw(win_enemy_stats, 0, 29, "Level %3d", enemy.get_level());

	// Refresh window
	wrefresh(win_enemy_stats);
}
