#include <algorithm>
#include "inventory.hpp"
#include "items.hpp"

/*
 * Entry
 */
Entry::Entry() {
    item = Item();
    quantity = 0;
}

Entry::Entry(Item new_item, int n) {
    item = new_item;
    quantity = n;
}

/*
 * Inventory
 */
Inventory::Inventory() {
    totalweight = 0;
}

/* Function: additem
 *   Adds item to first available slot in inventory
 *
 *   item: item to add
 *   n: number of item to add
 *
 */
void Inventory::additem(Item item, int n) {
    bool item_added = false;

    /* Iterate through entries searching for existing entry for item */
    for(unsigned int i = 0; i < slots.size(); i++) {
        /* Existing entry found for item at slots[i] */
        if(slots[i].item.id == item.id) {
            slots[i].quantity += n;
            totalweight += item.weight * n;

            item_added = true;
        }
    }

    /* If existing entry was not found, create new entry for item */
    if(!item_added) {
        slots.push_back(Entry(item, n));
        totalweight += item.weight * n;
    }
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
void Inventory::removeitem(Item item, int n) {
    /* Iterate through entries searching for existing entry for item */
    for(unsigned int i = 0; i < slots.size(); i++) {
        /* Existing entry found for item */
        if(slots[i].item.id == item.id) {
            /* Removing more of an item than is listed in entry */
            if(n >= slots[i].quantity) {
                totalweight -= item.weight * slots[i].quantity; /* Only decrement totalweight by weight of items being removed */
                slots.erase(slots.begin() + i);                 /* Remove entire entry at */
            } else {
                totalweight -= item.weight * n;
                slots[i].quantity -= n;
            }
        }
    }
}

/*
 * EquipSlot
 */
EquipSlot::EquipSlot() {
    equipped = Item();
}

/* Function: equip
 *   Moves 1 of specified item from inventory to equip slot
 *
 *   inventory: inventory to remove item from
 *   item: item to equip from inventory
 */
void EquipSlot::equip(Inventory &inventory, Item item) {
    inventory.removeitem(item, 1);
    equipped = item;
}

/* Function: unequip
 *   Moves item from equip slot back into inventory
 *
 *   inventory: inventory to move item back into
 */
void EquipSlot::unequip(Inventory &inventory) {
    inventory.additem(equipped, 1);
    equipped = Item();
}
