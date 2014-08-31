#include <string>
#include "items.hpp"

/* Base Item */
Item::Item() {
	name = "";
	weight = 0;
}

std::string Item::get_name() {
	return name;
}

int Item::get_weight() {
	return weight;
}

/* 1 - Shortsword */
Shortsword::Shortsword() {
	name = "Shortsword";
	weight = 5;
	damage = 8;
}

int Shortsword::get_damage() {
	return damage;
}
