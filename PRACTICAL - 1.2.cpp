#include <iostream>
#include <vector>
#include <string>
using namespace std;

// --- Procedural Approach ---

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

vector<Product> inventory;

void addProduct(int id, const string& name, int quantity, double price) {
    Product product = {id, name, quantity, price};
    inventory.push_back(product);
}

void updateQuantity(int id, int quantity) {
    for (auto& product : inventory) {
        if (product.id == id) {
            product.quantity = quantity;
            break;
        }
    }
}

double totalValue() {
    double total = 0;
    for (const auto& product : inventory) {
        total += product.quantity * product.price;
    }
    return total;
}

// --- Object-Oriented Approach ---

class ProductClass {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    ProductClass(int id, const string& name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {}

    int getId() const { return id; }

    void updateQuantity(int newQuantity) { quantity = newQuantity; }

    double totalValue() const { return quantity * price; }

    void displayProduct() const {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};

class Inventory {
private:
    vector<ProductClass> products;

public:
    void addProduct(int id, const string& name, int quantity, double price) {
        products.push_back(ProductClass(id, name, quantity, price));
    }

    void updateQuantity(int id, int quantity) {
        for (auto& product : products) {
            if (product.getId() == id) {
                product.updateQuantity(quantity);
                break;
            }
        }
    }

    double totalValue() const {
        double total = 0;
        for (const auto& product : products) {
            total += product.totalValue();
        }
        return total;
    }

    void displayInventory() const {
        for (const auto& product : products) {
            product.displayProduct();
        }
    }
};

int main() {
    int choice;
    bool running = true;
    int approachChoice;

    cout << "Choose Approach : \n";
    cout << "1. Procedural Approach\n";
    cout << "2. Object-Oriented Approach\n";
    cout << "Enter your choice : ";
    cin >> approachChoice;

    if (approachChoice != 1 && approachChoice != 2) {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }

    if (approachChoice == 1) {
        // --- Procedural Approach ---
        cout << "\nProcedural Approach - Inventory Management" << endl;

        while (running) {
            cout << "\nChoose an option (Procedural Approach) :\n";
            cout << "1. Add Product\n2. Update Quantity\n3. View Total Value\n4. Exit\n";
            cout << "Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int id, quantity;
                    string name;
                    double price;
                    cout << "Enter Product ID : ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Product Name : ";
                    getline(cin, name);
                    cout << "Enter Quantity : ";
                    cin >> quantity;
                    cout << "Enter Price : $";
                    cin >> price;
                    addProduct(id, name, quantity, price);
                    break;
                }
                case 2: {
                    int id, quantity;
                    cout << "Enter Product ID to update : ";
                    cin >> id;
                    cout << "Enter new Quantity : ";
                    cin >> quantity;
                    updateQuantity(id, quantity);
                    break;
                }
                case 3:
                    cout << "Total Inventory Value : $" << totalValue() << endl;
                    break;
                case 4:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        }
    }
    else if (approachChoice == 2) {
        // --- Object-Oriented Approach ---
        cout << "\nObject-Oriented Approach - Inventory Management" << endl;

        Inventory inventoryObj;
        running = true;

        while (running) {
            cout << "\nChoose an option (Object-Oriented Approach) :\n";
            cout << "1. Add Product\n2. Update Quantity\n3. View Total Value\n4. View All Products\n5. Exit\n";
            cout << "Enter your choice : ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int id, quantity;
                    string name;
                    double price;
                    cout << "Enter Product ID : ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Product Name : ";
                    getline(cin, name);
                    cout << "Enter Quantity : ";
                    cin >> quantity;
                    cout << "Enter Price : $";
                    cin >> price;
                    inventoryObj.addProduct(id, name, quantity, price);
                    break;
                }
                case 2: {
                    int id, quantity;
                    cout << "Enter Product ID to update : ";
                    cin >> id;
                    cout << "Enter new Quantity : ";
                    cin >> quantity;
                    inventoryObj.updateQuantity(id, quantity);
                    break;
                }
                case 3:
                    cout << "Total Inventory Value : $" << inventoryObj.totalValue() << endl;
                    break;
                case 4:
                    cout << "\nAll Products in Inventory :" << endl;
                    inventoryObj.displayInventory();
                    break;
                case 5:
                    running = false;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        }
    }
    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
