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

Character get_npc_from_id(unsigned char id, unsigned char level);

#endif
