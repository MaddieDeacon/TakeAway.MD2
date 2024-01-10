#include "Menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include "Takeaway.cpp"
using namespace std;

Menu::Menu(string filename)
    : ItemList()
{
    ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            char itemType;
            string name;
            double price;
            int calories;
            bool shareable;
            bool twoForOne;
            double abv;
            int volume;

            if (!(iss >> itemType >> name >> price >> calories)) {
                cerr << "Error parsing line: " << line << endl;
                continue;
            }

            if (itemType == 'a') {
                if (!(iss >> shareable >> twoForOne)) {
                    cerr << "Error parsing line: " << line << endl;
                    continue;
                }
                addItem(new Appetiser(name, price, calories, shareable, twoForOne));
            }
            else if (itemType == 'm') {
                addItem(new MainCourse(name, price, calories));
            }
            else if (itemType == 'b') {
                if (!(iss >> abv >> volume)) {
                    cerr << "Error parsing line: " << line << endl;
                    continue;
                }
                addItem(new Beverage(name, price, calories, abv, volume));
            }
            else {
                cerr << "Unknown item type: " << itemType << endl;
            }
        }

        file.close();
    }

Menu::~Menu()
{
	for (Item* item : items) {
		delete item; // Free memory for menu items
	}
}

string Menu::toString()
{
	string menuString = "Menu:\n";
	for (size_t i = 0; i < items.size(); ++i) {
		menuString += to_string(i + 1) + ". " + items[i]->toString() + "\n";
	}
	return string();
}









