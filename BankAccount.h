#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string> // added

class BankAccount {
public:
    BankAccount();
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    std::string get_id() const;
    void set_id(std::string nid);

private:
    double balance = 0.0;
    std::string id = "";
};

#endif // BANK_ACCOUNT_H
