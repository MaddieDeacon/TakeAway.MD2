#pragma once
#include "ItemList.h"

class Order : public ItemList
{
public:
	Order();
	void calculateTotal();
	void printReceipt();
	void add(Item* newItem);
	void remove(int index);
	string toString();
private:
	float total;
};

