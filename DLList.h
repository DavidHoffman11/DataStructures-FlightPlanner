#ifndef DLLIST_H
#define DLLIST_H
#include "Node.h"
#include "Itratr.h"
#include <iostream>

using namespace std;

template <typename T>
class DLList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DLList();
    //default constructor
    DLList(const DLList<T>&);
    //copy constructor
    ~DLList();
    //destructor
    void insertAtEnd(T);
    //inserts item at back of list
    void insertAtFront(T);
    //inserts item at front of list
    bool isElement(T);
    //checks to see if an object is already an element of the list
    Node<T>* getHead();
    //returns data of head
    Node<T>* getTail();
    //returns data of tail
    int getSize();
    //returns size
    T getNodeAtIndex();
    //returns node at specific index
    T getNodeOfInput();
    //returns node of input
    void deleteFront();
    void deleteBack();
    void clear();
    //clears linked list
    void print();
    //prints linked list
};

template <typename T>
DLList<T>::DLList(){
    this->size = 0;
    this->head = NULL;
}  //default constructor

template <typename T>
DLList<T>::DLList(const DLList<T>& x) {
    head = new Node<T>(x.head->data);
    Node<T>* itratr;

    itratr = head;
    //initializes iterator to the top of the linked list

    size = x.size;

    while(itratr->next != nullptr) {
        itratr->next = new Node<T>(itratr->next->data);
        itratr = itratr->next;
    }  //adds every node in the linked list x to another linked list
    this->tail = itratr;
}

template<typename T>
DLList<T>::~DLList() {

}  //destructor

template <typename T>
void DLList<T>::insertAtEnd(T x) {
    Node<T>* node = new Node<T>(x);

    node->data = x;
    node->next = nullptr;
    node->prev = this->tail;
    //sets next value equal to a nullptr and prev value equal to the former tail

    this->tail = node;
    //makes the new node the new tail
    this->size++;

}

template <typename T>
void DLList<T>::insertAtFront(T data){
    Node<T>* node = new Node<T>();

    node->data = data;

    if (this->size == 0) {
        this->head = node;
        this->tail = node;
        node->prev = nullptr;
        node->next = nullptr;
    }  //sets node as the head if the linked list is empty

    else {
        node->next = this->head;
        node->prev = nullptr;
        //sets next value equal to the former head and leaves prev value as a nullptr

        this->head = node;
        //makes the new node the new head
    }

    this->size++;
}

template <typename T>
bool DLList<T>::isElement(T o) {
    Node<T>* i;
    bool isElement = false;

    i = head;
    //initializes i to the head

    while (i != nullptr) {
        if (i->data == o) {
            return true;
        }  //returns true if data is an element of the list
        i = i->next;
    }

    return isElement;
}

template <typename T>
Node<T>* DLList<T>::getHead() {
    return head;
}

template <typename T>
Node<T>* DLList<T>::getTail() {
    return this->head;
}

template <typename T>
int DLList<T>::getSize() {
    return this->size;
}


#endif // DLLIST_H