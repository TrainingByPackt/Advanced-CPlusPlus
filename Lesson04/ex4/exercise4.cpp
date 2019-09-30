//============================================================================
// Name        : Exercise4.cpp
// Author      : Brian Price
// Version     :
// Description : Exercise 4 Lesson 4
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>

void PrintVector(const char* prefix, std::vector<int>& values)
{
    const char* sep = "";
    std::cout << prefix << " = [";
    for(auto n : values)
    {
        std::cout << sep << n;
        sep = ", ";
    }
    std::cout << "]\n";
}

int main(int argc, char**argv)
{
    std::cout << "\n------ Exercise 4 ------\n";
    std::vector<int> values{ 46, 27, 26, 27, 32, 1, 18, 50, 21, 49 };

    PrintVector("Initial Vector", values);

    std::cout << "Complete.\n";
    return 0;
}
