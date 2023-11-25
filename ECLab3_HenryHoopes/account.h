#ifndef ACCOUNT.H 
#define ACCOUNT.H 

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;
//class description

class Account{
    public:
        Account(string acctNum, string acctHolder, double balance);

        void displayDetails();
        void deposit(double amount);
        void withdraw(double amount);
        Account operator+(Account& obj);
        bool checkInput(double amount);

        string acctNum, acctHolder;
        double balance;
};

//method definitions

Account::Account(string num, string holder, double balance){
    acctNum = num;
    acctHolder = holder;
    this->balance = balance;
}

void Account::displayDetails(){
    cout<<"Account details for Account (ID: "<<acctNum<<"):\n";
    cout<<"\tHolder: "<<acctHolder<<"\n";
    cout<<"\tBalance: $"<<fixed <<setprecision(2)<<balance<<"\n";
}

void Account::deposit(double amount){
    if (!checkInput(amount)){
        return;
    }
    balance += amount;
}

void Account::withdraw(double amount){
    if (!checkInput(amount)){
        return;
    }
    if (0 > balance - amount){
        cout<<"ERROR (ACCOUNT ID: "<<acctNum<<"): withdrawal is greater than balance\n";
        return;
    }
    balance -= amount;
}

Account Account::operator+( Account& a2){
    balance += 300;
    a2.balance -= 300;
    return Account(acctNum, acctHolder, balance);
}

bool Account::checkInput(double amount){
    if (amount < 0){
        cout<<"ERROR (ACCOUNT ID: "<<acctNum<<"): cannot accept negative amount\n";
        return false;
    }
    return true;
}

void operator << (ostream &out, Account& obj)
{
    obj.displayDetails();
}
#endif