#include <iostream>
#include <vector>

using namespace std;

// Base Class: Shape
class Shape {
protected:
    double radius;

public:
    Shape() : radius(0) {} // Default constructor

    Shape(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double area;

public:
    Circle() : Shape(), area(0) {} // Default constructor

    Circle(double r) : Shape(r), area(0) {}

    void calculateArea() {
        area = 3.14 * radius * radius;
    }

    void displayArea() const {
        cout << "Radius : " << radius << " -> Area : " << area << endl;
    }
};

int main() {
    int n;

    // --- STL Approach ---
    cout << "Enter number of circles for STL approach : ";
    cin >> n;

    vector<Circle> circleVector;

    for (int i = 0; i < n; ++i) {
        double r;
        cout << "Enter radius of circle " << i + 1 << " : ";
        cin >> r;
        circleVector.emplace_back(r);
    }

    cout << "\nUsing STL (vector) :" << endl;
    for (auto& c : circleVector) {
        c.calculateArea();
        c.displayArea();
    }

    // --- Non-STL Approach ---
    cout << "\nEnter number of circles for Non-STL approach : ";
    cin >> n;

    Circle* circleArray = new Circle[n];

    for (int i = 0; i < n; ++i) {
        double r;
        cout << "Enter radius of circle " << i + 1 << " : ";
        cin >> r;
        circleArray[i] = Circle(r);
    }

    cout << "\nUsing Non-STL (array) :" << endl;
    for (int i = 0; i < n; ++i) {
        circleArray[i].calculateArea();
        circleArray[i].displayArea();
    }

    delete[] circleArray; // Free allocated memory

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}