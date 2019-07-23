//============================================================================
// Name        : chapter5.cpp
// Author      : Olena Lizina
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 1 Chapter 5
//============================================================================

#include <iostream>
#include <thread>
#include <functional>

void printNumbers()
{
    for(int i = 0; i < 100; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

class Printer
{
    public:
    void operator()()
    {
        for(int i = 0; i < 1000; ++i)
        {
            if (!(i % 200))
            {
                std::cout << std::endl;
            }
            std::cout << "*";
        }
    }
};

int main()
{
    auto printRevers = []()
    {
        for(int i = 100; i >= 0; --i)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    };

    std::function<void()> printOther = []()
    {
        for(int i = 0; i < 1000; ++i)
        {
            if (!(i % 200))
            {
                std::cout << std::endl;
            }
            std::cout << "^";
        }
    };

    std::thread thr1(printNumbers);
    thr1.join();

    std::thread thr2(printRevers);
    thr2.join();

    Printer print;
    std::thread thr3(print);
    thr3.detach();

    std::thread thr4(printOther);
    thr4.detach();

    std::getchar();
    return 0;
}
