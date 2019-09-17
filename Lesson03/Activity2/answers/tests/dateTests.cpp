//============================================================================
// Name        : datetests.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 2 Lesson 3
//============================================================================
#include "gtest/gtest.h"
#include "../date.hpp"

using namespace acpp::date;

class DateTest : public ::testing::Test
{
public:
    void VerifyDate(const Date& dt, int yearExp, int monthExp, int dayExp) const
    {
        ASSERT_EQ(dayExp, dt.Day());
        ASSERT_EQ(monthExp, dt.Month());
        ASSERT_EQ(yearExp, dt.Year());
    }
};

TEST_F(DateTest, DefaultConstructor)
{
    Date dt;
    VerifyDate(dt, 1970, 1, 1);
}

TEST_F(DateTest, Constructor1970Jan2)
{
    Date dt(2, 1, 1970);
    VerifyDate(dt, 1970, 1, 2);
}

TEST_F(DateTest, ToDateTDefaultIsZero)
{
    Date dt;
    ASSERT_EQ(0, dt.ToDateT());
}

TEST_F(DateTest, ToDateT1970Jan2Is1)
{
    Date dt(2, 1, 1970);
    ASSERT_EQ(1, dt.ToDateT());
}

TEST_F(DateTest, ToDateT1970Dec31Is364)
{
    Date dt(31, 12, 1970);
    ASSERT_EQ(364, dt.ToDateT());
}

TEST_F(DateTest, ToDateT1971Jan1Is365)
{
    Date dt(1, 1, 1971);
    ASSERT_EQ(365, dt.ToDateT());
}

TEST_F(DateTest, ToDateT1973Jan1Is1096)
{
    Date dt(1, 1, 1973);
    ASSERT_EQ(365*3+1, dt.ToDateT());
}

TEST_F(DateTest, ToDateT2019Aug28Is18136)
{
    Date dt(28, 8, 2019);
    ASSERT_EQ(18136, dt.ToDateT());
}

TEST_F(DateTest, FromDateT0Is1Jan1970)
{
    Date dt;
    dt.FromDateT(0);
    ASSERT_EQ(0, dt.ToDateT());
    VerifyDate(dt, 1970, 1, 1);
}

TEST_F(DateTest, FromDateT1Is2Jan1970)
{
    Date dt;
    dt.FromDateT(1);
    ASSERT_EQ(1, dt.ToDateT());
    VerifyDate(dt, 1970, 1, 2);
}

TEST_F(DateTest, FromDateT364Is31Dec1970)
{
    Date dt;
    dt.FromDateT(364);
    ASSERT_EQ(364, dt.ToDateT());
    VerifyDate(dt, 1970, 12, 31);
}

TEST_F(DateTest, FromDateT365Is1Jan1971)
{
    Date dt;
    dt.FromDateT(365);
    ASSERT_EQ(365, dt.ToDateT());
    VerifyDate(dt, 1971, 1, 1);
}

TEST_F(DateTest, FromDateT1096Is1Jan1973)
{
    Date dt;
    dt.FromDateT(1096);
    ASSERT_EQ(1096, dt.ToDateT());
    VerifyDate(dt, 1973, 1, 1);
}

TEST_F(DateTest, FromDateT18136Is28Aug2019)
{
    Date dt;
    dt.FromDateT(18136);
    ASSERT_EQ(18136, dt.ToDateT());
    VerifyDate(dt, 2019, 8, 28);
}

TEST_F(DateTest, AddZeroDays)
{
    Date dt(28, 8, 2019);
    Days days;

    dt += days;
    VerifyDate(dt, 2019, 8, 28);
}

TEST_F(DateTest, AddFourDays)
{
    Date dt(28, 8, 2019);
    Days days(4);

    dt += days;
    VerifyDate(dt, 2019, 9, 1);
}

TEST_F(DateTest, AddFourDaysAsInt)
{
    Date dt(28, 8, 2019);

    dt += static_cast<Days>(4);
    VerifyDate(dt, 2019, 9, 1);
}

TEST_F(DateTest, DateDifferences27days)
{
    Date dt1(28, 8, 2019);
    Date dt2(1, 8, 2019);

    Days days = dt1 - dt2;
    ASSERT_EQ(27, (int)days);
}

TEST_F(DateTest, DateDifferences365days)
{
    Date dt1(28, 8, 2019);
    Date dt2(28, 8, 2018);

    Days days = dt1 - dt2;
    ASSERT_EQ(365, (int)days);
}
