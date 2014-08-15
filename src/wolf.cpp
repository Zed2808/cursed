#include <string>
#include "wolf.hpp"

Wolf::Wolf(int l) {
	name = "Wolf";
	level = l;
	maxhealth = 10;
	health = maxhealth;
	maxmana = 0;
	mana = maxmana;
	maxstamina = 10;
	stamina = maxstamina;
}
