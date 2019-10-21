//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 2 Chapter 5
//============================================================================

#include <iostream>
#include <chrono>
#include <thread>

void divide(int& divisor, int& dividend)
{
	if (0 != dividend)
	{
	    std::cout << "Child thread goes sleep" << std::endl;

	    using namespace std::chrono_literals;
	    std::this_thread::sleep_for(2s);

	    std::cout << "Child thread woke up" << std::endl;

	    std::cout << "Dividend = " << dividend << std::endl;
	    std::cout << (divisor / dividend) << std::endl;
	}
    else
    {
        std::cout << "Error: dividend = 0" << std::endl;
    }
}

int main()
{
    int divisor = 15;
    int dividend = 5;

    std::thread thr1(divide, std::ref(divisor), std::ref(dividend));
    thr1.detach();

    std::cout << "Main thread goes sleep" << std::endl;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);

    std::cout << "Main thread woke up" << std::endl;
    dividend = 0;
    std::cout << "Main thread set dividend to 0" << std::endl;

    std::getchar();
    return 0;
}
