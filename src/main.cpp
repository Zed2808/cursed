#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <ctime>
#include "gui.hpp"
#include "player.hpp"
#include "npcs.hpp"
#include "maps.hpp"
#include "log.hpp"

Log log;

int main() {
    // Initialize custom GUI stuff
    init_gui();

    // Draw splash thingy
    //splash();

    // Create player object
    Player player;

    // Set player's name
    set_character_name(player);

    // Set player's main attributes
    set_main_attributes(player);

    // Add base stuff to player inventory
    player.inventory.additem(new BattleAxe(), 1);
    player.inventory.additem(new Shortsword(), 1);
    player.inventory.additem(new Mace(), 1);
    player.inventory.additem(new Fork(), 8);

    /* BEGIN OLD TESTING STUFF

    // Display player stats window
    draw_character_stats(player);
    getch();

    // Display & modify player equipslot
    player.equipslot.equip(player.inventory, Shortsword());
    draw_character_equipslot(player);
    draw_character_inventory(player);
    getch();

    player.equipslot.unequip(player.inventory);
    draw_character_equipslot(player);
    draw_character_inventory(player);
    getch();

    clear_to_border();

    */ //END OLD TESTING STUFF

    // Load map
    Map current_map = Map();
    load_map(current_map, "testmap");
    log.write("Loaded testmap.");

    // Place Player onto map
    current_map.place_character(2, 2, player);

    log.write("Press 'h' for help.");

    /* Prepare for player input */
    keypad(stdscr, true);
    int input = 0;

    // Do stuff with player input
    bool exit = false;
    while(true) {
        // Escape: exit game confirmation
        if(input == 27) {
            exit = confirm_exit();
        }

        // Arrow keys: move player character
        if(input == KEY_UP || input == KEY_DOWN || input == KEY_LEFT || input == KEY_RIGHT) {
            current_map.move_character(player, input);
        }

        // I: open inventory
        if(input == 'i') {
            draw_player_inventory(player);
        }

        // H: print help
        if(input == 'h') {
            log.write("Quit game: esc\n  Open/close inventory: i\n  Move character: arrow keys");
        }

        // Draw the map and log windows
        draw_map(current_map);
        draw_log(log);

        // Exit if exit flag was set
        if(exit) break;

        // Get new input
        input = getch();
    }

    endwin();

    return 0;
}
