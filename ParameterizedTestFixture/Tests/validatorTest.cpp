#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Validator.hpp"

class ValidatorTestFixture: public ::testing::TestWithParam<int> {
    protected:
    public:
        ValidatorTestFixture() {
            printf("Constructor Called\n");
        }
        ~ValidatorTestFixture() {
            printf("Destructor Called\n");
        }
        void SetUp() override {
            printf("SetUp Called\n");
        }
        void TearDown() override {
            printf("TearDown Called\n");
        }
        static void SetUpTestCase() {
            printf("SetUpTestCase Called\n");
        }
        static void TearDownTestCase() {
            printf("TearDownTestCase Called\n");
        }
};

class ValidatorTestRange: public ValidatorTestFixture {
    protected:
        Validator validator{0, 100};
    public:
};

TEST_P(ValidatorTestRange, TestInRange) {
    int value = GetParam();
    printf("TestInRange Called with value: %d\n", value);
    Error_nCode enErrorCode = validator.inRange(value);

    ASSERT_EQ(enErrorCode, Error_enCode_OK);
}

class ValidatorTestNoRange: public ValidatorTestFixture {
    protected:
        Validator validator{0, 100};
    public:
};

TEST_P(ValidatorTestNoRange, TestInvalidRange) {
    int value = GetParam();
    printf("TestInRange Called with value: %d\n", value);
    Error_nCode enErrorCode = validator.inRange(value);

    ASSERT_EQ(enErrorCode, Error_enCode_INVALID_VALUE);
}

INSTANTIATE_TEST_SUITE_P(TestInRangeTrue, ValidatorTestRange, ::testing::Values(0, 50, 100));
INSTANTIATE_TEST_SUITE_P(TestInRangeFalse, ValidatorTestNoRange, ::testing::Values(-100, -1 , 101, 250, 10000));

int main(int argc, char **argv) {

    /*
    #ifdef __unix__
        ::testing::GTEST_FLAG(filter) = "unixSuite:*"
     #else
        ::testing::GTEST_FLAG(filter) = "windowsSuite:*";
    #endif
    */
    ::testing::FLAGS_gtest_output = "xml:../testResults.xml";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}