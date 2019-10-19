//============================================================================
// Name        : exercise5.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 5 Lesson 3
//============================================================================
#include <iostream>
#include <iomanip>
#include <vector>

template<class T>
bool empty(const T& x)
{
    return x.empty();
}

template<class T>
int size(const T& x)
{
    return x.size();
}

int main()
{
    std::cout << "\n\n------ Exercise 5 ------\n";
    std::vector<int> numbers;

    std::cout << "Before adding numbers...\n";
    std::cout << std::boolalpha;
    std::cout << "numbers.empty => " << numbers.empty() << "\n";
    std::cout << "empty(numbers) => " << empty(numbers) << "\n";
    std::cout << "size(numbers) => " << size(numbers) << "\n";

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);

    std::cout << "After adding numbers...\n";
    std::cout << "numbers.empty => " << numbers.empty() << "\n";
    std::cout << "empty(numbers) => " << empty(numbers) << "\n";
    std::cout << "size(numbers) => " << size(numbers) << "\n";

    std::cout << "------ Complete. -------\n";
    return 0;
}
