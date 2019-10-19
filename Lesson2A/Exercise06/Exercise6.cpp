//============================================================================
// Name        : Exercise6.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 6 Lesson 2
//============================================================================

#include <iostream>
#include <string>

void swap(int& lhs, int& rhs)
{
    int tmp{lhs};
    lhs = rhs;
    rhs = tmp;
}

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 6 ------\n";

    int value = 42;       // declare value to be an integer and initialise to 42
    int& rvalue{value};  // declare a reference to an int and initialise it at value

    std::cout << "value = " << value << "\n";
    std::cout << "Setting value via rvalue\n";
    rvalue = 96;
    std::cout << "value = " << value << "\n\n";

    int a{123};
    int b{456};
    std::cout << "Swapping " << a << " and " << b << "\n";
    swap(a,b);
    std::cout << "Swapped " << a << " and " << b << "\n";


    std::cout << "value = " << value << "; rvalue = " << rvalue << "; a = " << a << "\n";
    std::cout << "Setting rvalue to a and then assigning 32 to rvalue\n";

    rvalue = 32;
    std::cout << "value = " << value << "; rvalue = " << rvalue << "; a = " << a << "\n";

    std::cout << "Complete.\n";
    return 0;
}

