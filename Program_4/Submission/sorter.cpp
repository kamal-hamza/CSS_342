#include <iostream>
#include<string>
#include <vector>
#include <random>
#include <chrono>
#include "sorts.h"

using namespace std;
using namespace std::chrono;

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

    sorts sort = sorts();

    if (argc < 3 || argc > 4) {
        cout << "Invalid Number of Arguments, Usage is: " << "<sortType> <vectorSize> [<print>] \n the third parameter is optional, type 'Print' if you want the vectors printed." << endl;
        return 1;
    }
    string sortType = argv[1];
    int vectorSize = atoi(argv[2]);
    bool toPrint = false;
    if (argc == 4) {
        string print = argv[3];
        if (print == "Print") {
            toPrint = true;
        }
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
    auto startTime = high_resolution_clock::now();
    if (sortType == "BubbleSort") {
        sort.BubbleSort(vec, 0, vec.size() - 1);
    }
    else if (sortType == "InsertionSort") {
        sort.InsertionSort(vec, 0, vec.size());
    }
    else if (sortType == "MergeSort") {
        sort.MergeSort(vec, 0, vec.size());
    }
    else if (sortType == "IterativeMergeSort") {
        sort.IterativeMergeSort(vec, 0, vec.size());
    }
    else if (sortType == "QuickSort") {
        sort.QuickSort(vec, 0, vec.size());
    }
    else if (sortType == "ShellSort") {
        sort.ShellSort(vec, 0, vec.size());
    }
    else {
        cout << "invalid sort type please try again" << endl;
    }

    auto endTime = high_resolution_clock::now();
    
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

    auto elapsedTime = duration_cast<microseconds>(endTime - startTime).count();

    cout << "Execution Time: " << elapsedTime << " microseconds." << endl;

    return 0;
}