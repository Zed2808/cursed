#include <ncurses.h>
#include "gui.h"
#include "player.h"
#include "monster.h"

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
 * Function: draw_monster_stats
 * ----------------------------
 *   Draws monster's stats (level, health, mana, stamina)
 * 
 *   win_monster_stats: window to write stats on
 *   monster: monster whose stats should be drawn
 */
void draw_monster_stats(WINDOW *win_monster_stats, Monster monster) {
	// Print name
	wattron(win_monster_stats, A_BOLD);
	mvwprintw(win_monster_stats, 0, 1, monster.get_name().c_str());
	wattroff(win_monster_stats, A_BOLD);

	// Print health
	mvwprintw(win_monster_stats, 1, 1, "HLTH ");

	wattron(win_monster_stats, COLOR_PAIR(1));
	for(double i = 0; i <= monster.get_health(); i += monster.get_maxhealth()/25.0) { /* Print 1 block for every full 4% of health, plus 1 */
		waddch(win_monster_stats, ACS_CKBOARD);
	}
	wattroff(win_monster_stats, COLOR_PAIR(1));

	if(monster.get_health() <= monster.get_maxhealth()/10) { /* If health is 10% or less, print percent in red */
		wattron(win_monster_stats, COLOR_PAIR(1));
		mvwprintw(win_monster_stats, 1, 31, "%3d", monster.get_health());
		wattroff(win_monster_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_monster_stats, 1, 31, "%3d", monster.get_health());
	}
	wprintw(win_monster_stats, "/%3d", monster.get_maxhealth());

	// Print mana (only if monster has magical capabilities)
	if(monster.get_maxmana() > 0) {
		mvwprintw(win_monster_stats, 2, 1, "MANA ");

		wattron(win_monster_stats, COLOR_PAIR(2));
		for(double i = 0; i <= monster.get_mana(); i += monster.get_maxmana()/25.0) { /* Print 1 block for every full 4% of mana, plus 1 */
			waddch(win_monster_stats, ACS_CKBOARD);
		}
		wattroff(win_monster_stats, COLOR_PAIR(2));

		if(monster.get_mana() <= monster.get_maxmana()/10) { /* If mana is 10% or less, print percent in red */
			wattron(win_monster_stats, COLOR_PAIR(1));
			mvwprintw(win_monster_stats, 2, 31, "%3d", monster.get_mana());
			wattroff(win_monster_stats, COLOR_PAIR(1));
		} else {
			mvwprintw(win_monster_stats, 2, 31, "%3d", monster.get_mana());
		}
		wprintw(win_monster_stats, "/%3d", monster.get_maxmana());
	}

	// Print stamina
	mvwprintw(win_monster_stats, 3, 1, "STAM ");

	wattron(win_monster_stats, COLOR_PAIR(3));
	for(double i = 0; i <= monster.get_stamina(); i += monster.get_maxstamina()/25.0) { /* Print 1 block for every full 4% of stamina, plus 1 */
		waddch(win_monster_stats, ACS_CKBOARD);
	}
	wattroff(win_monster_stats, COLOR_PAIR(3));

	if(monster.get_stamina() <= monster.get_maxstamina()/10) { /* If stamina is 10% or less, print percent in red */
		wattron(win_monster_stats, COLOR_PAIR(1));
		mvwprintw(win_monster_stats, 3, 31, "%3d", monster.get_stamina());
		wattroff(win_monster_stats, COLOR_PAIR(1));
	} else {
		mvwprintw(win_monster_stats, 3, 31, "%3d", monster.get_stamina());
	}
	wprintw(win_monster_stats, "/%3d", monster.get_maxstamina());

	// Print level
	mvwprintw(win_monster_stats, 0, 29, "Level %3d", monster.get_level());

	// Refresh window
	wrefresh(win_monster_stats);
}
