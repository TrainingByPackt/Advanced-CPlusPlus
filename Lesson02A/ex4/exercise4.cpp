//============================================================================
// Name        : Exercise4.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 4 Lesson 2
//============================================================================

#include <iostream>
#include <string>

enum Apple {
    RedDelicious,
    GoldenDelicious,
    Gala,
    Fuji,
    GrannySmith
};

enum Orange {
    Navel,
    Valencia,
    Hamlin,
    ParsonBrown
};

void printOrange(int orange)
{
    std::cout << "printOrange => " << orange << "\n";
}

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 4 ------\n";

    Apple apple = RedDelicious;
    Orange orange{Hamlin};

    std::cout << "apple = " << apple << "\n";
    std::cout << "orange = " << orange << "\n";

    apple = Gala;
    std::cout << "apple = " << apple << "\n";

    if (apple == orange)
    {
        std::cout << "apple == orange" << "\n";
        orange = Valencia;
    }
    else
    {
        std::cout << "apple != orange" << "\n";
    }

    printOrange(orange);
    printOrange(apple);

    std::cout << "Complete.\n";
    return 0;
}

