#include "Item.h"
using namespace std;

	Item::Item(string name, double price, int calories)
		: name(name), price(price), calories(calories) {}

	string Item::getName()
	{
		return string();
	}

	double Item::getPrice()
	{
		return 0.0;
	}

	int Item::getCalories()
	{
		return 0;
	}

	string Item::toString()
	{
		return name + " - $" + to_string(price) + " - " + to_string(calories) + " calories";
	}

