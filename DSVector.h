#ifndef VECTOR_H
#define VECTOR_H
#include "DSString.h"

template <class T>
//must include at the top of each function

class DSVector {

public:
    DSVector();
    DSVector (const int);
    DSVector (const DSVector<T>&);
    ~DSVector();

    DSVector<T>& operator= (const DSVector<T>&);
    T& operator[] (int);
    int getSize();
    void setSize(int);
    int getCapacity();
    bool isEmpty(DSVector<T>&);
    void clear();
    T* pop();
    //void push_back(Keyword);
    void push_back(const T&);
    void resize();
    bool isElement(DSVector<T>&, DSString&);
    //checks to see if a certain value is an element of a given DSVector object
    bool isElement(DSString);

private:
    int size = 0;
    int capacity = 10;
    T* array = new T[capacity];

};

template <class T>
//must include at the top of each function

DSVector<T>::DSVector() {
    size = 0;
    capacity = 10;
    array = new T[capacity];
}  //default constructor

template <class T>
//must include at the top of each function

DSVector<T>::DSVector(const DSVector<T>& x) {
    size = x.size;
    capacity = x.capacity;
    array = new T[x.capacity];

    for (int i = 0; i < x.size; i++) {
        array[i] = x.array[i];
    }  //copies vector x into a new vector
}

template <class T>
//must include at the top of each function

DSVector<T>::DSVector(const int x) {
    size = 0;
    capacity = x;
    array = new T[capacity];
}

template <class T>
//must include at the top of each function

DSVector<T>::~DSVector() {
    delete[] array;
}  //destructor

template <class T>
//must include at the top of each function

DSVector<T>& DSVector<T>::operator= (const DSVector<T>& x) {
    for (int i = 0; i < x.size; i++) {
        this->array[i] = x.array[i];
    }
    size = x.size;
    capacity = x.capacity;
    return *this;
}

template <class T>
//must include at the top of each function

T& DSVector<T>::operator[] (int x) {
    //Write some error checking code here:
    // if x<0
    //ifx>0 < size
    if(x>=0 && x<size)
    {
        return array[x];
    }
    else{
        std::cout<<"out of range"<<std::endl;
        exit(0);
    }


}  //returns value in vector at the location x

template <class T>
//must include at the top of each function

int DSVector<T>::getSize() {
    return size;
}

template <typename T>

void DSVector<T>::setSize(int x) {
    this->size = x;
}

template <class T>
//must include at the top of each function

T* DSVector<T>::pop() {
    size--;
    //removes last element of vector and replaces it with NULL

    return array;
}

template <class T>
//must include at the top of each function

int DSVector<T>::getCapacity() {
    return capacity;
}

template <class T>
//must include at the top of each function

bool DSVector<T>::isEmpty(DSVector& x) {

    if (x.size == 0) {
        return true;
    }  //returns true if array is empty

    else {
        return false;
    }  //returns false if array isn't empty
}

template <class T>
//must include at the top of each function

void DSVector<T>::clear() {
    for (int i = 0; i < size; i++) {
        this->pop();
    }
    size = 0;
}
/*
template <typename T>
void DSVector<T>::push_back(Keyword x) {
    if(size = capacity) {
        resize();
    }
    size++;
    array[size - 1] = x;
    array[size-1].setPageNum(x.getPageNum());
}
*/
template <class T>
//must include at the top of each function

void DSVector<T>::push_back(const T& x) {
    if (size == capacity) {
        resize();
    }  //resizes array if capacity is full
/*
    T* temp;
    temp = array;
    //this temporary array stores the contents of the old array before it is deleted
    delete[] array;
    array = new T[size + 1];
    //deletes array and creates a new one with a different size
*/
    size++;

    array[size - 1] = x;
}

template <class T>
//must include at the top of each function

void DSVector<T>::resize() {
    capacity *= 2;
    T* temp = new T[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }

    delete[] array;
    //must deallocate allocated memory to avoid memory leaks
    array = temp;
}

/*
bool DSVector<T>::isElement(DSVector& y, DSString& x) {
    bool element = false;
    for (int i = 0; i < y.getSize(); i++) {
        if (x == y[i]) {
            element = true;
        }  //returns true if x is an element of vector y
    }
    return element;
}
*/
template <typename T>
bool DSVector<T>::isElement(DSString x) {
    bool element = false;

    for (int i = 0; i < size; i++) {
        if (this->array[i] == x) {
            element = true;
        }  //returns true if x is an element of vector y
    }

    return element;
}

#endif
