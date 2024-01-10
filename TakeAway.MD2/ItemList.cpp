#include "ItemList.h"
using namespace std;


ItemList::~ItemList()
{
}

void ItemList::addItem(Item* item)
{
	items.push_back(item);
}

void ItemList::removeItem(int index)
{
    if (index >= 1 && static_cast<size_t>(index) <= items.size()) {
        delete items[index - 1]; // Free memory for the removed item
        items.erase(items.begin() + index - 1);
        cout << "Item removed from the order." << endl;
    }
    else {
        cerr << "Invalid index. Please enter a valid index to remove an item." << endl;
    }
}

vector<Item*>& ItemList::getItems()
{
    return items;
}



