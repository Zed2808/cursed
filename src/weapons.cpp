#include <string>
#include "weapons.hpp"
#include "character.hpp"

/* Weapon */
Weapon::Weapon() {
	damage = 0;
}

/* Bladed Weapon */
void BladedWeapon::swing(Character &target) {
	
}

void BladedWeapon::stab(Character &target) {
	
}

/* Blunt Weapon */
void BluntWeapon::swing(Character &target) {
	
}

void BluntWeapon::push(Character &target) {
	
}

/* Pole Weapon */
void PoleWeapon::swing(Character &target) {
	
}

void PoleWeapon::push(Character &target) {
	
}

/* Ranged Weapon */
void RangedWeapon::shoot(Character &target) {
	
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
