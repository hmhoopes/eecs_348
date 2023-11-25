#include "account.h"
//class description
class CurrentAccount: public Account{
    public:
        CurrentAccount(string num, string holder, double balance, double limit);

        void displayDetails();
        void withdraw(double amount);
        CurrentAccount operator+(Account& obj);

        double limit;
};
//method definitions

CurrentAccount::CurrentAccount(string num, string holder, double balance, double limit): Account(num, holder, balance){
    this->limit = limit;
}

void CurrentAccount::displayDetails(){
    Account::displayDetails();
    cout<<"\tOverdraft Limit: $"<<fixed<<setprecision(2)<<limit<<"\n";
}

void CurrentAccount::withdraw(double amount){
    if (!checkInput(amount)){
        return;
    }
    if (-1*limit > balance - amount){
        cout<<"ERROR (ACCOUNT ID: "<<acctNum<<"): withdrawal would cause balance to be less than overdraft limit\n";
        return;
    }
    balance -= amount;
}

CurrentAccount CurrentAccount::operator+( Account& a2){
    balance += 300;
    a2.balance -= 300;
    return CurrentAccount(acctNum, acctHolder, balance, limit);
}

void operator << (ostream &out, CurrentAccount& obj)
{
    obj.displayDetails();
}