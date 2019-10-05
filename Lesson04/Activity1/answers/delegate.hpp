//============================================================================
// Name        : delegate.hpp
// Author      : Brian Price
// Version     :
// Description : Activity 1 Lesson 4
//============================================================================
#pragma once

#include <functional>
#include <vector>

template<typename... ArgTypes>
class Delegate
{
public:
    Delegate() = default;

    Delegate& operator+=(const std::function<void(ArgTypes...)>& delegate)
    {
        m_delegates.push_back(delegate);
        return *this;
    }

    void Notify(ArgTypes&&... args) const
    {
        for(auto& delegate : m_delegates)
        {
            delegate(std::forward<ArgTypes>(args)...);
        }
    }

    void operator()(ArgTypes&&... args)
    {
        Notify(std::forward<ArgTypes>(args)...);
    }
private:
    std::vector<std::function<void(ArgTypes...)>> m_delegates;
};

