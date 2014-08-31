#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item {
	protected:
		std::string name;
		int itemid;
		int weight;
	public:
		Item();
		std::string get_name();
		int get_itemid();
		int get_weight();
};

class Shortsword : public Item {
	private:
		int damage;
	public:
		Shortsword();
		int get_damage();
};

#endif
