#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
	protected:
		std::string name;
		int itemid;
		int weight;
	public:
		Item();
		std::string get_name();
		int get_itemid();
		int get_weight();
};

class Weapon : public Item {
	protected:
		int damage;
	public:
		Weapon();
		int get_damage();
};

class BladedWeapon : public Weapon {
	
};

class BluntWeapon : public Weapon {
	
};

class PoleWeapon : public Weapon {
	
};

class RangedWeapon : public Weapon {
	
};

#endif
