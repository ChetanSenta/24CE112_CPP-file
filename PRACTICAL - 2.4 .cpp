#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    InventoryItem() {
        itemID = 0;
        itemName = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    InventoryItem(int id, string name, double pr, int qty) {
        itemID = id;
        itemName = name;
        price = pr;
        quantity = qty;
    }

    void addStock(int qty) {
        if (qty > 0) {
            quantity += qty;
            cout << "Added " << qty << " items to stock." << endl;
        } else {
            cout << "Invalid quantity to add!" << endl;
        }
    }

    void sellItem(int qty) {
        if (qty > 0 && qty <= quantity) {
            quantity -= qty;
            cout << "Sold " << qty << " items." << endl;
        } else if (qty <= 0) {
            cout << "Quantity to sell must be positive!" << endl;
        } else {
            cout << "Insufficient stock! Only " << quantity << " items available." << endl;
        }
    }

    void displayItem() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity in stock: " << quantity << endl;
    }
};

int main() {
    const int NUM_ITEMS = 3;
    InventoryItem inventory[NUM_ITEMS];

    inventory[0] = InventoryItem(101, "Laptop", 800.0, 10);
    inventory[1] = InventoryItem(102, "Smartphone", 500.0, 20);
    inventory[2] = InventoryItem(103, "Headphones", 50.0, 50);

    int choice, itemIndex, qty;

    do {
        cout << "Menu:\n";
        cout << "1. Add stock to an item\n";
        cout << "2. Sell items\n";
        cout << "3. Display item details\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item number (1 - Laptop, 2 - Smartphone, 3 - Headphones): ";
                cin >> itemIndex;
                cout << "Enter quantity to add: ";
                cin >> qty;
                if (itemIndex >= 1 && itemIndex <= NUM_ITEMS) {
                    inventory[itemIndex - 1].addStock(qty);
                } else {
                    cout << "Invalid item number!" << endl;
                }
                break;

            case 2:
                cout << "Enter the item number (1 - Laptop, 2 - Smartphone, 3 - Headphones): ";
                cin >> itemIndex;
                cout << "Enter quantity to sell: ";
                cin >> qty;
                if (itemIndex >= 1 && itemIndex <= NUM_ITEMS) {
                    inventory[itemIndex - 1].sellItem(qty);
                } else {
                    cout << "Invalid item number!" << endl;
                }
                break;

            case 3:
                cout << "Enter the item number (1 - Laptop, 2 - Smartphone, 3 - Headphones): ";
                cin >> itemIndex;
                if (itemIndex >= 1 && itemIndex <= NUM_ITEMS) {
                    inventory[itemIndex - 1].displayItem();
                } else {
                    cout << "Invalid item number!" << endl;
                }
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

