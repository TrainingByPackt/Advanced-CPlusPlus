//============================================================================
// Name        : main.cpp
// Author      : Brian Price
// Version     :
// Description : Activity 1 Lesson 4
//============================================================================
#include <iostream>
#include "delegate.hpp"

#define ACTIVITY_STEP 27


int main()
{
    std::cout << "\n------ Activity 1 ------\n";
#if ACTIVITY_STEP > 26

    std::cout << "\n------ Delegate - no args ------\n";
    Delegate delegate0;
    delegate0 += [] {std::cout << "Hello"; };
    delegate0 += [] {std::cout << ", "; };
    delegate0 += [] {std::cout << "World"; };
    delegate0();

    std::cout << "\n------ Delegate - string argument ------\n";
    Delegate<std::string&> delegate1;
    delegate1 += [] (std::string& str) {std::cout << str << "!-"; };
    delegate1 += [] (std::string& str) {std::cout << str << "?-"; };
    delegate1 += [] (std::string& str) {std::cout << str << "@-"; };

    std::string hi{"hello"};
    delegate1(hi);

    std::cout << "\n------ Delegate - binary int argument ------\n";
    Delegate<int,int> delegate2;
    delegate2 += [] (int a, int b) {std::cout << a << " + " << b << " = " << (a+b) << "\n"; };
    delegate2 += [] (int a, int b) {std::cout << a << " - " << b << " = " << (a-b) << "\n"; };
    delegate2 += [] (int a, int b) {std::cout << a << " * " << b << " = " << (a*b) << "\n"; };
    delegate2 += [] (int a, int b) {std::cout << a << " / " << b << " = " << (a/b) << "\n"; };

    delegate2(52,4);


#else

#endif
    std::cout << "\nComplete.\n";
    return 0;
}




