#ifndef OUTPUT_H
#define OUTPUT_H
#include "DLList.h"
#include "Origin.h"
#include "DSString.h"
#include "DSVector.h"
#include "AList.h"

class Output {
private:

public:
    Output();
    //default constructor
    void readIn(char**, AList flightData);
    void getFlightPath(char** argv, DSVector<DSVector<DSString>> flightReq, AList flightData);
    //gets various travel options and prints to output file
};

#endif // OUTPUT_H