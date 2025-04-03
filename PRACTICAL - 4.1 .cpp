#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
protected:
    double radius;
public:
    Shape(double r) : radius(r) {}
};

class Circle : public Shape {
private:
    double area;

public:
    Circle() : Shape(0), area(0) {}

    Circle(double r) : Shape(r), area(0) {}

    void calculateArea() {
        area = M_PI * radius * radius;
    }

    void displayArea() const {
        cout << "Area of Circle with radius " << radius << " is: " << area << endl;
    }
};

// Non-STL Approach: Using a basic array to store multiple Circle objects with user input
void computeAreaUsingArray() {
    int numCircles;

    cout << "Enter the number of circles (Non-STL approach): ";
    cin >> numCircles;

    Circle* circles = new Circle[numCircles];

    for (int i = 0; i < numCircles; ++i) {
        double radius;
        cout << "Enter radius for circle " << (i + 1) << ": ";
        cin >> radius;

        circles[i] = Circle(radius);
        circles[i].calculateArea();
    }

    for (int i = 0; i < numCircles; ++i) {
        circles[i].displayArea();
    }

    delete[] circles;
}

// STL Approach: Using std::vector to store multiple Circle objects
void computeAreaUsingVector() {
    int numCircles;

    cout << "Enter the number of circles (STL approach): ";
    cin >> numCircles;

    vector<Circle> circles;

    for (int i = 0; i < numCircles; ++i) {
        double radius;
        cout << "Enter radius for circle " << (i + 1) << ": ";
        cin >> radius;

        Circle circle(radius);
        circle.calculateArea();
        circles.push_back(circle);
    }

    for (const auto& circle : circles) {
        circle.displayArea();
    }
}

int main() {
    int choice;

    cout << "Choose an approach to calculate the area of circles:\n";
    cout << "1. STL Approach (using std::vector)\n";
    cout << "2. Non-STL Approach (using array)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        computeAreaUsingVector(); // STL Approach
    } else if (choice == 2) {
        computeAreaUsingArray(); // Non-STL Approach
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    return 0;
}
