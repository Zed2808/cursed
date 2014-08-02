#include "player.h"
#include <string>

Player::Player() {
	name = "Player Name";
	health = 100;
	mana = 100;
	stamina = 100;
}

void Player::set_name(std::string n) {
	name = n;
}

void Player::set_health(int h) {
	health = h;
}

void Player::set_mana(int m) {
	mana = m;
}

void Player::set_stamina(int s) {
	stamina = s;
}

std::string Player::get_name() {
	return name;
}

int Player::get_health() {
	return health;
}

int Player::get_mana() {
	return mana;
}

int Player::get_stamina() {
	return stamina;
}
