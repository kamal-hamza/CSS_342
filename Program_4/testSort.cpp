#include <iostream>
#include <vector>
#include "sort.cpp"

using namespace std;

int main() {
    vector<int> array = {1, 2, 44, 5, 667, 7, 7, 88, 8, 32};
    cout << "Unsorted: ";
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
    iterativeMergeSort(array);
    cout << "Sorted: ";
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
    return 0;
}