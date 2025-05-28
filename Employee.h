#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "BankAccount.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class Employee{ 
    public:
    /**
         Constructs an employee with a id, given name, salary, and
        bank account.
        @param id the id
        @param n the name
        @param s the annual salary
        @param a a pointer to the bank account
    */
          Employee(std::string nid, std::string nfname, std::string nlname, double nsalary, BankAccount* nacc);
    /**
         Deposits one month's salary into the bank account.
    */
          void deposit_monthly_salary();
    /**
         Prints this employee's information to cout.
    */
          void print(std::ostream& out) const;
    private:
          std::string id;
          std::string fname;
          std::string lname;
          double salary;
          BankAccount* account;
};
#endif 