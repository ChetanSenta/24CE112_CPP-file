#include <iostream>
using namespace std;

class Rectangle {

    int length;
    int width;

public:
    void setDimensions(int l, int w)
    {
        length = l;
        width = w;
    }

    int area()
    {
        return length * width;
    }

    int perimeter()
    {
        return 2 * (length + width);
    }
};

int main() {
    int n;
    cout << "Enter the number of rectangles : ";
    cin >> n;

    Rectangle rectangles[n];

    for (int i = 0; i < n; i++) {
        int length, width;
        cout << "Enter dimensions for rectangle " << i + 1 << " (length width): ";
        cin >> length >> width;
        rectangles[i].setDimensions(length, width);

        cout << "Rectangle " << i + 1 << " - Area = " << rectangles[i].area()
             << " AND Perimeter = " << rectangles[i].perimeter() << endl;
    }

    cout << endl << "24CE112_CHETAN" << endl ;
    return 0;
}
