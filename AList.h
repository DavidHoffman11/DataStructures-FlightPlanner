#ifndef ALIST_H
#define ALIST_H
#include "DLList.h"
#include "Origin.h"
#include "DSVector.h"
#include "Destination.h"
#include <iostream>

using namespace std;

class AList {
private:
    DLList<Origin> data;
    //a linked list of Origin city objects
    int size = 0;
public:
    AList();
    //default constructor
    ~AList();
    //destructor
    int getSize();
    //getter for private member variable
    DLList<Origin> getData();
      //returns data
    void add(Origin);
};
#endif // ALIST_H
