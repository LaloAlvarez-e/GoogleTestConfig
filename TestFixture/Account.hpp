#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "defines.h"

class Account
{
    public:
        Account();
        ~Account();
        Error_nCode deposit(double amount);
        Error_nCode withdraw(double amount);
        Error_nCode getBalance(double *balance);
        Error_nCode transfer(Account *toAccount, double amount);
    private:
        double d_Balance;
};

#endif // ACCOUNT_HPP