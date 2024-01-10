#pragma once
#include "Item.h"
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class ItemList
{
public:
	virtual ~ItemList();
	
	void addItem(Item* item);
	void removeItem(int index);
	 vector<Item*>& getItems() ;
	 virtual std::string toString() = 0;
protected:
	vector<Item*> items;
};

