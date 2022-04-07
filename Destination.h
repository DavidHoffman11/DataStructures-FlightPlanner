#ifndef DESTINATION_H
#define DESTINATION_H
#include <iostream>
#include "DSString.h"

using namespace std;

class Destination {
private:
    DSString destCity;
    DSString airline;
    int cost;
    int time;
public:
    Destination();
    //default constructor
    ~Destination();
    void setDestCity(DSString);
    void setCost(int);
    void setTime(int);
    void setAirline(DSString);
    DSString getDestCity();
    int getCost();
    int getTime();
    DSString getAirline();
    //getters and setters for private member variables
    bool operator==(const Destination&) const;
    //overloaded operator to check if two Destination objects are equal to one-another
};

#endif // DESTINATION_H
