#include "Appetiser.h"
using namespace std;
#include <sstream>

Appetiser::Appetiser(string name, double price, int calories, bool shareable, bool twoForOne)
	: Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

string Appetiser::toString()
{
	ostringstream oss;
	oss << getName() << " - $" << getPrice() << " - " << getCalories() << " calories";
    if (shareable) {
        oss << " - Shareable";
    }
    if (twoForOne) {
        oss << " - 2-4-1";
    }
    return oss.str();
}




