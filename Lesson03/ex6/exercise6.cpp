//============================================================================
// Name        : exercise5.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 6 Lesson 3
//============================================================================
#include <iostream>

struct Voltage
{
    Voltage (float emf) : m_emf(emf)
    {
    }

    float m_emf;
};

void calculate(Voltage v)
{
    std::cout << "Calculate for " << v.m_emf << " volts\n";
}

void use_float(float value)
{
    std::cout << "use_float for " << value << "\n";
}

int main()
{
    std::cout << "\n\n------ Exercise 6 ------\n";
    Voltage volts(1.0F);

    calculate(volts);
    calculate(32);

    use_float(42);

    std::cout << "------ Complete. -------\n";
    return 0;
}




