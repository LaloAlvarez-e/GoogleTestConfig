#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Validator.hpp"

class ValidatorMocked: public Validator {
    public:
        ValidatorMocked(int32_t i32LowerLimit, int32_t i32UpperLimit): Validator(i32LowerLimit, i32UpperLimit) {}
        MOCK_METHOD(Error_nCode, inRange, (int32_t));
        MOCK_METHOD(Error_nCode, setLimits, (int32_t, int32_t));
        MOCK_METHOD(Error_nCode, getLimits, (int32_t *, int32_t *));
        MOCK_METHOD(Error_nCode, setLowerLimit, (int32_t));
        MOCK_METHOD(Error_nCode, getLowerLimit, (int32_t *));
        MOCK_METHOD(Error_nCode, setUpperLimit, (int32_t));
        MOCK_METHOD(Error_nCode, getUpperLimit, (int32_t *));
};


TEST(ValidatorTest, TestInRange) {
    ValidatorMocked validator{0, 100};
    EXPECT_CALL(validator, inRange(50)).Times(1).WillOnce(testing::Return(Error_enCode_OK));
    Error_nCode enErrorCode = validator.inRange(50);
    ASSERT_EQ(enErrorCode, Error_enCode_OK);
}

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




class ValidatorTestFixtureTuple: public ::testing::TestWithParam<std::tuple<int,Error_nCode>> {
    protected:
    public:
        ValidatorTestFixtureTuple() {
            printf("Constructor Called\n");
        }
        ~ValidatorTestFixtureTuple() {
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



class ValidatorTestTuple: public ValidatorTestFixtureTuple {
    protected:
        Validator validator{16, 100};
    public:
};

TEST_P(ValidatorTestTuple, TestTuple) {
    std::tuple<int,Error_nCode> tuple = GetParam();
    int value = std::get<0>(tuple);
    Error_nCode expected = std::get<1>(tuple);
    printf("TestInRange Called with value: %d, and expected result: %d\n", value, (int) expected);
    Error_nCode enErrorCode = validator.inRange(value);

    ASSERT_EQ(enErrorCode, expected);
}

INSTANTIATE_TEST_SUITE_P(TestTupleOK, ValidatorTestTuple, ::testing::Values(
                                                                std::make_tuple(0, Error_enCode_INVALID_VALUE), 
                                                                std::make_tuple(50, Error_enCode_OK), 
                                                                std::make_tuple(100, Error_enCode_OK)));

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