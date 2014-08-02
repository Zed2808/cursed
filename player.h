#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
	private:
		std::string name;
		int health;
		int mana;
		int stamina;
	public:
		Player();
		void set_name(std::string n);
		void set_health(int h);
		void set_mana(int m);
		void set_stamina(int s);
		std::string get_name();
		int get_health();
		int get_mana();
		int get_stamina();
};

#endif
