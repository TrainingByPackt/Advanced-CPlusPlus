//============================================================================
// Name        : Exercise3.cpp
// Author      : Brian Price
// Version     :
// Description : Exercise 3 Lesson 4
//============================================================================
#include <iostream>
#include <functional>

using MyFunction = std::function<void(int)>;

void TestFunctionTemplate()
{
    std::cout << "+++ Entering TestFunctionTemplate()\n";
    MyFunction func;
    try
    {
        func(42);
    }
    catch(std::bad_function_call& e)
    {
        std::cout << "exception: " << e.what() << "\n";
    }
    std::cout << "+++ Leaving TestFunctionTemplate()\n";
}


int main(int argc, char**argv)
{
    std::cout << "\n------ Exercise 3 ------\n";
    TestFunctionTemplate();
    std::cout << "Complete.\n";
    return 0;
}

