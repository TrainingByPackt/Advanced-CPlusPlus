//============================================================================
// Name        : Exercise4.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 4 Lesson 3
//============================================================================

#include <iostream>
#include "Stack.hpp"


int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 4 ------\n";

#if EXERCISE4_STEP >= 20
    const char* emptyStr[2] = {"not empty", "empty"};
    acpp::Stack<float> mystack;

    std::cout << "Stack is " << emptyStr[mystack.empty()] << "\n";
    std::cout << "Pushing 0.0F onto stack\n";
    mystack.push(0.0F);
    std::cout << "Stack is " << emptyStr[mystack.empty()] << "\n";
    std::cout << "Pushing 3.14159F onto stack\n";
    mystack.push(3.14159F);
    std::cout << "Stack has " << mystack.size() << " items\n";
    std::cout << "Top item is " << mystack.top() << "\n";


#endif
    std::cout << "Complete.\n";
    return 0;
}

