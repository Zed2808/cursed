#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <unistd.h>
#include <string>
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
 * Function: clear_to_border
 * ----------------------
 *   Clears the screen to just a border
 */
void clear_to_border() {
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

/* Function: set_main_attributes
 * -----------------------------
 *   Input window for Character's main attributes
 *
 *   character: character whose main attrs should be set
 */
void set_main_attributes(Character character) {
	WINDOW *win = create_newwin(11, 19, (LINES-9)/2, (COLS-19)/2);
	int input;
	int index = 0;
	int points = 10;
	int attributes[7] = {5, 5, 5, 5, 5, 5, 5};
	/*
	 * 0: endurance
	 * 1: intelligence
	 * 2: agility
	 * 3: strength
	 * 4: personality
	 * 5: perception
	 * 6: luck
	 */

	keypad(win, true);
	noecho();

	mvwprintw(win, 1, 1, "Endurance");
	mvwprintw(win, 2, 1, "Intelligence");
	mvwprintw(win, 3, 1, "Agility");
	mvwprintw(win, 4, 1, "Strength");
	mvwprintw(win, 5, 1, "Personality");
	mvwprintw(win, 6, 1, "Perception");
	mvwprintw(win, 7, 1, "Luck");

	while(input != '\n') {
		// Endurance
		if(attributes[0] > 0)  mvwprintw(win, 1, 14, "<");
		if(attributes[0] < 10) mvwprintw(win, 1, 17, ">");
		if(index == 0) wattron(win, A_REVERSE);
		mvwprintw(win, 1, 15, "%2d", attributes[0]);
		wattroff(win, A_REVERSE);

		// Intelligence
		if(attributes[1] > 0)  mvwprintw(win, 2, 14, "<");
		if(attributes[1] < 10) mvwprintw(win, 2, 17, ">");
		if(index == 1) wattron(win, A_REVERSE);
		mvwprintw(win, 2, 15, "%2d", attributes[1]);
		wattroff(win, A_REVERSE);

		// Agility
		if(attributes[2] > 0)  mvwprintw(win, 3, 14, "<");
		if(attributes[2] < 10) mvwprintw(win, 3, 17, ">");
		if(index == 2) wattron(win, A_REVERSE);
		mvwprintw(win, 3, 15, "%2d", attributes[2]);
		wattroff(win, A_REVERSE);

		// Strength
		if(attributes[3] > 0)  mvwprintw(win, 4, 14, "<");
		if(attributes[3] < 10) mvwprintw(win, 4, 17, ">");
		if(index == 3) wattron(win, A_REVERSE);
		mvwprintw(win, 4, 15, "%2d", attributes[3]);
		wattroff(win, A_REVERSE);

		// Personality
		if(attributes[4] > 0)  mvwprintw(win, 5, 14, "<");
		if(attributes[4] < 10) mvwprintw(win, 5, 17, ">");
		if(index == 4) wattron(win, A_REVERSE);
		mvwprintw(win, 5, 15, "%2d", attributes[4]);
		wattroff(win, A_REVERSE);

		// Perception
		if(attributes[5] > 0)  mvwprintw(win, 6, 14, "<");
		if(attributes[5] < 10) mvwprintw(win, 6, 17, ">");
		if(index == 5) wattron(win, A_REVERSE);
		mvwprintw(win, 6, 15, "%2d", attributes[5]);
		wattroff(win, A_REVERSE);

		// Luck
		if(attributes[6] > 0)  mvwprintw(win, 7, 14, "<");
		if(attributes[6] < 10) mvwprintw(win, 7, 17, ">");
		if(index == 6) wattron(win, A_REVERSE);
		mvwprintw(win, 7, 15, "%2d", attributes[6]);
		wattroff(win, A_REVERSE);

		// Points Remaining
		mvwprintw(win, 9, 1, "%s %2d", "Points left:", points);

		input = wgetch(win);
		switch(input) {
			case KEY_DOWN:
				index++;
				if(index > 6) index = 0;
				break;
			case KEY_UP:
				index--;
				if(index < 0) index = 6;
				break;
			case KEY_LEFT:
				if(attributes[index] > 0) {
					attributes[index]--;
					points++;
				}
				break;
			case KEY_RIGHT:
				if(attributes[index] < 10 && points > 0) {
					attributes[index]++;
					points--;
				}
				break;
		}
	}
	
	character.set_endurance(attributes[0]);
	character.set_intelligence(attributes[1]);
	character.set_agility(attributes[2]);
	character.set_strength(attributes[3]);
	character.set_personality(attributes[4]);
	character.set_perception(attributes[5]);
	character.set_luck(attributes[6]);
}
