#include <string>
#include "character.h"

/* Sets & Gets for current stats */
void Character::set_name(std::string n) { name = n; }
std::string Character::get_name() {	return name; }
void Character::set_level(int l) { level = l; }
int Character::get_level() { return level; }

void Character::set_health(int h) { health = h; }
int Character::get_health() { return health; }
void Character::set_mana(int m) { mana = m; }
int Character::get_mana() { return mana; }
void Character::set_stamina(int s) { stamina = s; }
int Character::get_stamina() { return stamina; }

/* Sets & Gets for main attributes */
void Character::set_endurance(int e) { endurance = e; }
int Character::get_endurance() { return endurance; }
void Character::set_intelligence(int i) { intelligence = i; }
int Character::get_intelligence() { return intelligence; }
void Character::set_agility(int a) { agility = a; }
int Character::get_agility() { return agility; }
void Character::set_personality(int p) { personality = p; }
int Character::get_personality() { return personality; }
void Character::set_perception(int p) { perception = p; }
int Character::get_perception() { return perception; }
void Character::set_luck(int l) { luck = l; }
int Character::get_luck() { return luck; }

/* Sets & Gets for derived attributes */
void Character::set_maxhealth(int h) { maxhealth = h; }
int Character::get_maxhealth() { return maxhealth; }
void Character::set_maxmana(int m) { maxmana = m; }
int Character::get_maxmana() { return maxmana; }
void Character::set_maxstamina(int s) { maxstamina = s; }
int Character::get_maxstamina() { return maxstamina; }
void Character::set_carryweight(int c) { carryweight = c; }
int Character::get_carryweight() { return carryweight; }
