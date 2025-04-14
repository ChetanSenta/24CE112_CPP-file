#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n, double basic, double b = 500) : name(n), basicSalary(basic), bonus(b) {}

    double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    void display() const {
        cout << "Name : " << name << " , Basic Salary : " << basicSalary << " , Bonus : " << bonus
             << " , Total Salary : " << calculateTotalSalary() << endl;
    }
};

int main() {
    vector<Employee> employees;
    int numEmployees;

    cout << "Enter the number of employees : ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        string name;
        double basicSalary, bonus;
        char useDefaultBonus;

        cout << "\nEnter details for employee " << (i + 1) << " : \n";

        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter basic salary : ";
        cin >> basicSalary;

        cout << "Do you want to use the default bonus of 500? (y/n) : ";
        cin >> useDefaultBonus;

        if (useDefaultBonus == 'y' || useDefaultBonus == 'Y') {
            bonus = 500;
        } else {
            cout << "Enter custom bonus : ";
            cin >> bonus;
        }

        employees.push_back(Employee(name, basicSalary, bonus));
    }

    cout << "\nEmployee details and total salaries :\n";
    for (const auto& emp : employees) {
        emp.display();
    }

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
