#include "Output.h"
#include "Stack.h"
#include "Origin.h"
#include "DSVector.h"
#include "AList.h"
#include "Node.h"
#include "Itratr.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Output::Output() {
    //default constructor is sufficient in this case
}

void Output::readIn(char** argv, AList flightData) {
    char* buffer = new char[100];
    char* temp;
    DSString originCity;
    DSString destCity;
    DSString sortType;
    int numFlights;

    DSVector<DSVector<DSString>> flightReq;

    ifstream myFile1;
    myFile1.open(argv[2]);

    if (! myFile1.is_open()) {
        cout << "Could not open PathsToCalculate.txt file." << endl;
    } //outputs error message if file cannot be opened

    myFile1.getline(buffer, 100);
    temp = buffer;
    numFlights = atoi(temp);
    //reads in first line of file and stores info in numFlights variable

    for(int i = 0; i < numFlights; i++) {
        DSVector<DSString> nextReq;
        flightReq.push_back(nextReq);

        myFile1.getline(buffer, 100, '|');
        originCity = buffer;
        flightReq[i].push_back(originCity);
        myFile1.getline(buffer, 100, '|');
        destCity = buffer;
        flightReq[i].push_back(destCity);
        myFile1.getline(buffer, 100, '\n');
        sortType = buffer;
        flightReq[i].push_back(sortType);
    }  //puts data into a vector and then sends that vector to another function

    myFile1.close();

    getFlightPath(argv, flightReq, flightData);
}

void Output::getFlightPath(char **argv, DSVector<DSVector<DSString>> flightReq, AList flightData) {
    DSString sortType;
    DSString originCity;
    DSString destCity;
    Node<Origin>* curr;
    Itratr<Origin> itratr;

    ofstream myFile;
    myFile.open(argv[3]);

    if (! myFile.is_open()) {
        cout << "Could not open Output.txt file." << endl;
    } //outputs error message if file cannot be opened
/*
    for(int i = 0; i < flightReq.getSize(); i++) {
        flightReq[i][0] = sortType;
        flightReq[i][1] = destCity;
        flightReq[i][2] = originCity;
        curr = flightData.getData().getHead();

        myFile << "Flight " << i << ": " << originCity << ", " << destCity << " (";
        if (sortType == "T") {
            myFile << "Time)" << endl;
        }
        else {
            myFile << "Cost)" << endl;
        }

        for(int y = 0; y < flightData.getSize(); y++) {
            if(curr->getData().getOriginCity() == originCity) {
                cout << "yer" << endl;
            }

            else {
                //curr = itratr.moveForward(curr);
            }
        }
    }
*/
    myFile.close();
}


