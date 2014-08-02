#ifndef PLAYER_H
#define PLAYER_H

class Player {
	private:
		int health;
		int mana;
		int stamina;
	public:
		Player();
		void set_health(int x);
		void set_mana(int x);
		void set_stamina(int x);
		int get_health();
		int get_mana();
		int get_stamina();
};

#endif
