#ifndef INVENTORY_H
#define INVENTORY_H

#include "items.h"

class Inventory {
	private:
		int totalweight;
		int slots[256];
	public:
		Inventory();
		int additem(Item item, int quantity);    /* Returns slot item was added to */
		int removeitem(Item item, int quantity); /* Returns slot item was removed from */
};

#endif
