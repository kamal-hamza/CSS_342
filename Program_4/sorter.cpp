#include <iostream>
#include<string>
#include <vector>
#include <random>
#include "sort.cpp"

using namespace std;

vector<int> generateRandomVectorData(int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<int> dis(0, size);
    vector<int> result;
    for (int i = 0; i < size; ++i) {
        result.push_back(dis(gen));
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (3 != argc) {
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
        bubbleSort(vec);
    }
    else if (sortType == "InsertionSort") {
        insertionSort(vec);
    }
    else if (sortType == "MergeSort") {
        mergeSort(vec);
    }
    else if (sortType == "IterativeMergeSort") {
        iterativeMergeSort(vec);
    }
    else if (sortType == "QuickSort") {
        quickSort(vec, 0, vec.size());
    }
    else if (sortType == "ShellSort") {
        shellSort(vec);
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