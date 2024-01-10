#include "Order.h"

#include <iostream>
#include <fstream>
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"


Order::Order()
    : ItemList() {} // Initialize the base class constructor

Order::~Order() {
    for (Item* item : items) {
        delete item; // Free memory for order items
    }
}

void Order::calculateTotal()
{
    double total = 0.0;
    int eligibleForDiscount = 0;

    for (Item* item : items) {
        total += item->getPrice();

        // Check if the item is an appetizer eligible for 2-4-1 discount
        if (dynamic_cast<Appetiser*>(item) != nullptr) {
            eligibleForDiscount++;
        }
    }

    // Apply 2-4-1 discount for eligible appetizers
    total -= (eligibleForDiscount / 2) * dynamic_cast<Appetiser*>(items[0])->getPrice();

    cout << "Total: £" << total << endl;
}


void Order::printReceipt()
{
    ofstream receiptFile("receipt.txt");
    if (!receiptFile.is_open()) {
        std::cerr << "Error creating receipt file." << std::endl;
        return;
    }

    receiptFile << toString() << std::endl;
    calculateTotal();
    receiptFile.close();

    cout << "Receipt saved to receipt.txt" << endl;
}

void Order::add(Item* newItem) {
    if (newItem != nullptr) {
        items.push_back(newItem); 
        cout << "Item added to the order." << endl;
    }
    else {
        cerr << "Invalid item pointer. Please provide a valid item to add." << endl;
    }
}




void Order::remove(int index) {
    if (index >= 1 && static_cast<size_t>(index) <= items.size()) {
        delete items[index - 1]; // Free memory for the removed item
        items.erase(items.begin() + index - 1);
        std::cout << "Item removed from the order." << std::endl;
    }
    else {
        std::cerr << "Invalid index. Please enter a valid index to remove an item." << std::endl;
    }
}


string Order::toString()
{
    string orderString = "Order:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        orderString += std::to_string(i + 1) + ". " + items[i]->toString() + "\n";
    }
    return orderString;
}
 


