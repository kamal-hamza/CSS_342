#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& vec, int index1, int index2) {
    int temp = vec[index1];
    vec[index1] = vec[index2];
    vec[index2] = temp;
}

void bubbleSort(vector<int>& vec) {
    int length = vec.size();
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec, j, j+1);
            }
        }
    }
}

void insertionSort(vector<int>& vec) {
    int length = vec.size();
    for (int i = 1; i < length; i++) {
        int val = vec[i];
        int j = i - 1;
        while ((j >= 0) && (vec[j] > val)) {
            vec[j+1] = vec[j];
            j -= 1;
        }
        vec[j+1] = val;
    }
}

void mergeSort(vector<int>& vec) {
    if (vec.size() > 1) {
        int mid = vec.size() / 2;
        auto start = vec.begin();
        auto end = vec.begin() + mid;
        vector<int> left(start, end);
        auto start2 = vec.begin() + mid;
        auto end2 = vec.end();
        vector<int> right(start2, end2);
        cout << vec[mid] << endl;
        cout << "Left: ";
        for (int i = 0; i < left.size(); ++i) {
            cout << left[i] << ", ";
        }
        cout << endl;
        cout << "Right: ";
        for (int i = 0; i < right.size(); ++i) {
            cout << right[i] << ", ";
        }
        cout << endl;
        mergeSort(left);
        mergeSort(right);
        int i = 0, j = 0, k = 0;
        while ((i < left.size()) && (j < right.size())) {
            if (left[i] <= right[j]) {
                vec[k] = left[i];
                i += 1;
            }
            else {
                vec[k] = right[j];
                j += 1;
            }
            k += 1;
        }
        while (i < left.size()) {
            vec[k] = left[i];
            i += 1;
            k += 1;
        }
        while (j < right.size()) {
            vec[k] = right[j];
            j += 1;
            k += 1;
        }
    }
}

void merge(vector<int>& vec, int left, int mid, int right, vector<int>& temp) {
    int i = left;
    int j = mid;
    int k = left;
    while ((i < mid) && (j < right)) {
        if (vec[i] <= vec[j]) {
            temp[k] = vec[i];
            i += 1;
        }
        else {
            temp[k] = vec[j];
            j += 1;
        }
        k += 1;
    }
    while (i < mid) {
        temp[k] = vec[i];
        i += 1;
        k += 1;
    }
    while (j < right) {
        temp[k] = vec[j];
        j += 1;
        k += 1;
    }
    for (int l = left; l < right; l++) {
        vec[l] = temp[l];
    }
}

void iterativeMergeSort(vector<int>& vec) {
    int length = vec.size();
    vector<int> temp(length, 0);
    int size = 1;
    while (size < length) {
        int left = 0;
        while (left < length - size) {
            int mid = left + size;
            int right = min(left + 2*size, length);
            merge(vec, left, mid, right, temp);
            left += 2*size;
        }
        size += 2;
    }
}

int median(int val1, int val2, int val3) {
    if ((val1 < val2 && val2 < val3) || (val3 < val2 && val2 < val1)) {
        return val2;
    }
    else if ((val2 < val1 && val1 < val3) || (val3 < val1 && val1 < val2)) {
        return val1;
    }
    else {
        return val3;
    }
}

int partition(vector<int>& vec, int left, int right) {
    int pivot = vec[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (vec[j] <= pivot) {
            i += 1;
            swap(vec, i, j);
        }
    }
    swap(vec, i+1, right);
    return i + 1;
}

int medianPivot(vector<int>& vec, int left, int right) {
    int mid = right / 2;
    int midVal = median(vec[left], vec[mid], vec[right]);
    int tmp = vec[right];
    vec[right] = midVal;
    if (midVal == vec[left]) {
        vec[left] = tmp;
    }
    else if (midVal == vec[mid]) {
        vec[mid] = tmp;
    }
    return partition(vec, left, right);
}

void quickSortHelper(vector<int>& vec, int left, int right) {
    if (left < right) {
        int pivot = partition(vec, left, right);
        quickSortHelper(vec, left, pivot - 1);
        quickSortHelper(vec, pivot + 1, right); 
    }
}

void quickSort(vector<int>& vec, int left, int right) {
    if (left >= right) {
        return;
    }
    else if (left < right) {
        medianPivot(vec, left, right);
        quickSortHelper(vec, left, right);
    }
}

void shellSort(vector<int>& vec) {
    int gap = vec.size() / 2;
    while (gap >= 1) {
        for (int j = gap; j < vec.size(); j++) {
            int i = j - gap;
            while (i >= 0) {
                if (vec[i+gap] > vec[i]) {
                    break;
                }
                else {
                    swap(vec, i+gap, i);
                }
                i -= gap;
            }
        }
        gap = gap / 2;
    }
}