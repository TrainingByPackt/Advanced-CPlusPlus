//============================================================================
// Name        : Exercise2.cpp
// Author      : Brian Price
// Version     :
// Description : Exercise 2 Lesson 4
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char**argv)
{
    std::cout << "\n------ Exercise 2 ------\n";
    std::vector<int> values {1,2,3,4,5,6,7,8,9,10};

    std::cout << "Average of [";
    for( auto n : values )
        std::cout << n << ", ";
    std::cout << "] = ";

    std::cout << "??\n";
    std::cout << "Complete.\n";
    return 0;
}
