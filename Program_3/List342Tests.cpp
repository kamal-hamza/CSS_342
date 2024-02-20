#include "List342.cpp"
#include <iostream>

using namespace std;

bool checkDefaultConstructor() {
    List342<int> list;
    int size = list.Size();
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool checkParameterConstructor() {
    List342<int> list = {1, 2, 3, 4, 5};
    int size = list.Size();
    if (size == 5) {
        return true;
    } 
    else {
        return false;
    }
}

int main() {
    if (!checkDefaultConstructor()) { 
        cout << "Check Default Constructor Test Failed!" << endl; 
        return -1;
    }
    if (!checkParameterConstructor()) { 
        cout << "Check Parameter Constructor Test Failed!" << endl; 
        return -1;
    }
    cout << "All tests Passed!" << endl;
    return 0;
}