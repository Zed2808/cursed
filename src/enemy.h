#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
	protected:
		std::string name;
		int level;
		int maxhealth;
		int health;
		int maxmana;
		int mana;
		int maxstamina;
		int stamina;
	public:
		void set_maxhealth(int h);
		void set_health(int h);
		void set_maxmana(int m);
		void set_mana(int m);
		void set_maxstamina(int s);
		void set_stamina(int s);
		std::string get_name();
		int get_level();
		int get_maxhealth();
		int get_health();
		int get_maxmana();
		int get_mana();
		int get_maxstamina();
		int get_stamina();
};

#endif
