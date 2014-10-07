#ifndef WEAPONS_H
#define WEAPONS_H

#include "items.hpp"
#include "character.hpp"

class Weapon : public Item {
	protected:
		int damage;
	public:
		Weapon();
		int get_damage();
		/* Get weapon's attacks */
};

class BladedWeapon : public Weapon {
	public:
		void swing(Character &target);
		void stab(Character &target);
};

class BluntWeapon : public Weapon {
	public:
		void swing(Character &target);
		void push(Character &target);
};

class PoleWeapon : public Weapon {
	public:
		void swing(Character &target);
		void push(Character &target);
};

class RangedWeapon : public Weapon {
	public:
		void shoot(Character &target);
};

class Shortsword : public BladedWeapon {
	public:
		Shortsword();
};

class BattleAxe : public BluntWeapon {
	public:
		BattleAxe();
};

#endif
