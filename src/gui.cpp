#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <unistd.h>
#include "gui.h"
#include "character.h"

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
 * Function: draw_character_stats
 * --------------------
 *   Draws character's stats (health, mana, stamina)
 *
 *   win_character_stats: window to write stats on
 *   character: character whose stats should be drawn
 */
void draw_character_stats(WINDOW *win_character_stats, Character character) {
	// Print name
	wattron(win_character_stats, A_BOLD);
	mvwprintw(win_character_stats, 0, 1, character.get_name().c_str());
	wattroff(win_character_stats, A_BOLD);

	// Print health only if maxhealth > 0
	if(character.get_maxhealth() > 0) {
		mvwprintw(win_character_stats, 1, 1, "HLTH ");

		wattron(win_character_stats, COLOR_PAIR(1));
		for(double i = 0; i <= character.get_health(); i += character.get_maxhealth()/25.0) { /* Print 1 block for every full 4% of health, plus 1 */
			waddch(win_character_stats, ACS_CKBOARD);
		}
		wattroff(win_character_stats, COLOR_PAIR(1));

		if(character.get_health() <= character.get_maxhealth()/10) { /* If health is 10% or less, print percent in red */
			wattron(win_character_stats, COLOR_PAIR(1));
			mvwprintw(win_character_stats, 1, 31, "%3d", character.get_health());
			wattroff(win_character_stats, COLOR_PAIR(1));
		} else {
			mvwprintw(win_character_stats, 1, 31, "%3d", character.get_health());
		}
		wprintw(win_character_stats, "/%3d", character.get_maxhealth());
	}

	// Print mana only if maxmana > 0
	if(character.get_maxmana() > 0) {
		mvwprintw(win_character_stats, 2, 1, "MANA ");

		wattron(win_character_stats, COLOR_PAIR(2));
		for(double i = 0; i <= character.get_mana(); i += character.get_maxmana()/25.0) { /* Print 1 block for every full 4% of mana, plus 1 */
			waddch(win_character_stats, ACS_CKBOARD);
		}
		wattroff(win_character_stats, COLOR_PAIR(2));

		if(character.get_mana() <= character.get_maxmana()/10) { /* If mana is 10% or less, print percent in red */
			wattron(win_character_stats, COLOR_PAIR(1));
			mvwprintw(win_character_stats, 2, 31, "%3d", character.get_mana());
			wattroff(win_character_stats, COLOR_PAIR(1));
		} else {
			mvwprintw(win_character_stats, 2, 31, "%3d", character.get_mana());
		}
		wprintw(win_character_stats, "/%3d", character.get_maxmana());
	}

	// Print stamina only if maxhealth > 0
		if(character.get_maxstamina() > 0) {
		mvwprintw(win_character_stats, 3, 1, "STAM ");

		wattron(win_character_stats, COLOR_PAIR(3));
		for(double i = 0; i <= character.get_stamina(); i += character.get_maxstamina()/25.0) { /* Print 1 block for every full 4% of stamina, plus 1 */
			waddch(win_character_stats, ACS_CKBOARD);
		}
		wattroff(win_character_stats, COLOR_PAIR(3));

		if(character.get_stamina() <= character.get_maxstamina()/10) { /* If stamina is 10% or less, print percent in red */
			wattron(win_character_stats, COLOR_PAIR(1));
			mvwprintw(win_character_stats, 3, 31, "%3d", character.get_stamina());
			wattroff(win_character_stats, COLOR_PAIR(1));
		} else {
			mvwprintw(win_character_stats, 3, 31, "%3d", character.get_stamina());
		}
		wprintw(win_character_stats, "/%3d", character.get_maxstamina());
	}

	// Print level
	mvwprintw(win_character_stats, 0, 29, "Level %3d", character.get_level());

	// Refresh window
	wrefresh(win_character_stats);
}
