//============================================================================
// Name        : kitchen.cpp
// Author      : Brian Price
// Version     :
// Description : Exercise 1 Lesson 4
//============================================================================
#include <iostream>
#include <algorithm>
#include <sstream>
#include <exception>
#include "kitchen.hpp"

Kitchen::Kitchen(std::string chef) : m_chef{chef}
{
    m_recipes.push_back(Recipe("Spaghetti Bolognese"));
    m_recipes.push_back(Recipe("Steak Diane"));
    m_recipes.push_back(Recipe("Lamb Ragout"));

    m_desserts.push_back(Dessert("Pavlova"));
    m_desserts.push_back(Dessert("Creme Brulee"));
    m_desserts.push_back(Dessert("Baked Alaska"));

}

std::string Kitchen::processOrder(std::string order)
{
    std::stringstream os;
    os << "Chef '" << m_chef << "' is serving you tonight\n";

    auto recipe = searchForRecipe(order);
    if (!recipe.empty())
    {
        os << cookRecipe(recipe);
        return os.str();
    }
    auto dessert = searchForDessert(order);
    if (!dessert.empty())
    {
        os << serveDessert(dessert);
        return os.str();
    }
    os << "#### sacre bleu: '" << order << "'";
    throw std::invalid_argument(os.str());
}

std::string Kitchen::searchForRecipe(std::string order)
{
    auto position = getRecipe(order);
    return (position != m_recipes.end() ? order : "");
}

std::string Kitchen::searchForDessert(std::string order)
{
    auto position = getDessert(order);
    return (position != m_desserts.end() ? order : "");
}

std::string Kitchen::cookRecipe(std::string order)
{
    std::stringstream os;
    auto position = getRecipe(order);
    auto recipe = *position;

    os << recipe.Prepare() << "\n";
    os << recipe.Cook() << "\n";
    os << recipe.Serve() << "\n";
    return os.str();
}

std::string Kitchen::serveDessert(std::string order)
{
    std::stringstream os;
    auto position = getDessert(order);
    auto dessert = *position;
    os << dessert.Serve() << "\n";
    return os.str();
}

std::vector<Recipe>::iterator Kitchen::getRecipe(std::string recipe)
{
    auto iter = m_recipes.begin();
    while( iter != m_recipes.end() )
    {
        if (iter->GetName() == recipe)
            break;
        ++iter;
    }
    return iter;
}

std::vector<Dessert>::iterator Kitchen::getDessert(std::string recipe)
{
    auto iter = m_desserts.begin();
    while( iter != m_desserts.end() )
    {
        if (iter->GetName() == recipe)
            break;
        ++iter;
    }
    return iter;

}

