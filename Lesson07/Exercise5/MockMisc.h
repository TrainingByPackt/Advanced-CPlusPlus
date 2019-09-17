#include"Misc.h"
#include<gtest/gtest.h>
#include<gmock/gmock.h>


class MockDB : public ConnectDatabase {
    public :
        MockDB() {}
        virtual ~MockDB(){}

        MOCK_METHOD1(getResult, string( string) ); 
};
