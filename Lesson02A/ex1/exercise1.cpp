//============================================================================
// Name        : Exercise1.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 1 Lesson 2
//============================================================================
#include <iostream>
#include <string>

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 1 ------\n";

    int value = 42;     // declare value to be an integer & initialise to 42
    short a_value{64};  // declare a_value to be a short integer &
                        // initialise to 64
    int bad_idea;       // declare bad_idea to be an integer and DO NOT 
                        // initialise it. Use of this variable before 
                        // setting it is UNDEFINED BEHAVIOUR.

    float pi = 3.1415F; // declare pi to be a single precision floating
                        // point number and initialise it to pi.
                         
    double e{2.71828};  // declare e to be a double precision floating point
                        // number and initialise it to natural number e.

    auto title = "Sir Robin of Loxley";
                        // Let the compiler determine the type
    int ary[15]{};      // array of 15 integers - zero initialised

    // double pi = 3.14159;  // step 24 - remove comment at front
    // auto speed;           // step 25 - remove comment at front
    // value = "Hello world";// step 26 - remove comment at front
    // title = 123456789;    // step 27 - remove comment at front
    // short sh_int{32768};  // step 28 - remove comment at front

    std::cout << "sizeof(int) = " << sizeof(int) << "\n";
    std::cout << "sizeof(short) = " << sizeof(short) << "\n";
    std::cout << "sizeof(float) = " << sizeof(float) << "\n";
    std::cout << "sizeof(double) = " << sizeof(double) << "\n";
    std::cout << "sizeof(title) = " << sizeof(title) << "\n";
    std::cout << "sizeof(ary) = " << sizeof(ary)
              << " = " << sizeof(ary)/sizeof(ary[0]) 
              << " * " << sizeof(ary[0]) << "\n";
    std::cout << "Complete.\n";
    return 0;
}
