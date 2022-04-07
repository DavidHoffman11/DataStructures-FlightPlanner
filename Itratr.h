#ifndef ITRATR_H
#define ITRATR_H
#include "Node.h"
#include "DLList.h"

template <typename T>
class Itratr {
private:
    Node<T>* i;

public:
    Itratr();
    //default constructor
    void moveForward(Node<T>*);
    //moves iterator forwards in linked list
    void moveBackward(Node<T>*);
    //moves iterator backward in list
};

template <typename T>
Itratr<T>::Itratr() {
    //default constructor is sufficient in this case
}

template <typename T>
void Itratr<T>::moveForward(Node<T> *curr) {
    this->i = curr->next;
}  //points iterator to the next element in the list

template <typename T>
void Itratr<T>::moveBackward(Node<T>* curr) {
    this->i = curr->prev;
}  //points iterator to the previous element in the list

#endif // ITRATR_H