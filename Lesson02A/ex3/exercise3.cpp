//============================================================================
// Name        : Exercise3.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 3 Lesson 2
//============================================================================

#include <iostream>
#include <string>

void print_array_size(int* ary)
{
    std::cout << "---print_array_size---\n";
    std::cout << "sizeof(ary) = " << sizeof(ary) << "\n";
    std::cout << "elements in (ary) = " << sizeof(ary)/sizeof(ary[0]) << "\n";
}

void print_array_size2(int ary[10])
{
    std::cout << "---print_array_size2---\n";
    std::cout << "sizeof(ary) = " << sizeof(ary) << "\n";
    std::cout << "elements in (ary) = " << sizeof(ary)/sizeof(ary[0]) << "\n";
}

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 3 ------\n";

    int value = 42;       // declare value to be an integer and initialise to 42
    int* pvalue{&value};  // delcare a pointer to an int and point it at value

    std::cout << "value = " << value << "\n";
    std::cout << "Setting value via pvalue\n";
    *pvalue = 96;
    std::cout << "value = " << value << "\n\n";

    int ary[15]{};        // declare array and set to all zeros
    std::cout << "sizeof(ary) = " << sizeof(ary) << "\n";
    std::cout << "elements in (ary) = " << sizeof(ary)/sizeof(ary[0]) << "\n";
    print_array_size(ary);
    print_array_size2(ary);
    std::cout << '\n';

    char buffer[20] = "Hello, World";
    std::cout << "buffer = '" << buffer << "'\n";
    char* p = buffer;
    *(p+1) = 'a';
    std::cout << "buffer = '" << buffer << "' - after *(p+1) = 'a'; \n";
    std::cout << '\n';

    auto title = "Sir Robin of Loxley"; // Let the compiler determine the type
    // p = title;            // Step 11 - remove comment

    std::cout << "Complete.\n";
    return 0;
}

