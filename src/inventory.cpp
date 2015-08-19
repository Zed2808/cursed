#include <algorithm>
#include "inventory.hpp"
#include "items.hpp"

/*
 * Inventory
 */
Inventory::Inventory() {
    totalweight = 0;
    std::fill_n(slots, 256, Item());
    std::fill_n(quantity, 256, 0);
}

/* Function: additem
 *   Adds item to first available slot in inventory
 *
 *   item: item to add
 *   n: number of item to add
 *
 *   Returns slot in inventory item was added to
 */
int Inventory::additem(Item item, int n) {
    for(int i = 0; i <= 255; i++) {         /* Loop to search for matching itemid */
        if(slots[i].id == item.id) {        /* If itemid in slot matches that of the item we're trying to add */
            quantity[i] += n;               /* Don't change item in slot, just add n to quantity of that slot */
            totalweight += item.weight * n; /* Add item's weight * n to inventory weight */
            return i;                       /* Return index of slot of which the quantity was increased */
        }
    }

    for(int i = 0; i <= 255; i++) {         /* Loop to search for empty slot */
        if(quantity[i] == 0) {              /* Slot is empty */
            slots[i] = item;                /* Set empty slot to item */
            quantity[i] = n;                /* Set quantity of the slot to n */
            totalweight += item.weight * n; /* Add item's weight * n to inventory weight */
            return i;                       /* Return index of slot that item was added to */
        }
    }

    return -1; /* Return -1 if item could not be added to a slot */
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
int Inventory::removeitem(Item item, int n) {
    for(int i = 0; i <= 255; i++) {                       /* Loop to search for matching itemid */
        if(slots[i].id == item.id) {                      /* If itemid in slot matches that of the item we're trying to remove */
            if(n >= quantity[i]) {
                totalweight -= item.weight * quantity[i];
                quantity[i] = 0;                          /* Set quantity to 0 to avoid negative quantities */
                slots[i] = Item();                        /* Set item in slot to empty item */
            } else {
                totalweight -= item.weight * n;
                quantity[i] -= n;
            }
            return i; /* Return index item was removed from */
        }
    }
    return -1; /* Return -1 if item could not be removed */
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
