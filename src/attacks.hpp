#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>

// TODO: No attack functions because I plan on implementing it
// inside a section for combat stuff within game flow stuff

class Attack {
    public:
        Attack();
        std::string name;
        int damage;
        double penetration;
        int range;
};

class Slash : public Attack {
    public:
        Slash();
};

class Stab : public Attack {
    public:
        Stab();
};

class Chop : public Attack {
    public:
        Chop();
};

class Smash : public Attack {
    public:
        Smash();
};

#endif
