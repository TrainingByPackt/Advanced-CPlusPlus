//============================================================================
// Name        : recipe.hpp
// Author      : Brian Price
// Version     :
// Description : Exercise 1 Lesson 4
//============================================================================
#pragma once
#include <string>

class Recipe
{
public:
    Recipe(std::string name) : m_name{name} {};

    std::string Prepare()
    {
        std::string serve{"...Preparing "};
        serve += m_name;
        return serve;
    };

    std::string Cook()
    {
        std::string serve{"...Cooking "};
        serve += m_name;
        return serve;
    };

    std::string Serve()
    {
        std::string serve{"...Serving "};
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
