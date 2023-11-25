#include "account.h"
#define MIN 100
//class description
class SavingsAccount: public Account{
    public:
        SavingsAccount(string num, string holder, double balance, double rate);

        void displayDetails();
        void withdraw(double amount);
        SavingsAccount operator+(Account& obj);

        double rate;
};
//method definitions

SavingsAccount::SavingsAccount(string num, string holder, double balance, double rate): Account(num, holder, balance){
    this->rate = rate;
}

void SavingsAccount::displayDetails(){
    Account::displayDetails();
    cout<<"\tInterest Rate: %"<<fixed<<setprecision(2)<<rate*100<<"\n";
}

void SavingsAccount::withdraw(double amount){
    if (!checkInput(amount)){
        return;
    }
    if (MIN > balance - amount){
        cout<<"ERROR (ACCOUNT ID: "<<acctNum<<"): withdrawal would cause balance to be less than minimum\n";
        return;
    }
    balance -= amount;
}

SavingsAccount SavingsAccount::operator+( Account& a2){
    balance += 300;
    a2.balance -= 300;
    return SavingsAccount(acctNum, acctHolder, balance, rate);
}

void operator << (ostream &out, SavingsAccount& obj)
{
    obj.displayDetails();
}
