#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Product(int id = 0, string name = "", int quantity = 0, double price = 0.0)
        : id(id), name(name), quantity(quantity), price(price) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int quantity) { this->quantity = quantity; }
    void setProductDetails(int id, string name, int quantity, double price) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    double getTotalValue() const { return quantity * price; }

    void updateQuantity(int newQuantity) {
        this->quantity = newQuantity;
    }
};

class Inventory {
private:
    Product products[MAX_PRODUCTS];
    int count;

public:
    Inventory() : count(0) {}

    void addProduct() {
        if (count >= MAX_PRODUCTS) {
            cout << "Inventory is full! Cannot add more products.\n";
            return;
        }

        int id;
        string name;
        int quantity;
        double price;

        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, name);

        cout << "Enter product quantity: ";
        cin >> quantity;

        cout << "Enter product price: ";
        cin >> price;

        products[count].setProductDetails(id, name, quantity, price);
        count++;
    }

    void updateQuantity() {
        int id;
        cout << "Enter product ID to update: ";
        cin >> id;

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (products[i].getId() == id) {
                int newQuantity;
                cout << "Enter new quantity for " << products[i].getName() << ": ";
                cin >> newQuantity;
                products[i].updateQuantity(newQuantity);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Product not found!\n";
        }
    }

    double calculateTotalValue() {
        double totalValue = 0;
        for (int i = 0; i < count; i++) {
            totalValue += products[i].getTotalValue();
        }
        return totalValue;
    }

    void displayProducts() {
        if (count == 0) {
            cout << "No products in inventory.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "ID: " << products[i].getId()
                 << ", Name: " << products[i].getName()
                 << ", Quantity: " << products[i].getQuantity()
                 << ", Price: " << products[i].getPrice()
                 << ", Total Value: " << products[i].getTotalValue() << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "Inventory Management System\n";
        cout << "1. Add new product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Calculate total value\n";
        cout << "4. Display all products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.updateQuantity();
                break;
            case 3:
                cout << "Total value of all products: " << inventory.calculateTotalValue() << endl;
                break;
            case 4:
                inventory.displayProducts();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
