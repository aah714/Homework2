#include <iostream>
#include <string>
#include <cstdlib>


#include "Checkbook.h"

using namespace std;


void checkTest(Checkbook newcheckbook, float balance){
    newcheckbook.deposit(balance);
    bool callWriteCheck=true;
    Check newcheck;
    newcheck.checkAmount=20;
    while (callWriteCheck){
        callWriteCheck=newcheckbook.writeCheck(newcheck);
    }
    newcheckbook.displayChecks();
}



int main() {
    Checkbook newcheckbookObject;
    float balance=500;
    checkTest(newcheckbookObject, balance);

    return 0;
}

