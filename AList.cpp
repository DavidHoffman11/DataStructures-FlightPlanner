#include "AList.h"
#include <iostream>

using namespace std;

AList::AList() {
    //default constructor sufficient in this case
}

AList::~AList() {

}  //destructor

int AList::getSize() {
    return size;
}

DLList<Origin> AList::getData() {
    return data;
}

void AList::add(Origin o) {
    if(data.getSize() == 0) {
        data.insertAtFront(o);
    }  //emmediately adds if list is empty

    else if(data.isElement(o) == false) {
        data.insertAtFront(o);
    } //adds element to list if ithas not already been added before

    size++;
}