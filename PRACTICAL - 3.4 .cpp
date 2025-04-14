#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
T findMax(const vector<T>& vec) {
    T maxValue = vec[0];
    for (const T& value : vec) {
        if (value > maxValue) {
            maxValue = value;
        }
    }
    return maxValue;
}

template <typename T>
void reverseVector(vector<T>& vec) {
    reverse(vec.begin(), vec.end());
}

template <typename T>
void displayVector(const vector<T>& vec) {
    for (const T& value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {

    vector<int> intVec = {1, 3, 5, 7, 9};
    vector<double> doubleVec = {2.2, 4.4, 6.6, 8.8};
    vector<char> charVec = {'A', 'B', 'C', 'D'};

    cout << "Integer Vector:\n";
    displayVector(intVec);
    cout << "Maximum: " << findMax(intVec) << endl;
    reverseVector(intVec);
    cout << "Reversed: ";
    displayVector(intVec);

    cout << "\nDouble Vector:\n";
    displayVector(doubleVec);
    cout << "Maximum: " << findMax(doubleVec) << endl;
    reverseVector(doubleVec);
    cout << "Reversed: ";
    displayVector(doubleVec);

    cout << "\nCharacter Vector:\n";
    displayVector(charVec);
    cout << "Maximum: " << findMax(charVec) << endl;
    reverseVector(charVec);
    cout << "Reversed: ";
    displayVector(charVec);

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
