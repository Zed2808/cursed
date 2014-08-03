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

void Player::set_level(int l) {
	level = l;
}

void Player::set_maxhealth(int h) {
	maxhealth = h;
}

void Player::set_health(int h) {
	health = h;
}

void Player::set_maxmana(int m) {
	maxmana = m;
}

void Player::set_mana(int m) {
	mana = m;
}

void Player::set_maxstamina(int s) {
	maxstamina = s;
}

void Player::set_stamina(int s) {
	stamina = s;
}

std::string Player::get_name() {
	return name;
}

int Player::get_level() {
	return level;
}

int Player::get_maxhealth() {
	return maxhealth;
}

int Player::get_health() {
	return health;
}

int Player::get_maxmana() {
	return maxmana;
}

int Player::get_mana() {
	return mana;
}

int Player::get_maxstamina() {
	return maxstamina;
}

int Player::get_stamina() {
	return stamina;
}
