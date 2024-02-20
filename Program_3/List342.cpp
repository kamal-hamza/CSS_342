#include "List342.h"
#include <iostream>

using namespace std;

template <class T>
List342<T>::List342() {
    size = 0;
}

template <class T>
List342<T>::List342(initializer_list<T> args) {
    size = 0;
    for (T arg : args) {
        Node<T>* newNode = new Node<T>(arg, head);
        head = newNode;
        size++;
    }
}

template <class T>
int List342<T>::Size() const {
    return size;
}