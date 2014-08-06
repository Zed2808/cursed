#include <string>
#include "enemy.h"

void Enemy::set_maxhealth(int h) {
	maxhealth = h;
}

void Enemy::set_health(int h) {
	health = h;
}

void Enemy::set_maxmana(int m) {
	maxmana = m;
}

void Enemy::set_mana(int m) {
	mana = m;
}

void Enemy::set_maxstamina(int s) {
	maxstamina = s;
}

void Enemy::set_stamina(int s) {
	stamina = s;
}

std::string Enemy::get_name() {
	return name;
}

int Enemy::get_level() {
	return level;
}

int Enemy::get_maxhealth() {
	return maxhealth;
}

int Enemy::get_health() {
	return health;
}

int Enemy::get_maxmana() {
	return maxmana;
}

int Enemy::get_mana() {
	return mana;
}

int Enemy::get_maxstamina() {
	return maxstamina;
}

int Enemy::get_stamina() {
	return stamina;
}
