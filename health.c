#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void draw_stats(WINDOW *stats_win, int health, int mana, int stamina);

int main() {
	WINDOW *my_win;
	int height = 5;
	int width = 27;

	initscr();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);

	refresh();
	
	my_win = create_newwin(height, width, (LINES-height)/2, (COLS-width)/2);
	draw_stats(my_win, 100, 100, 100);

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
	wmove(stats_win, 1, 1);
	wattron(stats_win, COLOR_PAIR(1));
	waddch(stats_win, ACS_CKBOARD);
	wattroff(stats_win, COLOR_PAIR(1));
	
	wmove(stats_win, 2, 1);
	wattron(stats_win, COLOR_PAIR(2));
	waddch(stats_win, ACS_CKBOARD);
	wattroff(stats_win, COLOR_PAIR(2));

	wmove(stats_win, 3, 1);
	wattron(stats_win, COLOR_PAIR(3));
	waddch(stats_win, ACS_CKBOARD);
	wattroff(stats_win, COLOR_PAIR(3));

	wrefresh(stats_win);
}
