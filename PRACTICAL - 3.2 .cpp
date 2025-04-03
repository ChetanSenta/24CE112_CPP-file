#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int recursiveSum(const vector<int>& arr, int index) {
    if (index < 0) {
        return 0;
    }
    return arr[index] + recursiveSum(arr, index - 1);
}

int nonRecursiveSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto start = chrono::high_resolution_clock::now();
    int recursiveResult = recursiveSum(arr, n - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> recursiveDuration = end - start;

    start = chrono::high_resolution_clock::now();
    int nonRecursiveResult = nonRecursiveSum(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> nonRecursiveDuration = end - start;

    cout << "Recursive Sum : " << recursiveResult << endl;
    cout << "Non-recursive Sum : " << nonRecursiveResult << endl;

    cout << "Recursive time : " << recursiveDuration.count() << " seconds" << endl;
    cout << "Non-recursive time : " << nonRecursiveDuration.count() << " seconds" << endl;

    return 0;
}
