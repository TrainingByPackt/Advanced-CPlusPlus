//============================================================================
// Name        : containsTests.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "gtest/gtest.h"
#include "../contains.hpp"
#include <string>
#include <set>
#include <vector>


class containsTest : public ::testing::Test
{
public:
};


TEST_F(containsTest, DetectNpos)
{
    ASSERT_TRUE(has_npos_v<std::string>);
    ASSERT_FALSE(has_npos_v<std::set<int>>);
    ASSERT_FALSE(has_npos_v<std::vector<int>>);
}

TEST_F(containsTest, DetectFind)
{
    ASSERT_TRUE((has_find_v<std::string, char>));
    ASSERT_TRUE((has_find_v<std::set<int>, int>));
    ASSERT_FALSE((has_find_v<std::vector<int>, int>));
}

TEST_F(containsTest, VectorContains)
{
    std::vector<int> container {1,2,3,4,5};

    ASSERT_TRUE(contains(container, 5));
    ASSERT_FALSE(contains(container, 15));
}

TEST_F(containsTest, SetContains)
{
    std::set<int> container {1,2,3,4,5};

    ASSERT_TRUE(contains(container, 5));
    ASSERT_FALSE(contains(container, 15));
}


TEST_F(containsTest, StringContains)
{
    std::string container{"This is the message"};

    ASSERT_TRUE(contains(container, "the"));
    ASSERT_TRUE(contains(container, 'm'));
    ASSERT_FALSE(contains(container, "massage"));
    ASSERT_FALSE(contains(container, 'z'));
}

