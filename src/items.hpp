#ifndef ITEMS_H
#define ITEMS_H

class Item {
	protected:
		int weight;
	public:
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
