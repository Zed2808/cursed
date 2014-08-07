#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
	protected:
		/* Current Stats */
		std::string name;
		int level;

		int health;
		int mana;
		int stamina;

		/* Main Attributes */
		int endurance;		/* Affects health */
		int intelligence;	/* Affects mana */
		int agility;		/* Affects stamina */
		int strength;		/* Affects carry weight */
		int personality;
		int perception;
		int luck;

		/* Derived Attributes */
		int maxhealth;
		int maxmana;
		int maxstamina;
		int carryweight;
	public:
		/* Sets & Gets for current stats */
		void set_name(std::string n);
		std::string get_name();
		void set_level(int l);
		int get_level();

		void set_health(int h);
		int get_health();
		void set_mana(int m);
		int get_mana();
		void set_stamina(int s);
		int get_stamina();

		/* Sets & Gets for main attributes */
		void set_endurance(int e);
		int get_endurance();
		void set_intelligence(int i);
		int get_intelligence();
		void set_agility(int a);
		int get_agility();
		void set_personality(int p);
		int get_personality();
		void set_perception(int p);
		int get_perception();
		void set_luck(int l);
		int get_luck();

		/* Sets & Gets for derived attributes */
		void set_maxhealth(int h);
		int get_maxhealth();
		void set_maxmana(int m);
		int get_maxmana();
		void set_maxstamina(int s);
		int get_maxstamina();
		void set_carryweight(int c);
		int get_carryweight();
};

#endif
