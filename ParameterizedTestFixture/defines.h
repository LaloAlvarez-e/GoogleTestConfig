#ifndef DEFINES_H
#define DEFINES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum
{
    Error_enCode_OK,
    Error_enCode_ERROR,
    Error_enCode_INVALID_INPUT,
    Error_enCode_INVALID_VALUE,
    Error_enCode_UNDEF,
}Error_nCode;


#endif // DEFINES_H