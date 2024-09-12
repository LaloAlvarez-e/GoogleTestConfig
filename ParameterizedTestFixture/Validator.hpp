#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "defines.h"

class Validator
{
    public:
        Validator(int32_t i32LowerLimit, int32_t i32UpperLimit);
        Validator();
        ~Validator();
        Error_nCode inRange(int32_t i32Value);
        Error_nCode setLimits(int32_t i32LowerLimit, int32_t i32UpperLimit);
        Error_nCode getLimits(int32_t *i32LowerLimit, int32_t *i32UpperLimit);
        Error_nCode setLowerLimit(int32_t i32LowerLimit);
        Error_nCode getLowerLimit(int32_t *i32LowerLimit);
        Error_nCode setUpperLimit(int32_t i32UpperLimit);
        Error_nCode getUpperLimit(int32_t *i32UpperLimit);
    private:
        int32_t i32_LowerLimit;
        int32_t i32_UpperLimit;
};

#endif // VALIDATOR_HPP