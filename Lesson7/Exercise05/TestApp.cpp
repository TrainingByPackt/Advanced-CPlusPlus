#include"MockMisc.h"

using ::testing::_;
using ::testing::Return;

class TestApp : public ::testing::Test {
    protected : 
        App testApp;
        MockDB *mdb;

        void SetUp(){
            mdb = new MockDB();
            testApp.connectDB(mdb);
        }

        void TearDown(){
        }
};

TEST_F(TestApp, NullIP){
    EXPECT_CALL(*mdb, getResult(_)).
                 WillOnce(Return(""));

    ASSERT_FALSE(testApp.checkValidIp(testApp.getDBResult("")));
}

TEST_F(TestApp, SpaceTokenIP){
    EXPECT_CALL(*mdb, getResult(_)).
                 WillOnce(Return("13. 21.31.68"));

    ASSERT_FALSE(testApp.checkValidIp(testApp.getDBResult("")));
}

TEST_F(TestApp, NonValidDigitIP){
    EXPECT_CALL(*mdb, getResult(_)).
                 WillOnce(Return("13.521.31.68"));

    ASSERT_FALSE(testApp.checkValidIp(testApp.getDBResult("")));
}

TEST_F(TestApp, CorrectIP){
    EXPECT_CALL(*mdb, getResult(_)).
                 WillOnce(Return("212.121.21.45"));

    ASSERT_TRUE(testApp.checkValidIp(testApp.getDBResult("")));
}

