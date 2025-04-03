#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPersonDetails() const {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(string n, int a, int id) : Person(n, a), employeeID(id) {}

    void displayEmployeeDetails() const {
        displayPersonDetails();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id), department(dept) {}

    Manager() : Employee("", 0, 0), department("") {}

    void displayManagerDetails() const {
        displayEmployeeDetails();
        cout << "Department: " << department << endl;
    }
};

// STL Approach: Using std::map to store Manager objects by employeeID
void computeUsingMap() {
    map<int, Manager> managerMap;
    int numManagers;

    cout << "Enter the number of Managers (STL approach): ";
    cin >> numManagers;

    for (int i = 0; i < numManagers; ++i) {
        string name, department;
        int age, employeeID;

        cout << "\nEnter details for Manager " << (i + 1) << ":\n";

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Employee ID: ";
        cin >> employeeID;

        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        Manager manager(name, age, employeeID, department);
        managerMap[employeeID] = manager;
    }

    cout << "\nManager details:\n";
    for (const auto& entry : managerMap) {
        cout << "\nManager with Employee ID " << entry.first << ":\n";
        entry.second.displayManagerDetails();
    }
}

// Non-STL Approach: Using basic arrays to store Manager objects
void computeUsingArray() {
    int numManagers;

    cout << "Enter the number of Managers (Non-STL approach): ";
    cin >> numManagers;

    Manager* managers = new Manager[numManagers];

    for (int i = 0; i < numManagers; ++i) {
        string name, department;
        int age, employeeID;

        cout << "\nEnter details for Manager " << (i + 1) << ":\n";

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "Employee ID: ";
        cin >> employeeID;

        cout << "Department: ";
        cin.ignore();
        getline(cin, department);

        managers[i] = Manager(name, age, employeeID, department);
    }

    cout << "\nManager details:\n";
    for (int i = 0; i < numManagers; ++i) {
        cout << "\nManager " << (i + 1) << ":\n";
        managers[i].displayManagerDetails();
    }

    delete[] managers;
}

int main() {
    int choice;

    cout << "Choose an approach to manage Manager details:\n";
    cout << "1. STL Approach (using std::map)\n";
    cout << "2. Non-STL Approach (using array)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        computeUsingMap(); // STL Approach
    } else if (choice == 2) {
        computeUsingArray(); // Non-STL Approach
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
