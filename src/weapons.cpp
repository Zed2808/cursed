#include <string>
#include "weapons.hpp"
#include "character.hpp"

/* Weapon */
Weapon::Weapon() {
	damage = 0;
}

/* 1 - Shortsword */
Shortsword::Shortsword() {
	name = "Shortsword";
	itemid = 1;
	weight = 5;
	damage = 8;
}

/* 2 - Longsword */
BattleAxe::BattleAxe() {
	name = "Battle Axe";
	itemid = 2;
	weight = 8;
	damage = 11;
}
