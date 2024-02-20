#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    // Template constructors
    Node();
    Node(const T& value, Node<T>* next);

    // Getters
    T& getValue() const;
    Node<T>* getNode() const;

    // Setters
    void setValue(const T& value);
    void setNode(Node<T>* next);

private:
    T value;
    Node<T>* next;
};

#endif
