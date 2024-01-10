#pragma once
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Item
{
public:
	Item(std::string name, double price, int calories);
	virtual ~Item() = default;


	std::string getName() ;
	double getPrice() ;
	int getCalories() ;
	virtual string toString();
protected:

	int calories;
	string name;
	float price;
	
};

