#include <stdio.h>
#include "defines.h"
#include "Account.hpp"

int main() {
    Account* account = new Account();
    Account* account2 = new Account();
    double dBalance = 0;
    double dFirstDeposit = 100.0;
    Error_nCode enErrorCode = account->getBalance(&dBalance);
    printf("Starting Account balance: %f, with error code: %d\n", dBalance, (int) enErrorCode);
    enErrorCode = account->deposit(dFirstDeposit);
    printf("Deposited %f, with error code: %d\n", dFirstDeposit, (int) enErrorCode);
    enErrorCode = account->transfer(account2, dFirstDeposit);
    printf("Transfered %f, with error code: %d\n", dFirstDeposit, (int) enErrorCode);
    return ((int) enErrorCode);
}