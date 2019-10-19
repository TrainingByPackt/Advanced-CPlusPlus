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

#if EXERCISE1_STEP>= 27
TEST_F(StackTest, PopEmptyStackThrowsUnderFlowException)
{
    acpp::Stack<int>  stack;

    ASSERT_TRUE(stack.empty());
    // ASSERT_THROW confirms the type of exception thrown
    ASSERT_THROW(({
         try
         {
             stack.pop();
         }
         catch( const std::underflow_error& e )
         {
             // and this tests that it has the correct message
             EXPECT_STREQ( "Pop from empty stack", e.what() );
             throw;  // Re-throw for the EXPECT_THROW to check
         }
     }), std::underflow_error );

}
#endif

#if EXERCISE1_STEP>= 31
TEST_F(StackTest, TopEmptyStackThrowsUnderFlowException)
{
    acpp::Stack<int>  stack;

    ASSERT_TRUE(stack.empty());
    // ASSERT_THROW confirms the type of exception thrown
    ASSERT_THROW(({
         try
         {
             stack.top();
         }
         catch( const std::underflow_error& e )
         {
             // and this tests that it has the correct message
             EXPECT_STREQ( "Top from empty stack", e.what() );
             throw;  // Re-throw for the EXPECT_THROW to check
         }
     }), std::underflow_error );

}
#endif

#if EXERCISE1_STEP>= 35
TEST_F(StackTest, TopEmptyConstStackThrowsUnderFlowException)
{
    acpp::Stack<int>  stack;
    const acpp::Stack<int>& rstack{stack};

    ASSERT_TRUE(stack.empty());
    // ASSERT_THROW confirms the type of exception thrown
    ASSERT_THROW(({
         try
         {
             rstack.top();
         }
         catch( const std::underflow_error& e )
         {
             // and this tests that it has the correct message
             EXPECT_STREQ( "Top from empty stack", e.what() );
             throw;  // Re-throw for the EXPECT_THROW to check
         }
     }), std::underflow_error );

}
#endif

TEST_F(StackTest, DefaultConstructorInitsEmpty)
{
	acpp::Stack<int>  stack;

	ASSERT_TRUE(stack.empty());
}

TEST_F(StackTest, PushOntoStackNotEmpty)
{
    acpp::Stack<int>  stack;

    stack.push(42);
    ASSERT_FALSE(stack.empty());
}

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
