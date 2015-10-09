#ifndef ATTACKS_H
#define ATTACKS_H

// TODO: No attack functions because I plan on implementing it
// inside a section for combat stuff within game flow stuff

class Attack {
    public:
        Attack();
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

#endif
