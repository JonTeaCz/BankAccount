#include "Employee.h"
#include <iostream>

#include <iomanip>
using namespace std;

//prototype
string addComma(const double& s);

//construction function
Employee::Employee(std::string nid, std::string nfname, std::string nlname, double nsalary, BankAccount* nacc){
    id = nid;
    fname = nfname;
    lname = nlname;
    salary = nsalary;
    account = nacc;
}

void Employee::deposit_monthly_salary(){
    double dep = salary / 12;
    account->deposit(dep); //call deposit function and put 12th of annual salary into balance
}

void Employee::print(ostream& out) const{
    //print out the id, name, annual salary, monthly salary, and balance
    out << left << setw(15) << id << setw(15) << lname << setw(15) << fname << setw(1) << "$";
    out << left << setw(20) << addComma(salary) <<  setw(1) << "$";
    out << left << setw(20) <<  addComma(salary/12.0) << "$";
    out << left << setw(20) << addComma(account->get_balance()) << endl; 
}


//this function adds a comma every 3 digits
string addComma(const double& s){
    ostringstream ss;
    ss << fixed << std::setprecision(2) << s;
    string str = ss.str();
    size_t idx = str.find('.');
    while (idx > 3) {
        idx -= 3;
        str.insert(idx, ",");
    }
    return str;
}