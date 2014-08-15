#include "items.h"

/* Base Item */
int Item::get_weight() {
	return weight;
}

/* Shortsword */
Shortsword::Shortsword() {
	weight = 5;
	damage = 8;
}

int Shortsword::get_damage() {
	return damage;
}
