#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "GetInfo.h"

using namespace std;

int main(int argc, char** argv) {
      //catch tests run if there are no command line args
    if(argc == 1) {
        cout << "Running Catch Tests" << endl;
        Catch::Session().run();
    }

    GetInfo start;

    start.getInfo(argv);
      //sends FlightData.txt into the GetInfo function and starts program

    return 0;
}