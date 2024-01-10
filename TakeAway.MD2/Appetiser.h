#pragma once
#include "Item.h"

class Appetiser : public Item
{
public:
	Appetiser(string name, double price, int calories, bool shareable, bool twoForOne);
	string toString();
private:
	bool shareable;
	bool twoForOne;
};

