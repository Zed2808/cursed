#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void draw_stats(WINDOW *stats_win, int health, int mana, int stamina);

int main() {
	WINDOW *stats_win;
	int stats_height = 5;
	int stats_width = 36;
	
	int health = 100;
	int mana = 42;
	int stamina = 79;

	initscr();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();
	
	stats_win = create_newwin(stats_height, stats_width, 10, 20);
	draw_stats(stats_win, health, mana, stamina);

	getch();	
	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);

	return local_win;
}

void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

void draw_stats(WINDOW *stats_win, int health, int mana, int stamina) {
	// Print health
	mvwprintw(stats_win, 1, 1, "HLTH ");
	wattron(stats_win, COLOR_PAIR(1));
	for(int i = 1; i <= health; i += 4) {
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(1));
	mvwprintw(stats_win, 1, 31, "%3d%%", health);

	// Print mana
	mvwprintw(stats_win, 2, 1, "MANA ");
	wattron(stats_win, COLOR_PAIR(2));
	for(int i = 1; i <= mana; i += 4) {
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(2));
	mvwprintw(stats_win, 2, 31, "%3d%%", mana);

	// Print stamina
	mvwprintw(stats_win, 3, 1, "STAM ");
	wattron(stats_win, COLOR_PAIR(3));
	for(int i = 1; i <= stamina; i += 4) {
		waddch(stats_win, ACS_CKBOARD);
	}
	wattroff(stats_win, COLOR_PAIR(3));
	mvwprintw(stats_win, 3, 31, "%3d%%", stamina);

	wrefresh(stats_win);
}
