#include "BankAccount.h"
#include <iostream>
#include <string> 

using namespace std;

BankAccount::BankAccount(){

}

void BankAccount::deposit(double amount){
    balance += amount;
}

void BankAccount::withdraw(double amount){
    balance -= amount;
}

double BankAccount::get_balance() const{
    return balance;
}

string BankAccount::get_id() const{ 
    return id;
}

void BankAccount::set_id(string nid){ // removed std::
    id = nid;
}
