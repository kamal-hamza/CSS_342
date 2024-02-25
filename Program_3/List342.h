#ifndef LIST342_H_
#define LIST342_H_

#include <iostream>
#include <fstream>
#include <string>
#include <initializer_list>

using namespace std;

template<class T>
class List342 {
public:
    // Constructors
    List342();
    List342(const List342<T>& list);
    List342(initializer_list<T> values);

    // Destructor
    ~List342();

    // Member functions
    bool BuildList(string file_name);
    bool Insert(T* value);
    bool Remove(T target, T& result);
    bool Peek(T target, T& result);
    int Size() const;
    void DeleteList();
    bool Merge(List342& list1);

    // extra function
    bool isEmpty() const;

    // Operator Overloads
    List342<T>& operator+(const List342<T>& rhs);
    List342<T>& operator+=(const List342<T>& rhs);
    bool operator==(const List342<T>& rhs) const;
    bool operator!=(const List342<T>& rhs) const;
    List342<T>& operator=(const List342<T>& rhs);
    template<typename U>
    friend ostream& operator<<(ostream& os, const List342<U>& list);

    private:
        struct Node {
            T* data;
            Node* next;
        };
        Node* head;
};

template <class T>
List342<T>::List342() {
    head = nullptr;
}

template <class T>
List342<T>::List342(const List342 &other) {
    head = nullptr;
    *this = other;
}

template <class T>
List342<T>::~List342() {
    DeleteList();
}

template <class T>
bool List342<T>::BuildList(string fileName) {
    ifstream inFile;
    inFile.open(fileName);

    if (!inFile) {
        cout << "The file can't be opened. Please try again." << endl;
        return false;
    } 

    T item;
    while (!inFile.eof()) {
        inFile >> item;
        Insert(&item);
    }

    inFile.close();
    return true;
}

template <class T>
bool List342<T>::Insert(T *obj) {
    if (obj == nullptr) {
        return false;
    }

    if (Peek(*obj, *obj)) {
        return false;
    }
    
    Node *newNode = new Node;
    T *newData;

    newData = new T;
    *newData = *obj;

    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return true;
    }
    else if (*(newNode->data) < *(head->data)) {
        newNode->next = head;
        head = newNode;
        return true;
    }
    else {
        Node *trackingPtr;
        trackingPtr = head;

        while ((trackingPtr->next != nullptr) && (*(newNode->data) > *(trackingPtr->next->data))) {
            trackingPtr = trackingPtr->next;
        }

        newNode->next = trackingPtr->next;
        trackingPtr->next = newNode;
    }
    return true;
}

template <class T>
bool List342<T>::Remove(T target, T &result) {
    if (head == nullptr) {
        return false;
    }

    Node *currentPtr;
    currentPtr = head;
    
    if (*(head->data) == target) {
        head = head->next;
        result = *(currentPtr->data);
        delete currentPtr->data;  
        currentPtr->data = nullptr;
        currentPtr->next = nullptr;
        delete currentPtr;
        currentPtr = nullptr;
        return true;
    }

    currentPtr = head;
    Node *trackingPtr;

    while (currentPtr->next != nullptr && *(currentPtr->next->data) != target) {
        currentPtr = currentPtr->next;
    }

    if (currentPtr->next == nullptr) {
        return false;
    }
    else {
        trackingPtr = currentPtr->next;
        result = *(trackingPtr->data);
        currentPtr->next = currentPtr->next->next;
        delete trackingPtr->data;    
        trackingPtr->data = nullptr;   
        delete trackingPtr;        
        trackingPtr = nullptr;          
        return true;
    }
}

template <class T>
bool List342<T>::Peek(T target, T &result)  {
    if (head == nullptr) {
        return false;
    }

    Node *currentPtr;
    currentPtr = head;

    while (currentPtr != nullptr) {
        if (*(currentPtr->data) == target) {
            result = *(currentPtr->data);                 
            return true;
        }
        else {
            currentPtr = currentPtr->next;
        }
    }
    return false;
}

template <class T>
bool List342<T>::isEmpty() const  {
    return (head == nullptr);
}

template <class T>
bool List342<T>::Merge(List342<T> &other) {
    if (this == &other || other.head == nullptr) {
        return false;
    }

    if (head == nullptr) {
        head = other.head;
        other.head = nullptr;
        return true;
    }

    Node *secondTrackingNode;
    secondTrackingNode = other.head;

    if ((*head->data) >= *(secondTrackingNode->data)) {
        other.head = other.head->next;

        if (*head->data == *(secondTrackingNode->data)) {       
            delete (secondTrackingNode->data);
            delete secondTrackingNode;
        }
        else {
            secondTrackingNode->next = head;
            head = secondTrackingNode;
        }
    }     

    Node *trackingNode;
    trackingNode = head;
  
    while (other.head != nullptr) {
        if (trackingNode->next != nullptr) {
            secondTrackingNode = other.head;

            if (*(secondTrackingNode->data) < *(trackingNode->next->data)) {
                other.head = other.head->next;

                secondTrackingNode->next = trackingNode->next;
                trackingNode->next = secondTrackingNode;

                trackingNode = secondTrackingNode;
                secondTrackingNode = nullptr;
            }
            else if (*(secondTrackingNode->data) == *(trackingNode->next->data)) {
                other.head = other.head->next;

                delete secondTrackingNode->data;
                delete secondTrackingNode;

                secondTrackingNode = nullptr;
            }
            else {
                trackingNode = trackingNode->next;
            }
        }
        else {
            trackingNode->next = secondTrackingNode;
            other.head = nullptr;

            return true;
        }
    }

    return true;
}

template <class T>
List342<T>& List342<T>::operator+(const List342<T> &rhs)  {
    List342<T> tempList;
    tempList = *this;
    tempList += rhs; 
    return tempList;
}

template <class T>
List342<T>& List342<T>::operator+=(const List342<T> &rhs) {
    if (rhs.head == nullptr) {
        return *this;
    }

    if (head == nullptr) {
        *this = rhs;
        return *this;
    }

    Node *newNode = rhs.head;

    while (newNode != nullptr) {
        Insert(newNode->data);
        newNode = newNode->next;
    }
    return *this;
}

template <class T>
bool List342<T>::operator==(const List342<T> &rhs) const {
    if (((head == nullptr) && (rhs.head != nullptr)) || ((head != nullptr) && (rhs.head == nullptr))) {
        return false;
    }

    Node *tracker1, *tracker2;
    
    tracker1 = head;
    tracker2 = rhs.head;
    
    while (tracker1 != nullptr && tracker2 != nullptr) {
        if (*(tracker1->data) == *(tracker2->data)) {
            tracker1 = tracker1->next;
            tracker2 = tracker2->next;
        }
        else {
            return false;
        }
    }

    if (((tracker1 == nullptr) && (tracker2 == nullptr)) || ((tracker1 != nullptr) && (tracker2 != nullptr))) {
        return true;
    }
    return false;
}

template <class T>
bool List342<T>::operator!=(const List342<T> &rhs) const {
    return !(*this == rhs);
}

template <class T>
List342<T>& List342<T>::operator=(const List342<T> &rhs) {
    if (this == &rhs) {
        return *this;
    }

    DeleteList();

    if (rhs.isEmpty()) {
        return *this;
    }

    Node *assignedNode = new Node;
    T *assignedItem = new T;
    Node *tracker, *current;

    *assignedItem = *(rhs.head->data);

    assignedNode->data = assignedItem;
    assignedNode->next = nullptr;  

    head = assignedNode;

    tracker = head;
    current = rhs.head->next;

    while (current != nullptr) {
        assignedNode = new Node;
        assignedItem = new T;

        *(assignedItem) = *(current->data);
        
        assignedNode->data = assignedItem;
        assignedNode->next = nullptr;   
        
        tracker->next = assignedNode;
        
        tracker = tracker->next;
        current = current->next;
    }
    return *this;
}

template <class T>
ostream& operator<<(ostream& stream, const List342<T> &rhs) {
    if (rhs.isEmpty()) {
        stream << "List is Empty" << endl;
        return stream;
    }

    typename List342<T>::Node* currentPtr;
    currentPtr = rhs.head;

    while (currentPtr != nullptr) {
        stream << *(currentPtr->data);
        currentPtr = currentPtr->next;
    }
    return stream;
}

template <class T>
void List342<T>::DeleteList() {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    head = nullptr;
}

#endif