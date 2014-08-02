#include "player.h"

Player::Player()
{
	health = 100;
	mana = 100;
	stamina = 100;
}

void Player::set_health(int x) {
	health = x;
}

void Player::set_mana(int x) {
	mana = x;
}

void Player::set_stamina(int x) {
	stamina = x;
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
