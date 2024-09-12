#include <gtest/gtest.h>
#include "sum.h"

Error_nCode sum(int a, int b, int *result);
// Test cases
TEST(SumTest, PositiveNumbers) {
    int result = 0;
    Error_nCode enErrorCode = sum(5, 10, &result);
    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    EXPECT_EQ(result, 15);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}