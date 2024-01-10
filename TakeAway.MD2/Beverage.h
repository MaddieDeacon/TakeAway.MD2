#pragma once
#include "Item.h"

class Beverage : public Item
{
public:
	Beverage(string name, double price, int calories, double abv, int volume);
	bool isAlcoholic();
	string toString();
private:
	float abv;
	int volume;
};

