#include <stdio.h>
#include "defines.h"
#include "sum.h"

int main() {
    int a = 5;
    int b = 10;
    int result = 0;
    Error_nCode enErrorCode = sum(a, b, &result);
    printf("The sum of %d and %d is %d\n", a, b, result);
    return ((int) enErrorCode);
}