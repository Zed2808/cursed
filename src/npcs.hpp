#ifndef NPCS_H
#define NPCS_H

#include "character.hpp"

class Wolf : public Character {
	public:
		Wolf(int l);
};

class Rat : public Character {
	public:
		Rat(int l);
};

#endif
