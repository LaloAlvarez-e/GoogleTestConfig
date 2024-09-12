#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.hpp"
// Test cases
TEST(AccountTest, TestEmptyAccount) {
    Account* account = new Account();
    double dBalance = 0;
    Error_nCode enErrorCode = account->getBalance(&dBalance);

    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    EXPECT_EQ(dBalance, 0);

}

class AccountTestFixture: public ::testing::Test {
    protected:
        Account* account;
        Account* account2;
        double dBalance;
        double dFinalBalance;
        double dDeposit;
        Error_nCode enErrorCode;
    public:
        AccountTestFixture() {
            printf("Constructor Called\n");
        }
        ~AccountTestFixture() {
            printf("Destructor Called\n");
        }
        void SetUp() override {
            printf("SetUp Called\n");
            account = new Account();
            account2 = new Account();
            dBalance = 0;
            dDeposit = 10.5;
            
            enErrorCode = account->deposit(dDeposit);
            EXPECT_EQ(enErrorCode, Error_enCode_OK);
        }
        void TearDown() override {
            printf("TearDown Called\n");
            enErrorCode = account->getBalance(&dBalance);
            EXPECT_EQ(enErrorCode, Error_enCode_OK);
            EXPECT_EQ(dBalance, dFinalBalance);
            delete account;
            delete account2;
        }
        static void SetUpTestCase() {
            printf("SetUpTestCase Called\n");
        }
        static void TearDownTestCase() {
            printf("TearDownTestCase Called\n");
        }
};

TEST_F(AccountTestFixture, TestDeposit) {
    dFinalBalance = dDeposit;
}

TEST_F(AccountTestFixture, TestWithDrawOK) {
    double dWitdraw = 3.5;

    enErrorCode = account->withdraw(dWitdraw);
    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    dFinalBalance = (dDeposit - dWitdraw);

}

TEST_F(AccountTestFixture, TestWithDrawInsufficientFounds) {
    double dWitdraw = dDeposit + 10;

    enErrorCode = account->withdraw(dWitdraw);
    EXPECT_EQ(enErrorCode, Error_enCode_INVALID_VALUE);
    dFinalBalance = dDeposit;

}

TEST_F(AccountTestFixture, TestTransferOK) {
    double dTransfer = 3.5;

    enErrorCode = account->transfer(account2, dTransfer);
    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    enErrorCode = account2->getBalance(&dBalance);
    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    EXPECT_EQ(dBalance, dTransfer);
    dFinalBalance = (dDeposit - dTransfer);

}

TEST_F(AccountTestFixture, TestTransferInsufficientFounds) {
    double dTransfer = dDeposit + 10;

    enErrorCode = account->transfer(account2, dTransfer);
    EXPECT_EQ(enErrorCode, Error_enCode_INVALID_VALUE);
    enErrorCode = account2->getBalance(&dBalance);
    EXPECT_EQ(enErrorCode, Error_enCode_OK);
    EXPECT_EQ(dBalance, 0);
    dFinalBalance = dDeposit;

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}