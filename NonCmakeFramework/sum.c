#include "sum.h"		
#include <stdlib.h>

Error_nCode sum(int a, int b, int *result)
{
    Error_nCode enErrorCode = Error_enCode_OK;
    if (NULL == result)
    {
        enErrorCode =  Error_enCode_UNDEF;
    }
    if(Error_enCode_OK == enErrorCode)
    {
        *result = a + b;
    }
    return (enErrorCode);
}