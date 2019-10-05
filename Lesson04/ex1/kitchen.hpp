//============================================================================
// Name        : kitchen.hpp
// Author      : Brian Price
// Version     :
// Description : Exercise 1 Lesson 4
//============================================================================
#pragma once
#include <string>
#include <vector>

#include "recipe.hpp"
#include "dessert.hpp"

class Kitchen
{
public:
    Kitchen(std::string chef);
    std::string processOrder(std::string order);

private:
    std::string searchForRecipe(std::string order);
    std::string searchForDessert(std::string order);
    std::string cookRecipe(std::string recipe);
    std::string serveDessert(std::string dessert);

    std::vector<Recipe>::iterator getRecipe(std::string recipe);
    std::vector<Dessert>::iterator getDessert(std::string recipe);

    std::string m_chef;
    std::vector<Recipe> m_recipes;
    std::vector<Dessert> m_desserts;

};
