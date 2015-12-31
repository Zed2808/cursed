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

    /* BEGIN OLD TESTING STUFF

    // Display player stats window
    draw_character_stats(player);
    getch();

    // Display & modify player inventory
    draw_character_inventory(player);
    getch();

    player.inventory.additem(Shortsword(), 19);
    draw_character_inventory(player);
    getch();

    player.inventory.additem(BattleAxe(), 7);
    draw_character_inventory(player);
    getch();

    player.inventory.additem(Shortsword(), 3);
    draw_character_inventory(player);
    getch();

    player.inventory.removeitem(Shortsword(), 7);
    draw_character_inventory(player);
    getch();

    player.inventory.removeitem(BattleAxe(), 9);
    draw_character_inventory(player);
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

    // Place Player onto map
    current_map.place_character(2, 2, player);

    // Display current_map
    draw_map(current_map);

    // Get player input
    keypad(stdscr, true);
    int input = getch();

    // Do stuff with player input
    while(input != 27) { // 27 - escape key
        if(input == KEY_UP || input == KEY_DOWN || input == KEY_LEFT || input == KEY_RIGHT) {
            current_map.move_character(player, input);
        }

        draw_map(current_map);

        input = getch();
    }

    endwin();

    return 0;
}
