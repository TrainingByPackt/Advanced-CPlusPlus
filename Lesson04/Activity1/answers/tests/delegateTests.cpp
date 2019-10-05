//============================================================================
// Name        : matrix3dTests.cpp
// Author      : Brian Price
// Version     :
// Description : Activity 1 Lesson 2
//============================================================================
#include "gtest/gtest.h"
#include "../delegate.hpp"
#include <iostream>
#include <sstream>
#include <string>

class DelegateTest : public ::testing::Test
{
public:
    void SetUp() override;
    void TearDown() override;

    std::stringstream m_buffer;

    // Save cout's buffer here
    std::streambuf *m_savedBuf{};
};

void DelegateTest::SetUp()
{
    // Save the cout buffer
    m_savedBuf = std::cout.rdbuf();
    // Redirect cout to our buffer
    std::cout.rdbuf(m_buffer.rdbuf());
}

void DelegateTest::TearDown()
{
    // Restore cout buffer to original
    std::cout.rdbuf(m_savedBuf);
}


TEST_F(DelegateTest, BasicDelegate)
{
    Delegate<int> delegate;

    ASSERT_NO_THROW(delegate.Notify(42));
    ASSERT_NO_THROW(delegate(23));
}

TEST_F(DelegateTest, SingleCallback)
{
    Delegate<int> delegate;

    delegate += [] (int value) { std::cout << "value = " << value; };
    delegate.Notify(42);
    std::string result = m_buffer.str();
    ASSERT_STREQ("value = 42", result.c_str());
}

TEST_F(DelegateTest, DualCallbacks)
{
    Delegate<int> delegate;

    delegate += [] (int value) { std::cout << "1: = " << value << "\n"; };
    delegate += [] (int value) { std::cout << "2: = " << value << "\n"; };
    delegate.Notify(12);
    std::string result = m_buffer.str();
    ASSERT_STREQ("1: = 12\n2: = 12\n", result.c_str());
}

TEST_F(DelegateTest, DualCallbacksNoArgs)
{
    Delegate delegate;

    delegate += [] () { std::cout << "CB1\n"; };
    delegate += [] () { std::cout << "CB2\n"; };
    delegate.Notify();
    std::string result = m_buffer.str();
    ASSERT_STREQ("CB1\nCB2\n", result.c_str());
}


TEST_F(DelegateTest, DualCallbacksStringAndInt)
{
    Delegate<std::string&, int> delegate;

    delegate += [] (std::string& value, int i) {
            std::cout << "1: = " << value << "," << i << "\n"; };
    delegate += [] (std::string& value, int i) {
        std::cout << "2: = " << value << "," << i << "\n"; };
    std::string hi{"hi"};
    delegate.Notify(hi, 52);
    std::string result = m_buffer.str();
    ASSERT_STREQ("1: = hi,52\n2: = hi,52\n", result.c_str());
}


