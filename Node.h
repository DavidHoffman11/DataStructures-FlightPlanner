
#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template <typename T>
class Node {
    template <class U> friend class DLList;
private:
    Node<T>* next;
    Node<T>* prev;
    T data;
public:
    Node():next(nullptr),prev(nullptr){}
    //default constructor
    Node(T val):next(nullptr),prev(nullptr),data(val){}
    //overloaded constructor
    Node(const Node<T>& x):next(nullptr),prev(nullptr),data(x.data){}
    //overloaded constructor
    T& getData();
    Node<T>* getNext();
};

template <typename T>
T& Node<T>::getData() {
    return this->data;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return this->next;
}

#endif // NODE_H
