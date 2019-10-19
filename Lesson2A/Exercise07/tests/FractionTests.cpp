//============================================================================
// Name        : Exercise7.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 7 Lesson 2
//============================================================================
#include "gtest/gtest.h"
#include "../Fraction.hpp"
#include <sstream>


class FractionTest : public ::testing::Test
{

};


TEST_F(FractionTest, DefaultConstructorInitsZero)
{
    Fraction f1;

    ASSERT_EQ(0, f1.getNumerator());
    ASSERT_EQ(1, f1.getDenominator());
}

TEST_F(FractionTest, ConstructorInitToInteger)
{
    Fraction f1{-5};

    ASSERT_EQ(-5, f1.getNumerator());
    ASSERT_EQ(1, f1.getDenominator());
}


TEST_F(FractionTest, ConstructorNormaliseFraction)
{
    Fraction f1{1,-5};

    ASSERT_EQ(-1, f1.getNumerator());
    ASSERT_EQ(5, f1.getDenominator());
}


TEST_F(FractionTest, ConstructorNormaliseFraction2)
{
    Fraction f1{4,-8};

    ASSERT_EQ(-1, f1.getNumerator());
    ASSERT_EQ(2, f1.getDenominator());
}



TEST_F(FractionTest, MultiplyFractions)
{
    Fraction f1{4,-8};
    Fraction f2{7,3};

    f1 *= f2;
    ASSERT_EQ(-7, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}

TEST_F(FractionTest, MultiplyFractions2)
{
    Fraction f3{4,-8};
    Fraction f2{7,3};

    Fraction f1 = f2 * f3;
    ASSERT_EQ(-7, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}

#if EXERCISE7_STEP >= 11
TEST_F(FractionTest, AddFractions)
{
    Fraction f1{1,2};
    Fraction f2{1,3};

    f1 += f2;
    ASSERT_EQ(5, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}

TEST_F(FractionTest, AddFractions2)
{
    Fraction f3{1,2};
    Fraction f2{1,3};

    Fraction f1 = f2 + f3;
    ASSERT_EQ(5, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}
#endif


#if EXERCISE7_STEP >= 15
TEST_F(FractionTest, SubtractFractions)
{
    Fraction f1{1,2};
    Fraction f2{1,3};

    f1 -= f2;
    ASSERT_EQ(1, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}

TEST_F(FractionTest, SubtractFractions2)
{
    Fraction f3{1,2};
    Fraction f2{1,3};

    Fraction f1 = f3 - f2;
    ASSERT_EQ(1, f1.getNumerator());
    ASSERT_EQ(6, f1.getDenominator());
}
#endif

#if EXERCISE7_STEP >= 19
TEST_F(FractionTest, DivideFractions)
{
    Fraction f1{1,2};
    Fraction f2{5,6};

    f1 /= f2;
    ASSERT_EQ(3, f1.getNumerator());
    ASSERT_EQ(5, f1.getDenominator());
}

TEST_F(FractionTest, DivideFractions2)
{
    Fraction f3{1,2};
    Fraction f2{5,6};

    Fraction f1 = f3 / f2;
    ASSERT_EQ(3, f1.getNumerator());
    ASSERT_EQ(5, f1.getDenominator());
}
#endif

#if EXERCISE7_STEP >= 23
TEST_F(FractionTest, InsertOperator)
{
    std::stringstream out;
    Fraction f3{-22,7};

    out << f3;

    ASSERT_STREQ("-22 / 7", out.str().c_str());
}
#endif
