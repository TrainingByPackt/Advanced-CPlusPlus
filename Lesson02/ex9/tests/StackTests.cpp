//============================================================================
// Name        : StackTests.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 9 Lesson 2
//============================================================================
#include "gtest/gtest.h"
#include "../Stack.hpp"


class StackTest : public ::testing::Test
{

};


TEST_F(StackTest, DefaultConstructorInitsEmpty)
{
	acpp::Stack<int>  stack;

#if EXERCISE9_STEP >= 10
	ASSERT_FALSE(stack.empty());
#endif
}

#if EXERCISE9_STEP >= 15
TEST_F(StackTest, PushOntoStackNotEmpty)
{
    acpp::Stack<int>  stack;

    stack.push(42);
    ASSERT_FALSE(stack.empty());
}
#endif

#if EXERCISE9_STEP >= 16
TEST_F(StackTest, PushOntoStackChangesSizeByOne)
{
    acpp::Stack<int>  stack;

    ASSERT_EQ(0, stack.size());
    ASSERT_TRUE(stack.empty());
    stack.push(42);
    ASSERT_EQ(1, stack.size());
    ASSERT_FALSE(stack.empty());
    stack.push(321);
    ASSERT_EQ(2, stack.size());
}
#endif

#if EXERCISE9_STEP >= 18
TEST_F(StackTest, PopFromStackReducesSizeByOne)
{
    acpp::Stack<int>  stack;

    ASSERT_EQ(0, stack.size());
    stack.push(42);
    ASSERT_EQ(1, stack.size());
    stack.push(321);
    ASSERT_EQ(2, stack.size());
    stack.pop();
    ASSERT_EQ(1, stack.size());
    stack.pop();
    ASSERT_EQ(0, stack.size());
    ASSERT_TRUE(stack.empty());
}
#endif

#if EXERCISE9_STEP >= 20
TEST_F(StackTest, TopGetsYoungestItemOnStack)
{
    acpp::Stack<int>  stack;

    ASSERT_EQ(0, stack.size());
    stack.push(42);
    ASSERT_EQ(1, stack.size());
    stack.push(321);
    ASSERT_EQ(321, stack.top());
    stack.pop();
    ASSERT_EQ(42, stack.top());
    stack.pop();
    ASSERT_EQ(0, stack.size());
    ASSERT_TRUE(stack.empty());
}
#endif
