#include "Account.hpp"
#include <stddef.h>

Account::Account()
{
    d_Balance = 0;
}

Account::~Account()
{
}

Error_nCode Account::deposit(double dAmount)
{
    Error_nCode enErrorCode = Error_enCode_OK;
    if (dAmount < 0)
    {
        enErrorCode = Error_enCode_INVALID_INPUT;
    }
    if(Error_enCode_OK == enErrorCode)
    {
        d_Balance += dAmount;
    }
    return (enErrorCode);
}

Error_nCode Account::withdraw(double dAmount)
{
    Error_nCode enErrorCode = Error_enCode_OK;
    if (dAmount < 0)
    {
        enErrorCode = Error_enCode_INVALID_INPUT;
    }
    if(Error_enCode_OK == enErrorCode)
    {
        if(d_Balance < dAmount)
        {
            enErrorCode = Error_enCode_INVALID_VALUE;
        }
    }
    if(Error_enCode_OK == enErrorCode)
    {
        d_Balance -= dAmount;
    }
    return (enErrorCode);
}

Error_nCode Account::getBalance(double *dBalance)
{
    Error_nCode enErrorCode = Error_enCode_OK;
    if (NULL == dBalance)
    {
        enErrorCode = Error_enCode_INVALID_INPUT;
    }
    if(Error_enCode_OK == enErrorCode)
    {
        *dBalance = d_Balance;
    }
    return (enErrorCode);
}

Error_nCode Account::transfer(Account *pToAccount, double dAmount)
{
    Error_nCode enErrorCode = Error_enCode_OK;
    if ((NULL == pToAccount) || (dAmount < 0))
    {
        enErrorCode = Error_enCode_INVALID_INPUT;
    }
    if(Error_enCode_OK == enErrorCode)
    {
        enErrorCode = withdraw(dAmount);
    }
    if(Error_enCode_OK == enErrorCode)
    {
        enErrorCode = pToAccount->deposit(dAmount);
    }
    return (enErrorCode);
}