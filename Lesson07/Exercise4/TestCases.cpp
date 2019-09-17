#include"CheckIp.h"
#include<gtest/gtest.h>

using namespace std;

const char * testIp;

TEST(CheckIp, testNull) { 
    testIp=NULL;
	ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, BadLength) {
    testIp = "232.13.1231.1321.123";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, WrongTokenCount) {
    testIp = "22.1311.11";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, WrongTokenEmpty) {
    testIp = "22.131..11";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, WrongTokenStart) {
    testIp = ".2.1.31.11";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, WrongTokenEnd) {
    testIp = "2.13.11.1.";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, SpaceToken) {
    testIp = "2.13.11. 1";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, NonDigit) {
    testIp = "2.13.b1.A1";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, NonValidDigit) {
    testIp = "2.13.521.61";
    ASSERT_FALSE(checkValidIp(testIp));
}

TEST(CheckIp, CorrectIp) {
    testIp = "232.13.123.1";
    ASSERT_TRUE(checkValidIp(testIp));
}

