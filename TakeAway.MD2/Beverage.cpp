#include "Beverage.h"
#include <sstream>
using namespace std; 


Beverage::Beverage(string name, double price, int calories, double abv, int volume)
	: Item(name, price, calories), abv(abv), volume(volume) {}

bool Beverage::isAlcoholic()
{
	return abv > 0.0;
}

string Beverage::toString()
{
	ostringstream oss;
	oss << getName() << " - $" << getPrice() << " - " << getCalories() << " calories - " << abv << "% ABV - " << volume << " ml";
	return oss.str();
}
	


