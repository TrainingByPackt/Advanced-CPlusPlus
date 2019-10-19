//============================================================================
// Name        : Exercise7.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 7 Lesson 2
//============================================================================

#include <iostream>
#include "Fraction.hpp"


int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 7 ------\n";

    Fraction fraction(5);

    std::cout << fraction << "\n";
    Fraction f1(1, 24);
    Fraction f2(3, 5);
    std::cout << f1 << " * " << f2 << " = " << f1*f2 << "\n";
    std::cout << f1 << " + " << f2 << " = " << f1+f2 << "\n";
    std::cout << f1 << " - " << f2 << " = " << f1-f2 << "\n";
    std::cout << f1 << " / " << f2 << " = " << f1/f2 << "\n";


    std::cout << "sizeof(Fraction) = " << sizeof(Fraction) << " bytes\n";
    std::cout << "sizeof(Fraction.m_numerator)   = " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(Fraction.m_denominator) = " << sizeof(int) << " bytes\n";


    std::cout << "Complete.\n";
    return 0;
}

