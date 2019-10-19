//============================================================================
// Name        : Exercise8.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 2 Lesson 3
//============================================================================

#include <iostream>
#include <vector>

void printVector(std::vector<int>& ary)
{
    std::cout << "Array is : ";
    for(std::vector<int>::iterator it{ary.begin()}; it != ary.end() ; ++it)
    {
        std::cout << *it << ",";
    }
    std::cout << "\n";
}

int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 2 ------\n";

    std::vector<int> ary = {2,4,6,1,3,5};

    printVector(ary);

    std::cout << "Complete.\n";
    return 0;
}
