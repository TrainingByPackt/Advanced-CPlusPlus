//============================================================================
// Name        : Exercise3.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 3 Lesson 3
//============================================================================
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

template<typename T> std::string stringify(const T& x)
{
    std::ostringstream out;
    out << x;
    return out.str();
}

template<> std::string stringify<bool>(const bool& x)
{
    std::ostringstream out;
    out << std::boolalpha << x;
    return out.str();
}

template<> std::string stringify<double>(const double& x)
{
    const int sigdigits = std::numeric_limits<double>::digits10;
    std::ostringstream out;
    out << std::setprecision(sigdigits) << x;
    return out.str();
}

template<> std::string stringify<float>(const float& x)
{
    const int sigdigits = std::numeric_limits<float>::digits10;
    std::ostringstream out;
    out << std::setprecision(sigdigits) << x;
    return out.str();
}

template<> std::string stringify<long double>(const long double& x)
{
    const int sigdigits = std::numeric_limits<long double>::digits10;
    std::ostringstream out;
    out << std::setprecision(sigdigits) << x;
    return out.str();
}


int main(int argc, char**argv)
{
    std::cout << "\n\n------ Exercise 3 ------\n";

    std::cout << "stringify(true)         --> " << stringify(true) << "\n";
    std::cout << "stringify(32)           --> " << stringify(32) << "\n";
    std::cout << "stringify(143.2109876F) --> " << stringify(143.2109876F) << "\n";
    std::cout << "stringify(1234.56789)   --> " << stringify(1234.56789) << "\n";

    std::cout << "Complete.\n";
    return 0;
}
