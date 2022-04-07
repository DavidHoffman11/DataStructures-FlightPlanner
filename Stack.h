#ifndef STACK_H
#define STACK_H
#include "DLList.h"
#include "DSVector.h"
#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    DSVector<T> data;
    int size;
public:
    Stack();
    //default constructor
    void push(T&);
    T peek();
    //returns top element of stack
    T pop();
    //returns and deletes top element off stack
    bool doesContain(T);
    //checks to see if an element is located in a stack
    bool isEmpty();
    //checks to see if the stack is empty
};

template <typename T>
Stack<T>::Stack() {
    this->data = data;
    this->size = 0;
}  //default constructor

template <typename T>
void Stack<T>::push(T& x) {
    data.push_back(x);
    size++;
}  //adds items to stack

template <typename T>
T Stack<T>::pop() {
    T* temp;

    temp = data.pop();
    size--;

    return *temp;
}  //removes items from stack

template <typename T>
T Stack<T>::peek() {
    T show;

    if (data.isEmpty(data) == true) {
        cout << "The stack is empty" << endl;
        return show;
    }  //checks if stack is empty

    show = data[size-1];

    return show;
}

template <typename T>
bool Stack<T>::isEmpty() {
    bool isEmpty = true;

    if(size != 0) {
        isEmpty = false;
    }  //isEmpty is false if size doesn't equal 0

    return isEmpty;
}

template <typename T>
bool Stack<T>::doesContain(T x) {
    T temp;
    bool contain;

    for (int i = 0; i < data.getSize(); i++) {
        if (data[i] == x) {
            contain = true;
            return contain;
        }  //returns contain if contain is true
        else {
            contain = false;
        }  //contain remains false unless data is found
    }

    return contain;
}

#endif // STACK_H