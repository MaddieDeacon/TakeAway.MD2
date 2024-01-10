#pragma once
#include "ItemList.h"
using namespace std;

class Menu : public ItemList
{
public:
	Menu(string filename);
	~Menu();
	string toString();
private:
	void loadMenu(string filePath);
};



