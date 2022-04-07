#include "Origin.h"
#include "Destination.h"
#include "DLList.h"
#include "DSString.h"
#include <iostream>

using namespace std;

Origin::Origin() {
    //default constructor
}

Origin::Origin(DSString originCity) {
    this->originCity = originCity;
    this->data = data;
}

Origin::~Origin(){

}  //destructor

void Origin::setOriginCity(DSString originCity) {
    this->originCity = originCity;
}

DSString Origin::getOriginCity() {
    return this->originCity;
}

Node<Destination>* Origin::getDataHead() {
    return this->data.getHead();
}

void Origin::add(Destination d) {
    this->data = data;

    if(data.getSize() == 0) {
        data.insertAtFront(d);
    }  //emmediately adds object if the list is empty

    else if(data.isElement(d) == false) {
        data.insertAtFront(d);
    } //adds element to list if it has not already been added before
}

bool Origin::operator==(const Origin& o) {
    bool isEqual = false;

    if(this->originCity == o.originCity) {
        isEqual = true;
    }  //checks if the two objects are equal to one-another

    return isEqual;
}
