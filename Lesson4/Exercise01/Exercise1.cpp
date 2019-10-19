//============================================================================
// Name        : Exercise1.cpp
// Author      : Brian Price
// Version     :
// Description : Exercise 1 Lesson 4
//============================================================================
#include <iostream>
#include "kitchen.hpp"
#include <exception>
#include <vector>


int main(int argc, char**argv)
{
    std::cout << "\n------ Kitchen Exercise 1 ------\n";
    Kitchen kitchen("TheChef");

    std::vector<const char*> orders {"Lamb Ragout", "Baked Alaska", "Turkey", "Steak Diane", "Pavlova"};

    for(auto order : orders)
    {
        try
        {
            std::cout << kitchen.processOrder(order);
        }
        catch(std::exception& ex)
        {
            std::cout << ex.what() << "\n";
        }
    }

    std::cout << "Complete.\n";
    return 0;
}


