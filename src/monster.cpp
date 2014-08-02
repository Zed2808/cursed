#include <string>
#include "monster.h"

void Monster::set_maxhealth(int h) {
	maxhealth = h;
}

void Monster::set_health(int h) {
	health = h;
}

void Monster::set_maxmana(int m) {
	maxmana = m;
}

void Monster::set_mana(int m) {
	mana = m;
}

void Monster::set_maxstamina(int s) {
	maxstamina = s;
}

void Monster::set_stamina(int s) {
	stamina = s;
}

std::string Monster::get_name() {
	return name;
}

int Monster::get_maxhealth() {
	return maxhealth;
}

int Monster::get_health() {
	return health;
}

int Monster::get_maxmana() {
	return maxmana;
}

int Monster::get_mana() {
	return mana;
}

int Monster::get_maxstamina() {
	return maxstamina;
}

int Monster::get_stamina() {
	return stamina;
}
