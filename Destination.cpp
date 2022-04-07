#include "Destination.h"
#include "DSString.h"
#include <iostream>

using namespace std;

Destination::Destination() {
    this->cost = 0;
    this->time = 0;
    //this->destCity = destCity;
    //this->airline = airline;
}

Destination::~Destination(){

}  //destructor

void Destination::setCost(int cost) {
    this->cost = cost;
}

void Destination::setTime(int t) {
    this->time = t;
}

void Destination::setDestCity(DSString s) {
    this->destCity = s;
}

void Destination::setAirline(DSString s) {
    this->airline = s;
}

int Destination::getCost() {
    return this->cost;
}

int Destination::getTime() {
    return this->time;
}

DSString Destination::getDestCity() {
    return this->destCity;
}

DSString Destination::getAirline() {
    return this->airline;
}

bool Destination::operator==(const Destination& d) const {
    bool isEqual = false;

    if(this->time == d.time && this->cost == d.cost && this->destCity == d.destCity) {
        isEqual = true;
    }  //checks to see3 if private data members of Destination object are the same
    //outputs true if they are the same

    return isEqual;
}
