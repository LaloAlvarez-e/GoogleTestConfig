#include "Validator.hpp"

Validator::Validator(int32_t i32LowerLimit, int32_t i32UpperLimit) {
    i32_LowerLimit = i32LowerLimit;
    i32_UpperLimit = i32UpperLimit;
}

Validator::Validator() {
    i32_LowerLimit = 0;
    i32_UpperLimit = 100;
}

Validator::~Validator() {
}

Error_nCode Validator::inRange(int32_t i32Value) {
    Error_nCode enErrorCode = Error_enCode_OK;
    if ((i32Value < i32_LowerLimit) || (i32Value > i32_UpperLimit)) {
        enErrorCode = Error_enCode_INVALID_VALUE;
    }
    return (enErrorCode);
}

Error_nCode Validator::setLowerLimit(int32_t i32LowerLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    i32_LowerLimit = i32LowerLimit;
    return (enErrorCode);
}

Error_nCode Validator::getLowerLimit(int32_t *i32LowerLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    if (NULL != i32LowerLimit) {
        *i32LowerLimit = i32_LowerLimit;
    }
    return (enErrorCode);
}

Error_nCode Validator::setUpperLimit(int32_t i32UpperLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    i32_UpperLimit = i32UpperLimit;
    return (enErrorCode);
}

Error_nCode Validator::getUpperLimit(int32_t *i32UpperLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    if (NULL != i32UpperLimit) {
        *i32UpperLimit = i32_UpperLimit;
    }
    return (enErrorCode);
}

Error_nCode Validator::setLimits(int32_t i32LowerLimit, int32_t i32UpperLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    setUpperLimit(i32_UpperLimit);
    setLowerLimit(i32_LowerLimit);
    return (enErrorCode);
}

Error_nCode Validator::getLimits(int32_t *i32LowerLimit, int32_t *i32UpperLimit) {
    Error_nCode enErrorCode = Error_enCode_OK;
    getLowerLimit(i32LowerLimit);
    getUpperLimit(i32UpperLimit);
    return (enErrorCode);
}
