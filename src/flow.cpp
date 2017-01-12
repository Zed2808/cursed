#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include "flow.hpp"
#include "character.hpp"
#include "gui.hpp"

extern Log log;
extern Player player;
extern Map map;

void init_game() {
	/* Initialize GUI stuff */
	init_gui();

	/* Draw splash screen */
	// splash();

	/* Set player's name */
	set_character_name(player);

	/* Set player's main attributes */
	set_main_attributes(player);

	/* Prepare for player input */
    keypad(stdscr, true);
}

bool update_game(int input) {
    // Escape: exit game confirmation
    if(input == 27) {
        if(confirm_exit()) {
        	endwin();
        	return true;
        }
    }

    // Arrow keys: move player character
    if(input == KEY_UP || input == KEY_DOWN || input == KEY_LEFT || input == KEY_RIGHT) {
        map.move_character(player, input);
    }

    // I: open inventory
    if(input == 'i') {
        player_inventory(player);
    }

    // H: print help
    if(input == 'h') {
        log.write("Quit game: esc\n  Open/close inventory: i\n  Move character: arrow keys");
    }

    // Draw the rest of the windows
    draw_map(map);
    draw_log(log);
    draw_character_weaponslot(player);

    return false;
}
