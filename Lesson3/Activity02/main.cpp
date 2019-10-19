//============================================================================
// Name        : main.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 2 Lesson 3
//============================================================================
#include "date.hpp"
#include <iostream>


//#define ACTIVITY2

#ifdef ACTIVITY2
using namespace acpp::date;

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    static const char*months[] = {"???", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    os << date.Day() << '-' << months[date.Month()] << '-' << date.Year();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Days& days)
{
    os << static_cast<int>(days);
    return os;
}

void PrintDaysBetween(const Date& date1, const Date& date2)
{
    constexpr double DaysPerYear = 365.2422;
    auto diff = date2 - date1;
    std::cout << "There are " << diff << " days between " << date1 << " and " << date2 << "\n";
    std::cout << "There are " << (diff/DaysPerYear) << " years between " << date1 << " and " << date2 << "\n\n";
}

#endif

int main()
{
    std::cout << "\n------ Activity 2 ------\n";
#ifdef ACTIVITY2
    Date date1{1,1,2019};       // First day of 2019
    Date date2{25,12,2019};     // Christmas Day 2019
    Date date3{31,12,2019};     // Christmas Day 2019
    Date date4{1,1,1970};       // Beginning of Date Epoch
    Date date5{1,1,2070};       // 100 years after Date Epoch

    PrintDaysBetween(date1, date2);
    PrintDaysBetween(date1, date3);
    PrintDaysBetween(date4, date2);
    PrintDaysBetween(date4, date5);
#else
    std::cout << "\nWait until the implementation of Date is complete.\n";
    std::cout << "Then remove comment from #define ACTIVITY2 and re-run\n\n";
#endif
    std::cout << "Complete.\n";
    return 0;
}


