#include <iostream>
#include <string>
using namespace std;

void addProduct(int productIDs[], string productNames[], int productQuantities[], double productPrices[], int& count) {
    if (count >= 100) {
        cout << "Inventory full! Cannot add more products.\n";
        return;
    }

    cout << "Enter product ID: ";
    cin >> productIDs[count];

    cout << "Enter product name: ";
    cin >> productNames[count];

    cout << "Enter product quantity: ";
    cin >> productQuantities[count];

    cout << "Enter product price: ";
    cin >> productPrices[count];

    count++;
}

void updateQuantity(int productIDs[], string productNames[], int productQuantities[], int count) {
    int id;
    cout << "Enter product ID to update: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (productIDs[i] == id) {
            cout << "Enter new quantity for " << productNames[i] << ": ";
            cin >> productQuantities[i];
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found!\n";
    }
}

double calculateTotalValue(int productQuantities[], double productPrices[], int count) {
    double totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += productQuantities[i] * productPrices[i];
    }
    return totalValue;
}

int main() {
    int productIDs[100];
    string productNames[100];
    int productQuantities[100];
    double productPrices[100];
    int count = 0;

    int choice;
    do {
           cout << " Inventory Management System" << endl
                << " 1. Add new product" << endl
                << " 2. Update product quantity" << endl
                << " 3. Calculate total value" << endl
                << " 4. Exit" << endl
                << " Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(productIDs, productNames, productQuantities, productPrices, count);
                break;
            case 2:
                updateQuantity(productIDs, productNames, productQuantities, count);
                break;
            case 3:
                cout << "Total value of all products: " << calculateTotalValue(productQuantities, productPrices, count) << endl;
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

