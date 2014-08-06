#include <string>
#include "character.h"

void Character::set_name(std::string n) {
	name = n;
}

void Character::set_level(int l) {
	level = l;
}

void Character::set_maxhealth(int h) {
	maxhealth = h;
}

void Character::set_health(int h) {
	health = h;
}

void Character::set_maxmana(int m) {
	maxmana = m;
}

void Character::set_mana(int m) {
	mana = m;
}

void Character::set_maxstamina(int s) {
	maxstamina = s;
}

void Character::set_stamina(int s) {
	stamina = s;
}

std::string Character::get_name() {
	return name;
}

int Character::get_level() {
	return level;
}

int Character::get_maxhealth() {
	return maxhealth;
}

int Character::get_health() {
	return health;
}

int Character::get_maxmana() {
	return maxmana;
}

int Character::get_mana() {
	return mana;
}

int Character::get_maxstamina() {
	return maxstamina;
}

int Character::get_stamina() {
	return stamina;
}
