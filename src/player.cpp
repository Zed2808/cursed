#include "player.h"
#include <string>

Player::Player(std::string n) {
	name = n;
	level = 1;
	maxhealth = 100;
	health = 100;
	maxmana = 100;
	mana = 100;
	maxstamina = 100;
	stamina = 100;
}
