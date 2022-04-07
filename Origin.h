#ifndef ORIGIN_H
#define ORIGIN_H
#include "Destination.h"
#include "DLList.h"
#include "DSString.h"
#include "Node.h"
#include <iostream>

using namespace std;

class Origin {
private:
    DSString originCity;
    DLList<Destination> data;
public:
    Origin();
    //default constructor
    Origin(DSString);
    ~Origin();

    void setOriginCity(DSString);
    DSString getOriginCity();
    Node<Destination>* getDataHead();
    //getters and setters for private member variables
    void add(Destination);
    //fills data linked list
    bool operator==(const Origin&);
    //overloaded operator to check if two Origin objects are equal to one-another
};

#endif // ORIGIN_H