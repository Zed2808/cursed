#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
	protected:
		std::string name;
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
		int get_maxhealth();
		int get_health();
		int get_maxmana();
		int get_mana();
		int get_maxstamina();
		int get_stamina();
};

#endif