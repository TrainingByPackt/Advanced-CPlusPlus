//============================================================================
// Name        : point3dtest.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "gtest/gtest.h"
#include "../point3d.hpp"
#include <sstream>
#include <string>

using namespace acpp::gfx;

class Point3dTest : public ::testing::Test
{
public:
    static constexpr float epsilon{1e-12};

    template<size_t size>
    void VerifyPoint(Point3d& pt, float (&expected)[size])
    {

        for(size_t i=0 ; i< size ; i++)
        {
            ASSERT_NEAR(expected[i], pt(i), epsilon) << "cell [" << i << "]";
        }
    }
};


TEST_F(Point3dTest, DefaultConstructorIsOrigin)
{
    Point3d pt;
    float expected[4] = {0,0,0,1};

    VerifyPoint(pt, expected);
}

TEST_F(Point3dTest, InitListConstructor3)
{
    Point3d pt {5.2, 3.5, 6.7};
    float expected[4] = {5.2,3.5,6.7,1};

    VerifyPoint(pt, expected);
}

TEST_F(Point3dTest, InitListConstructor4)
{
    Point3d pt {5.2, 3.5, 6.7, 2.0};
    float expected[4] = {5.2,3.5,6.7,2.0};

    VerifyPoint(pt, expected);
}

TEST_F(Point3dTest, EqualityOperatorEqual)
{
    Point3d pt1;
    Point3d pt2;

    ASSERT_EQ(pt1, pt2);
}

TEST_F(Point3dTest, EqualityOperatorNotEqual)
{
    Point3d pt1 {1,2,3};
    Point3d pt2 {1,2,4};

    ASSERT_NE(pt1, pt2);
}
