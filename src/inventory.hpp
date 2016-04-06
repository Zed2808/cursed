#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "attacks.hpp"
#include "items.hpp"

class Entry {
    public:
        Item * item;
        int quantity;

        Entry();
        Entry(Item * new_item, int n);
};

class Inventory {
    public:
        std::vector<Entry> slots;
        int totalweight;

        Inventory();
        void additem(Item * item, int n);
        void removeitem(Item * item, int n);
};

class EquipSlot {
    public:
        Weapon * equipped;
        Attack attack1;
        Attack attack2;

        EquipSlot();
        void equip(Inventory &inventory, Weapon * Weapon); /* Moves 1 of item from inventory to EquipSlot */
        void unequip(Inventory &inventory);                /* Moves item in equip slot back to inventory */
};

#endif
