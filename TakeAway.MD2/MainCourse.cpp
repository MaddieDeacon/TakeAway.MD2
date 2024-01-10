#include "MainCourse.h"
#include <sstream>
using namespace std;

MainCourse::MainCourse(std::string name, double price, int calories)
	: Item(name, price, calories) {}

string MainCourse::toString()  {
    ostringstream oss;
    oss << getName() << " - $" << getPrice() << " - " << getCalories() << " calories";
    return oss.str();
}