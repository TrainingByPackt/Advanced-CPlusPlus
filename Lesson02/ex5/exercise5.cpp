//============================================================================
// Name        : Exercise5.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 5 Lesson 2
//============================================================================

#include <iostream>
#include <string>

int gcd(int x, int y)
{
    while(y!=0)
    {
        auto c{x%y};
        x = y;
        y = c;
    }
    return x;
}

class Fraction
{
public:
    Fraction()
    {

    }

    int getNumerator() const
    {
        return m_numerator;
    }

    int getDenominator() const
    {
        return m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 5 ------\n";

    Fraction fraction;

    std::cout << "fraction = " << fraction.getNumerator() << "/" << fraction.getDenominator() << "\n";

    std::cout << "sizeof(Fraction) = " << sizeof(Fraction) << " bytes\n";
    std::cout << "sizeof(Fraction.m_numerator)   = " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(Fraction.m_denominator) = " << sizeof(int) << " bytes\n";


    std::cout << "Complete.\n";
    return 0;
}

