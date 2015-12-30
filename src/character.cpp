#include <string>
#include "character.hpp"

Character::Character() {
    name = "";
    num_id = 0xff;
    str_id = "void";
    level = 0;
    hostile = false;
    symbol = ' ';
    color_pair = 0;
    row = 0;
    col = 0;
    maxhealth = 0;
    health = 0;
    maxmana = 0;
    mana = 0;
    maxstamina = 0;
    stamina = 0;
}

/* Sets & Gets for main attributes */
void Character::set_endurance(int e) {
    endurance = e;
    maxhealth = endurance * 20;
    health = maxhealth;
}

int Character::get_endurance() {
    return endurance;
}

void Character::set_intelligence(int i) {
    intelligence = i;
    maxmana = intelligence * 20;
    mana = maxmana;
}

int Character::get_intelligence() {
    return intelligence;
}

void Character::set_agility(int a) {
    agility = a;
    maxstamina = agility * 10;
    stamina = maxstamina;
}

int Character::get_agility() {
    return agility;
}

void Character::set_strength(int s) {
    strength = s;
    carryweight = strength * 20;
}

int Character::get_strength() {
    return strength;
}

void Character::set_personality(int p) {
    personality = p;
}

int Character::get_personality() {
    return personality;
}

void Character::set_perception(int p) {
    perception = p;
}

int Character::get_perception() {
    return perception;
}

void Character::set_luck(int l) {
    luck = l;
}

int Character::get_luck() {
    return luck;
}

/* Gets for derived attributes */
int Character::get_maxhealth() {
    return maxhealth;
}

int Character::get_maxmana() {
    return maxmana;
}

int Character::get_maxstamina() {
    return maxstamina;
}

int Character::get_carryweight() {
    return carryweight;
}
