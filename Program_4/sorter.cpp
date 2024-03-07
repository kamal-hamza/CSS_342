#include <iostream>
#include<string>
#include <vector>
#include <random>
#include "sort.cpp"

using namespace std;

vector<int> generateRandomVectorData(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, size);
    vector<int> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(dis(gen));
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (4 != argc) {
        cout << "Invalid Number of Arguments, Usage is: " << "<sortType> <vectorSize> <print> \n the third paramter is optional type 'Print' if you want the vectors printed." << endl;
        return 1;
    }
    string sortType = argv[1];
    int vectorSize = atoi(argv[2]);
    string print = argv[3];
    bool toPrint = false;
    if (print == "Print") {
        toPrint = true;
    }
    else {
        toPrint = false;
    } 

    vector<int> vec = generateRandomVectorData(vectorSize);

    if (toPrint) {
        cout << "Unsorted: ";
        for (int i = 0; i < vec.size(); i++) {
            if (i > 0) {
                cout << ", ";
            }
            cout << vec[i];
        }
        cout << endl;
    }

    if (sortType == "BubbleSort") {
        BubbleSort(vec, 0, vec.size() - 1);
    }
    else if (sortType == "InsertionSort") {
        InsertionSort(vec, 0, vec.size());
    }
    else if (sortType == "MergeSort") {
        MergeSort(vec, 0, vec.size());
    }
    else if (sortType == "IterativeMergeSort") {
        IterativeMergeSort(vec, 0, vec.size());
    }
    else if (sortType == "QuickSort") {
        QuickSort(vec, 0, vec.size());
    }
    else if (sortType == "ShellSort") {
        ShellSort(vec, 0, vec.size());
    }
    else {
        cout << "invalid sort type please try again" << endl;
    }
    
    if (toPrint) {
        cout << "Sorted: ";
        for (int i = 0; i < vec.size(); i++) {
            if (i > 0) {
                cout << ", ";
            }
            cout << vec[i];
        }
        cout << endl;
    }

    return 0;
}