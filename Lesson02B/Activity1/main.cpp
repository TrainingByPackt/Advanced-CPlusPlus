//============================================================================
// Name        : main.cpp
// Author      : Brian Price
// Version     :
// Description : Activity 1 Lesson 3
//============================================================================
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "contains.hpp"

// #define ACTIVITY1


int main()
{
    std::cout << "\n------ Activity 1 ------\n";
#if defined(ACTIVITY1)
    std::set<int> mySet {1,2,3,4,5};

    std::cout << std::boolalpha;
    std::cout << "Set contains 5: " << contains(mySet,5) << "\n";
    std::cout << "Set contains 15: " << contains(mySet,15) << "\n";

    std::vector<int> myVector{1,2,3,4,5};
    std::cout << "Vector contains 5: " << contains(myVector,5) << "\n";
    std::cout << "Vector contains 15: " << contains(myVector,15) << "\n";

    std::string myString{"It was the best of times, it was the worst of times,"};

    std::cout << "String contains 'times': " << contains(myString, "times") << "\n";
    std::cout << "String contains 'Light': " << contains(myString, "Light") << "\n";
    std::cout << "String contains 'm': " << contains(myString, 'm') << "\n";
    std::cout << "String contains 'z': " << contains(myString, 'z') << "\n";

#else
    std::cout << "\nWait until the implementation of contains template is complete.\n";
    std::cout << "\nThen remove comment from #define ACTIVITY1 and re-run\n";
#endif
    std::cout << "\nComplete.\n";
    return 0;
}




