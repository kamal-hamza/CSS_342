#ifndef LIST342_H_
#define LIST342_H_
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class List342 {
    public:
    // template constructors
    List342();
    List342(initializer_list<T> args);

    int Size() const;

    private:
    Node<T> head;
    int size;
};

#endif