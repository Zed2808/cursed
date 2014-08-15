#include <algorithm>
#include "inventory.h"

Inventory::Inventory() {
	totalweight = 0;
	std::fill_n(slots, 256, 0);
}

/* Function: additem
 *   Adds item to first available slot in inventory
 *
 *   item: item to add
 *   quantity: number of item to add
 *
 *   Returns slot in inventory item was added to
 */
int Inventory::additem(Item item, int quantity) {
	return 0;
}

/* Function: removeitem
 *   Searches inventory for item and removes it
 *
 *   item: item to search for for removal
 *   quantity: number of item to remove
 *
 *   Returns slot in inventory item was removed from
 */
int Inventory::removeitem(Item item, int quantity) {
	return 0;
}
