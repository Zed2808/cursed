#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <ctime>
#include "gui.hpp"
#include "weapons.hpp"
#include "player.hpp"
#include "npcs.hpp"
#include "map.hpp"

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

    /* Create player object */
    Player player;

    /* Get and set player's name */
    WINDOW *win_name = create_newwin(4, 36, (LINES-4)/2, (COLS-36)/2);
    wattron(win_name, A_BOLD);
    mvwprintw(win_name, 1, 1, "Enter your name (up to 24 chars).");
    wattroff(win_name, A_BOLD);
    curs_set(1);
    mvwgetstr(win_name, 2, 1, name);
    curs_set(0);
    player.set_name(name);

    clear_to_border();

    set_main_attributes(player);

    clear_to_border();

    /* Display player stats window */
    WINDOW *win_player = create_newwin(win_stats_height, win_stats_width, LINES-win_stats_height, 0);
    draw_character_stats(win_player, player);

    getch();

    /* Create wolf object and display its stats */
    Wolf wolf1(6);
    WINDOW *win_wolf1 = create_newwin(win_stats_height, win_stats_width, LINES-win_stats_height, COLS-win_stats_width);
    draw_character_stats(win_wolf1, wolf1);

    getch();

    /* Create rat object and display its stats */
    Rat rat1(19);
    WINDOW *win_rat1 = create_newwin(win_stats_height, win_stats_width, LINES-win_stats_height, COLS-win_stats_width);
    draw_character_stats(win_rat1, rat1);

    getch();

    /* Display player inventory */
    WINDOW *win_player_inventory = create_newwin(9, 18, (LINES-9)/2, (COLS-18)/2);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.inventory.additem(Shortsword(), 19);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.inventory.additem(BattleAxe(), 7);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.inventory.additem(Shortsword(), 3);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.inventory.removeitem(Shortsword(), 7);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.inventory.removeitem(BattleAxe(), 9);
    draw_character_inventory(win_player_inventory, player);
    getch();

    /* Display player equipslot */
    WINDOW *win_player_equipslot = create_newwin(3, 18, (LINES-3), (COLS-18)/2);
    player.equipslot.equip(player.inventory, Shortsword());
    draw_character_equipslot(win_player_equipslot, player);
    draw_character_inventory(win_player_inventory, player);
    getch();

    player.equipslot.unequip(player.inventory);
    draw_character_equipslot(win_player_equipslot, player);
    draw_character_inventory(win_player_inventory, player);
    getch();

    /* Load map001 into current_map buffer */
    Map current_map;
    load_map("data/maps/map001", current_map);

    endwin();

    /* Print current_map to console */
    printf("current_map:\n");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%X", current_map.tiles[row][col]);
        }
        printf("\n");
    }

    return 0;
}
