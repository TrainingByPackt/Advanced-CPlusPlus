//============================================================================
// Name        : dessert.hpp
// Author      : Brian Price
// Version     :
// Description : Exercise 1 Lesson 4
//============================================================================
#pragma once
#include <string>

class Dessert
{
public:
    Dessert(std::string name) : m_name {name} {};
    std::string Serve()
    {
        std::string serve{"---Serving "};
        serve += m_name;
        return serve;
    };

    std::string GetName() const
    {
        return m_name;
    }


private:
    std::string m_name;
};
