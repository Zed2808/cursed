#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <ctime>
#include "flow.hpp"
#include "gui.hpp"
#include "player.hpp"
#include "log.hpp"
#include "maps.hpp"
#include "npcs.hpp"

Log log;
Player player;
Map map;

int main() {
    // Initialize game
    init_game();

    // Add base stuff to player inventory
    player.inventory.additem(new BattleAxe(), 1);
    player.inventory.additem(new Shortsword(), 1);
    player.inventory.additem(new Mace(), 1);
    player.inventory.additem(new Fork(), 8);

    // BEGIN OLD TESTING STUFF

    // Display player stats window
    draw_character_stats(player);
    getch();

    //END OLD TESTING STUFF

    // Load map
    map = Map();
    load_map(map, "testmap");
    log.write("Loaded testmap.");

    // Place Player onto map
    map.place_character(2, 2, player);

    log.write("Press 'h' for help.");

    /* Get player input */
    int input = 0;

    while(true) {
        /* Update game state */
        if(update_game(input)) break;

        input = getch();
    }

    return 0;
}
