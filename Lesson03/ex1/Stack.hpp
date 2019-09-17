//============================================================================
// Name        : Stack.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 9 Lesson 2
//============================================================================
#pragma once
#include <vector>
#include <cstddef>
#include <stdexcept>

#define EXERCISE1_STEP  35

namespace acpp
{

template <typename T>
class Stack
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;

    bool empty() const
    {
        return m_stack.empty();
    }

    void push(const value_type& value)
    {
        m_stack.push_back(value);
    }

    size_type size() const
    {
        return m_stack.size();
    }

    void pop()
    {
        if(empty())
            throw std::underflow_error("Pop from empty stack");
        m_stack.pop_back();
    }

    reference top()
    {
        if(empty())
            throw std::underflow_error("Top from empty stack");
        return m_stack.back();
    }

    const_reference top() const
    {
        if(empty())
            throw std::underflow_error("Top from empty stack");
        return m_stack.back();
    }

private:
	std::vector<T> m_stack;
};

} // namespace acpp
