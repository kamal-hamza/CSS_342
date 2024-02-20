#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node() {
    value = T();
    next = nullptr;
}

template <class T>
Node<T>::Node(const T& value, Node<T>* next) {
    value = value;
    next = next;
}

template <class T>
T& Node<T>::getValue() const {
    return value;
}

template <class T>
Node<T>* Node<T>::getNode() const {
    return next;
}

template <class T>
void Node<T>::setValue(const T& value) {
    value = value;
} 

template <class T>
void Node<T>::setNode(Node<T>* next) {
    this->next = next;
}
