#ifdef __MINGW32__
#include <curses.h>
#endif

#ifdef __linux__
#include <ncurses.h>
#endif

#include <unistd.h>
#include <string>
#include "gui.hpp"
#include "character.hpp"

#define LOGHEIGHT 12
#define INVWIDTH 34

/*
 * init_gui
 *
 *   Sets up misc GUI stuff
 */
void init_gui() {
    initscr();
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_BLUE);

    refresh();
    curs_set(0);
}

/*
 * splash
 *
 *   Draws splash screen
 */
void splash() {
    attron(COLOR_PAIR(2));

    bool offset = false;
    for(int i = 0; i < LINES; i++) {
        int j = 0;
        if(offset) j++;
        while(j < COLS) {
            mvaddch(i, j, ACS_CKBOARD);
            j += 2;
        }
        offset = !offset;
        refresh();
        usleep(5000);
    }

    attroff(COLOR_PAIR(2));

    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < LINES; j++) {
            mvaddch(j, i, ' ');
        }
        refresh();
        usleep(2500);
    }


    attron(COLOR_PAIR(3));

    offset = false;
    for(int i = LINES; i >= 0; i--) {
        int j = COLS;
        if(offset) j--;
        while(j >= 0) {
            mvaddch(i, j, ACS_CKBOARD);
            j -= 2;
        }
        offset = !offset;
        refresh();
        usleep(5000);
    }

    attroff(COLOR_PAIR(3));

    for(int i = COLS; i >= 0; i--) {
        for(int j = LINES; j >= 0; j--) {
            mvaddch(j, i, ' ');
        }
        refresh();
        usleep(2500);
    }
}

/*
 * create_newwin
 *
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
 * destroy_win
 *
 *   Destroys window
 *
 *   local_win: window to destroy
 */
void destroy_win(WINDOW *local_win) {
    werase(local_win);
    wrefresh(local_win);
    delwin(local_win);
}

/*
 * clear_to_border
 *
 *   Clears the screen to just a border
 */
void clear_to_border() {
    border(0, 0, 0, 0, 0, 0, 0, 0);
    refresh();
}

/*
 * draw_character_stats
 *
 *   Draws character's stats (health, mana, stamina)
 *
 *   win_character_stats: window to write stats on
 *   character: character whose stats should be drawn
 */
void draw_character_stats(Character character) {
    WINDOW *win_character_stats = create_newwin(5, 39, LINES-5, 0);

    /* Print name */
    wattron(win_character_stats, A_BOLD);
    mvwprintw(win_character_stats, 0, 1, character.name.c_str());
    wattroff(win_character_stats, A_BOLD);

    /* Print health only if maxhealth > 0 */
    if(character.get_maxhealth() > 0) {
        mvwprintw(win_character_stats, 1, 1, "HLTH ");

        wattron(win_character_stats, COLOR_PAIR(1));
        for(double i = 0; i <= character.health; i += character.get_maxhealth()/25.0) { /* Print 1 block for every full 4% of health, plus 1 */
            waddch(win_character_stats, ACS_CKBOARD);
        }
        wattroff(win_character_stats, COLOR_PAIR(1));

        if(character.health <= character.get_maxhealth()/10) { /* If health is 10% or less, print percent in red */
            wattron(win_character_stats, COLOR_PAIR(1));
            mvwprintw(win_character_stats, 1, 31, "%3d", character.health);
            wattroff(win_character_stats, COLOR_PAIR(1));
        } else {
            mvwprintw(win_character_stats, 1, 31, "%3d", character.health);
        }
        wprintw(win_character_stats, "/%3d", character.get_maxhealth());
    }

    /* Print mana only if maxmana > 0 */
    if(character.get_maxmana() > 0) {
        mvwprintw(win_character_stats, 2, 1, "MANA ");

        wattron(win_character_stats, COLOR_PAIR(2));
        for(double i = 0; i <= character.mana; i += character.get_maxmana()/25.0) { /* Print 1 block for every full 4% of mana, plus 1 */
            waddch(win_character_stats, ACS_CKBOARD);
        }
        wattroff(win_character_stats, COLOR_PAIR(2));

        if(character.mana <= character.get_maxmana()/10) { /* If mana is 10% or less, print percent in red */
            wattron(win_character_stats, COLOR_PAIR(1));
            mvwprintw(win_character_stats, 2, 31, "%3d", character.mana);
            wattroff(win_character_stats, COLOR_PAIR(1));
        } else {
            mvwprintw(win_character_stats, 2, 31, "%3d", character.mana);
        }
        wprintw(win_character_stats, "/%3d", character.get_maxmana());
    }

    /* Print stamina only if maxhealth > 0 */
        if(character.get_maxstamina() > 0) {
        mvwprintw(win_character_stats, 3, 1, "STAM ");

        wattron(win_character_stats, COLOR_PAIR(3));
        for(double i = 0; i <= character.stamina; i += character.get_maxstamina()/25.0) { /* Print 1 block for every full 4% of stamina, plus 1 */
            waddch(win_character_stats, ACS_CKBOARD);
        }
        wattroff(win_character_stats, COLOR_PAIR(3));

        if(character.stamina <= character.get_maxstamina()/10) { /* If stamina is 10% or less, print percent in red */
            wattron(win_character_stats, COLOR_PAIR(1));
            mvwprintw(win_character_stats, 3, 31, "%3d", character.stamina);
            wattroff(win_character_stats, COLOR_PAIR(1));
        } else {
            mvwprintw(win_character_stats, 3, 31, "%3d", character.stamina);
        }
        wprintw(win_character_stats, "/%3d", character.get_maxstamina());
    }

    /* Print level */
    mvwprintw(win_character_stats, 0, 29, "Level %3d", character.level);

    /* Refresh window */
    wrefresh(win_character_stats);
}

/*
 * player_inventory
 *
 *   Draws inventory of player and handles player input
 *
 *   player: player object
 */
void player_inventory(Player &player) {
    unsigned int INVHEIGHT = LINES - LOGHEIGHT - 2;
    int INFOWIDTH = 34;
    int INFOHEIGHT;
    WINDOW *win_inventory = create_newwin(INVHEIGHT, INVWIDTH, 1, 1);

    /* When scrolling, used as an offset for vector index */
    unsigned int scroll = 0;

    /* Key input by user */
    int input;

    /* How many entries to write */
    unsigned int limit;

    /* Index of item in inventory to highlight */
    unsigned int highlight = 0;

    /* Until user presses escape */
    while(input != 'i') {
        /* Highlight item */
        if(input == KEY_UP && highlight > 0) {
            highlight--;
        }

        if(input == KEY_DOWN && highlight < player.inventory.slots.size() - 1) {
            highlight++;
        }

        /* Set scroll offset and limit number of lines to print */
        if(player.inventory.slots.size() > INVHEIGHT-2) {
            /* Set scroll offset with arrow keys */
            if(input == KEY_UP && scroll > 0) {
                scroll--;
            }

            if(input == KEY_DOWN && scroll < INVHEIGHT - player.inventory.slots.size()) {
                scroll++;
            }

            limit = INVHEIGHT-2;
        } else {
            limit = player.inventory.slots.size();
        }

        /* Clear inventory window & redraw border */
        werase(win_inventory);
        box(win_inventory, 0, 0);
        wattron(win_inventory, A_BOLD);
        mvwprintw(win_inventory, 0, 1, "%s", player.name.c_str());
        wattroff(win_inventory, A_BOLD);
        mvwprintw(win_inventory, 0, INVWIDTH-12, "%3d/%3d lbs", player.inventory.totalweight, player.get_carryweight());

        /* Write inventory window until limit is reached */
        for(unsigned int i = 0; i < limit; i++) {
            /* If for loop has reached item index highlight */
            if(i == highlight - scroll) {
                wattron(win_inventory, A_REVERSE);
            }
            mvwprintw(win_inventory, i+1, 2, "%d %s ", player.inventory.slots[i+scroll].quantity, player.inventory.slots[i+scroll].item->name.c_str());
            wattroff(win_inventory, A_REVERSE);
        }

        /* Set info box height based on item type */
        switch(player.inventory.slots[highlight-scroll].item->item_type) {
            case 0x01:
                INFOHEIGHT = 12;
                break;
            default:
                INFOHEIGHT = 3;
                break;
        }

        /* Create info window (could change size: must create new window every time) */
        WINDOW *win_info = create_newwin(INFOHEIGHT, INFOWIDTH, 1, INVWIDTH+2);

        Item * item = player.inventory.slots[highlight-scroll].item;

        /* If highlighted item is of item_type weapon */
        if(item->item_type == 0x01) {
            Weapon * weapon = dynamic_cast<Weapon*>(item);
            mvwprintw(win_info, 2, 1, "%s", weapon->primary.name.c_str());
            mvwprintw(win_info, 3, 1, "Damage: %d", weapon->primary.damage);
            mvwprintw(win_info, 4, 1, "Penetration: %.0f%%", weapon->primary.penetration * 100.0);
            mvwprintw(win_info, 5, 1, "Range: %d spaces", weapon->primary.range);
            mvwprintw(win_info, 7, 1, "%s", weapon->secondary.name.c_str());
            mvwprintw(win_info, 8, 1, "Damage: %d", weapon->secondary.damage);
            mvwprintw(win_info, 9, 1, "Penetration: %.0f%%", weapon->secondary.penetration * 100.0);
            mvwprintw(win_info, 10, 1, "Range: %d spaces", weapon->secondary.range);
        }

        /* Print generic item stats */
        wattron(win_info, A_BOLD);
        mvwprintw(win_info, 0, 1, "%s", item->name.c_str());
        wattroff(win_info, A_BOLD);
        mvwprintw(win_info, 0, INFOWIDTH-8, "%3d lbs", item->weight);

        /* Refresh windows */
        wrefresh(win_inventory);
        wrefresh(win_info);
        draw_character_equipslot(player);

        /* Get player input */
        input = getch();

        /* Destroy info window */
        destroy_win(win_info);
    }

    /* Destroy window */
    destroy_win(win_inventory);
}

/*
 * draw_character_equipslot
 *
 *   Draws equipslot of character
 *
 *   win_character_equipslot: window on which to draw character's equipslot
 *   character: character whose equipslot should be drawn
 */
void draw_character_equipslot(Character character) {
    const int EQUIPSLOT_HEIGHT = 3;
    WINDOW *win_character_equipslot = create_newwin(3, 18, (LINES-LOGHEIGHT-EQUIPSLOT_HEIGHT-1), (COLS-18)/2);
    Weapon * weapon = character.equipslot.equipped;

    wattron(win_character_equipslot, A_BOLD);
    mvwprintw(win_character_equipslot, 0, 1, "Equipped");
    wattroff(win_character_equipslot, A_BOLD);

    mvwprintw(win_character_equipslot, 1, 1, "%s", weapon->name.c_str());

    /* Refresh window */
    wrefresh(win_character_equipslot);
}

/*
 * set_character_name
 *
 *   Input window for character's name
 *
 *   character: character whose name should be set
 */
void set_character_name(Character &character) {
    char name[24];

    WINDOW *win_name = create_newwin(4, 39, (LINES-4)/2, (COLS-36)/2);
    wattron(win_name, A_BOLD);

    if(character.str_id == "player") {
        mvwprintw(win_name, 1, 1, "Enter your name.");
    } else {
        mvwprintw(win_name, 1, 1, "Enter %s's name (up to 24 chars).", character.str_id.c_str());
    }
    wattroff(win_name, A_BOLD);
    curs_set(1);
    mvwgetnstr(win_name, 2, 1, name, 24);
    curs_set(0);
    character.name = name;

    clear_to_border();
}

/* 
 * set_main_attributes
 *
 *   Input window for character's main attributes
 *
 *   character: character whose main attrs should be set
 */
void set_main_attributes(Character &character) {
    WINDOW *win = create_newwin(11, 26, (LINES-9)/2, (COLS-19)/2);
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

    mvwprintw(win, 0, 1, character.name.c_str());

    mvwprintw(win, 1, 1, "Endurance");
    mvwprintw(win, 2, 1, "Intelligence");
    mvwprintw(win, 3, 1, "Agility");
    mvwprintw(win, 4, 1, "Strength");
    mvwprintw(win, 5, 1, "Personality");
    mvwprintw(win, 6, 1, "Perception");
    mvwprintw(win, 7, 1, "Luck");

    while(input != '\n') {
        /* Endurance */
        if(attributes[0] > 0)  mvwprintw(win, 1, 20, "<");
        if(attributes[0] < 10) mvwprintw(win, 1, 23, ">");
        if(index == 0) wattron(win, A_REVERSE);
        mvwprintw(win, 1, 21, "%2d", attributes[0]);
        wattroff(win, A_REVERSE);

        /* Intelligence */
        if(attributes[1] > 0)  mvwprintw(win, 2, 20, "<");
        if(attributes[1] < 10) mvwprintw(win, 2, 23, ">");
        if(index == 1) wattron(win, A_REVERSE);
        mvwprintw(win, 2, 21, "%2d", attributes[1]);
        wattroff(win, A_REVERSE);

        /* Agility */
        if(attributes[2] > 0)  mvwprintw(win, 3, 20, "<");
        if(attributes[2] < 10) mvwprintw(win, 3, 23, ">");
        if(index == 2) wattron(win, A_REVERSE);
        mvwprintw(win, 3, 21, "%2d", attributes[2]);
        wattroff(win, A_REVERSE);

        /* Strength */
        if(attributes[3] > 0)  mvwprintw(win, 4, 20, "<");
        if(attributes[3] < 10) mvwprintw(win, 4, 23, ">");
        if(index == 3) wattron(win, A_REVERSE);
        mvwprintw(win, 4, 21, "%2d", attributes[3]);
        wattroff(win, A_REVERSE);

        /* Personality */
        if(attributes[4] > 0)  mvwprintw(win, 5, 20, "<");
        if(attributes[4] < 10) mvwprintw(win, 5, 23, ">");
        if(index == 4) wattron(win, A_REVERSE);
        mvwprintw(win, 5, 21, "%2d", attributes[4]);
        wattroff(win, A_REVERSE);

        /* Perception */
        if(attributes[5] > 0)  mvwprintw(win, 6, 20, "<");
        if(attributes[5] < 10) mvwprintw(win, 6, 23, ">");
        if(index == 5) wattron(win, A_REVERSE);
        mvwprintw(win, 6, 21, "%2d", attributes[5]);
        wattroff(win, A_REVERSE);

        /* Luck */
        if(attributes[6] > 0)  mvwprintw(win, 7, 20, "<");
        if(attributes[6] < 10) mvwprintw(win, 7, 23, ">");
        if(index == 6) wattron(win, A_REVERSE);
        mvwprintw(win, 7, 21, "%2d", attributes[6]);
        wattroff(win, A_REVERSE);

        /* Points Remaining */
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
                if(attributes[index] > 1) {
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

    clear_to_border();
}

/*
 * draw_map
 *
 *   Draws map to window
 *
 *   win_map: window to draw map to
 *   map: map to draw to win_map
 */
void draw_map(Map map) {
    WINDOW *win_map = create_newwin(18, 18, (LINES/2)-9, (COLS/2)-9);

    /* Draw map name */
    mvwprintw(win_map, 0, 1, "%s", map.name);

    /* Draw tiles */
    for(int row = 0; row < 16; row++) {
        for(int col = 0; col < 16; col++) {
            wattron(win_map, COLOR_PAIR(map.tiles[row][col].color_pair));
            mvwaddch(win_map, row+1, col+1, map.tiles[row][col].symbol);
            wattroff(win_map, COLOR_PAIR(map.tiles[row][col].color_pair));
        }
    }

    /* Draw characters */
    for(int row = 0; row < 16; row++) {
        for(int col = 0; col < 16; col++) {
            wattron(win_map, COLOR_PAIR(map.characters[row][col].color_pair));
            if(map.characters[row][col].name != "") {
                mvwaddch(win_map, row+1, col+1, map.characters[row][col].symbol);
            }
            wattroff(win_map, COLOR_PAIR(map.characters[row][col].color_pair));
        }
    }

    /* Refresh window */
    wrefresh(win_map);
}

/*
 * draw_log
 *
 *   Draws log window
 *
 *   log: log to write to window
 */
void draw_log(Log log) {
    /* Create outer window with border */
    WINDOW *win_log_border = newwin(LOGHEIGHT, COLS-2, LINES-LOGHEIGHT-1, 1);
    box(win_log_border, 0, 0);

    /* Create inner borderless window to write to */
    WINDOW *win_log = newwin(10, COLS-6, LINES-LOGHEIGHT, 2);

    int curs_y;
    int curs_x;

    /* Iterate through each log entry */
    for(std::list<std::string>::iterator it = log.log.begin(); it != log.log.end(); it++) {
        std::string s = *it;
        getyx(win_log, curs_y, curs_x);

        /* Print log entry only if cursor ended up at the beginning of a blank line after last entry */
        if(curs_y <= 9 && curs_x == 0) {
            wprintw(win_log, "> %s\n", s.c_str());
        }
    }

    wrefresh(win_log_border);
    wrefresh(win_log);
}

/*
 * confirm_exit
 *
 *   Window asking user for confirmation to exit game
 *
 *   Returns true if game should exit, false if not
 */
bool confirm_exit() {
    /* Create exit confirmation window */
    WINDOW *win_confirm_exit = create_newwin(5, 20, (LINES-5)/2, (COLS-20)/2);

    /* Key pressed by user */
    int input;

    /* Whether or not to exit the game (no by default) */
    bool exit = false;

    mvwprintw(win_confirm_exit, 1, 5, "Exit game?");

    /* Draw yes/no, with no highlighted initially */
    mvwprintw(win_confirm_exit, 3, 4, " ");
    wattron(win_confirm_exit, A_UNDERLINE);
    wprintw(win_confirm_exit, "y");
    wattroff(win_confirm_exit, A_UNDERLINE);
    wprintw(win_confirm_exit, "es ");
    wattron(win_confirm_exit, A_REVERSE);
    mvwprintw(win_confirm_exit, 3, 12, " ");
    wattron(win_confirm_exit, A_UNDERLINE);
    wprintw(win_confirm_exit, "n");
    wattroff(win_confirm_exit, A_UNDERLINE);
    wprintw(win_confirm_exit, "o ");
    wattroff(win_confirm_exit, A_REVERSE);

    wrefresh(win_confirm_exit);

    /* Get user input */
    input = getch();

    /* Left and right arrow keys to highlight, enter to select */
    while(input != '\n') {
        switch(input) {
            /* Highlight "yes" */
            case KEY_LEFT:
                wattron(win_confirm_exit, A_REVERSE);
                mvwprintw(win_confirm_exit, 3, 4, " ");
                wattron(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "y");
                wattroff(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "es ");
                wattroff(win_confirm_exit, A_REVERSE);
                mvwprintw(win_confirm_exit, 3, 12, " ");
                wattron(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "n");
                wattroff(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "o ");
                exit = true;
                break;
            /* Highlight "no" */
            case KEY_RIGHT:
                mvwprintw(win_confirm_exit, 3, 4, " ");
                wattron(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "y");
                wattroff(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "es ");
                wattron(win_confirm_exit, A_REVERSE);
                mvwprintw(win_confirm_exit, 3, 12, " ");
                wattron(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "n");
                wattroff(win_confirm_exit, A_UNDERLINE);
                wprintw(win_confirm_exit, "o ");
                wattroff(win_confirm_exit, A_REVERSE);
                exit = false;
                break;
            case 'y':
                destroy_win(win_confirm_exit);
                return true;
            case 'n':
                destroy_win(win_confirm_exit);
                return false;
            default:
                break;
        }

        wrefresh(win_confirm_exit);

        input = getch();
    }

    destroy_win(win_confirm_exit);
    return exit;
}
