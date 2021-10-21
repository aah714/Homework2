#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Check {
    float checkAmount;
    string checkMemo;
    int checkNum;
    bool operator <= (float balance){
        return checkAmount<=balance;}
};
ostream& operator << (ostream& output, Check cb1){
    output << "Check Amount: " << cb1.checkAmount <<"   Check Memo: "<<cb1.checkMemo << "   Check Number: " << cb1.checkNum<<endl;
    return output;
}


class Checkbook{
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

void checkTest(Checkbook newcheckbook, float balance){
    newcheckbook.deposit(balance);
    bool callWriteCheck=true;
    Check newcheck;
    newcheck.checkAmount=10;
    while (callWriteCheck){
        callWriteCheck=newcheckbook.writeCheck(newcheck);
    }
    newcheckbook.displayChecks();
}

int main() {
    Checkbook newcheckbookObject;
    float balance=20;
    checkTest(newcheckbookObject, balance);

    return 0;
}

Checkbook::Checkbook():balance(0), numofChecks(0), checkBookSize(4){
    chkPtr= new Check[checkBookSize];
}

Checkbook::Checkbook(float amount):balance(amount), numofChecks(0), checkBookSize(2){
    chkPtr= new Check[checkBookSize];
}


bool Checkbook::writeCheck(Check c_amount)
{
   string CheckMemoArray[8]={
            "Wedding", "Baby Shower", "Plumber", "Barbershop",
            "Childrens Hospital", "Hobbit", "Tutor", "Pizza",};

    int randomNumber= (rand()%8);
    if(c_amount<=balance)
    {
        if(numofChecks==(checkBookSize/2)){
            checkBookSize=(checkBookSize*2);                   //doubling size of checkbook ptr array
            Check *temp=new Check[checkBookSize];
            for(int i=0; i<=numofChecks; i++){
                temp[i]=chkPtr[i];

            }
            delete[]chkPtr;
            chkPtr=temp;
        }
        c_amount.checkNum=numofChecks;
        chkPtr[numofChecks].checkAmount= c_amount.checkAmount;
        chkPtr[numofChecks].checkNum = c_amount.checkNum;
        chkPtr[numofChecks].checkMemo=CheckMemoArray[randomNumber];
        balance-=c_amount.checkAmount;
        numofChecks++;
        return true;
    }else{
        return false;
    }
}

void Checkbook::displayChecks()
{
    for(int i=numofChecks-1; i>=0; i--)
    {
        cout<<chkPtr[i]<<endl;
    }
}

Checkbook::Checkbook(const Checkbook& oldCheckbook){    //defining copy constructor
    balance=oldCheckbook.balance;
    numofChecks=oldCheckbook.numofChecks;
    checkBookSize=oldCheckbook.checkBookSize;
    lastDeposit=oldCheckbook.lastDeposit;
    chkPtr= new Check[checkBookSize];

    for (int i=0; i<checkBookSize; i++){
        chkPtr[i]=oldCheckbook.chkPtr[i];
    }
}

Checkbook& Checkbook::operator = (const Checkbook& oldCheckbook){    //defining overloaded operator
    balance=oldCheckbook.balance;
    numofChecks=oldCheckbook.numofChecks;
    checkBookSize=oldCheckbook.checkBookSize;
    lastDeposit=oldCheckbook.lastDeposit;
    chkPtr= new Check[checkBookSize];

    for (int i=0; i<checkBookSize; i++) {
        chkPtr[i] = oldCheckbook.chkPtr[i];
    }
    return *this;
}

Checkbook::~Checkbook(){ delete[] chkPtr;}

void Checkbook::deposit(float newBalance){
    balance+=newBalance;
}