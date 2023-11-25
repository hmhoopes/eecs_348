#include "account.h"
#include "saving_account.h"
#include "current_account.h"
#include <string>
#include <iostream>

int main(){
    
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    //showing functionality of << overloading
    cout<<savings;
    cout<<current;

    //showing functionality of deposit/withdraw
    cout<<"\nDetails after deposit and withdraw\n\n";

    savings.deposit(500);
    current.withdraw(1000);
    
    cout<<savings;
    cout<<current;

    //show functionality of + overloading
    cout<<"\nDetails after add\n\n";

    current = current + savings;

    cout<<savings;
    cout<<current;
    
    //show functionality of withdraw
    savings.withdraw(1100);
    current.withdraw(1800);

    cout<<savings;
    cout<<current;

    //show handling of overdraft limit and minimum balance
    savings.withdraw(1);
    current.withdraw(1);

    cout<<savings;
    cout<<current;

    //show handling of negative numbers
    savings.withdraw(-11);
    current.withdraw(-11);

    cout<<savings;
    cout<<current;
    
    return 0;
}