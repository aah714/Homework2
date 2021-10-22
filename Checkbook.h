//
// Created by ashle on 10/21/2021.
//

#ifndef MAIN_CPP_CHECKBOOK_H
#define MAIN_CPP_CHECKBOOK_H
#include <iostream>

using namespace std;

struct Check {
    float checkAmount;
    string checkMemo;
    int checkNum;
    bool operator <= (float balance){
        return checkAmount<=balance;}
};




class Checkbook {
public:
    Checkbook();
    Checkbook(float amount);
    ~Checkbook(); //destructor
    Checkbook(const Checkbook& oldCheckbook);  //copy constructor
    Checkbook &operator = (const Checkbook& oldCheckbook);  //overloaded assignment operator
    bool writeCheck(Check c_amount);
    void displayChecks();
    //int getAllChecks()const{return  Checks;}
    void setcheckBookSize(int value);
    void setBalance(float value);
    void setlastDeposit(float value);
    const int getcheckBookSize();
    const float getBalance();
    const float getlastDeposit();
    void deposit(float newBalance);
private:
    float balance, lastDeposit;
    int numofChecks;
    //Check checks[N]; //static array, conventional array meaning it is not dynamic
    static int allChecks;
    Check *chkPtr;
    int checkBookSize;

};


#endif //MAIN_CPP_CHECKBOOK_H
