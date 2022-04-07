#include "GetInfo.h"
#include "Output.h"
#include "Origin.h"
#include "Destination.h"
#include "AList.h"
#include "DSString.h"
#include <iostream>
#include <fstream>

using namespace std;

GetInfo::GetInfo() {
    //default constructor is sufficient in this case
}

void GetInfo::getInfo(char** file) {
    Output next;
    AList flightData;
    Origin o;
    Destination d;
    char* buffer = new char[100];
    char* temp;
    DSString originCity;
    DSString destCity;
    int time;
    int cost;
    DSString airline;
    int numLines;

    ifstream myFile1;
    myFile1.open(file[1]);
    //opens file

    if (! myFile1.is_open()) {
        cout << "Could not open FlightData.txt file." << endl;
    } //outputs error message if file cannot be read

    myFile1.getline(buffer, 100);
    temp = buffer;
    numLines = atoi(temp);
    //reads in first line of file and stores info in numLines variable

    for(int i = 0; i < numLines; i++) {
        myFile1.getline(buffer, 100, '|');
        originCity = buffer;
        o.setOriginCity(originCity);
        myFile1.getline(buffer, 100, '|');
        destCity = buffer;
        d.setDestCity(destCity);
        myFile1.getline(buffer, 100, '|');
        temp = buffer;
        time = atoi(temp);
        d.setTime(time);
        myFile1.getline(buffer, 100, '|');
        temp = buffer;
        cost = atoi(temp);
        d.setCost(cost);
        myFile1.getline(buffer, 100, '\n');
        airline = buffer;
        d.setAirline(airline);

        o.add(d);
        flightData.add(o);
    }  //adds appropriate info to Origin object and destination objects

    myFile1.close();
    //must close file after it is opened

    next.readIn(file, flightData);
      //calls next function
}