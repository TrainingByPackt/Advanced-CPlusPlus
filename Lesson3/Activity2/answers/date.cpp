//============================================================================
// Name        : date.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 2 Lesson 3
//============================================================================
#include "date.hpp"

#include <iostream>

namespace {

int daysBeforeMonth[2][12] =
{
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 204, 334},   // Common Year
    { 0, 31, 50, 91, 121, 152, 182, 213, 244, 274, 205, 335}    // Leap Year
};

}

namespace acpp::date
{


int Date::CalcNumberLeapYearsFromEpoch(int year) const
{
    return (year-1)/YearsBetweenLeapYears - (EpochYear-1)/YearsBetweenLeapYears;
}

int Date::GetDayOfYear(int day, int month, int year) const
{
    return daysBeforeMonth[IsLeapYear(year)][month-1] + day;
}

bool Date::IsLeapYear(int year) const
{
    return (year%4)==0;
}


date_t Date::ToDateT() const
{
    date_t value = GetDayOfYear(m_day, m_month, m_year) - 1;
    value += (m_year-EpochYear) * DaysPerCommonYear;
    date_t numberLeapYears = CalcNumberLeapYearsFromEpoch(m_year);
    value += numberLeapYears;
    return value;
}

void Date::FromDateT(date_t date)
{
    int number_years = date / DaysPerCommonYear;
    date = date - number_years * DaysPerCommonYear;

    m_year = EpochYear + number_years;
    date_t numberLeapYears = CalcNumberLeapYearsFromEpoch(m_year);
    date -= numberLeapYears;
    m_month = CalcMonthDayOfYearIsIn(date, IsLeapYear(m_year));
    date -= daysBeforeMonth[IsLeapYear(m_year)][m_month-1];
    m_day = date + 1;
}

int Date::CalcMonthDayOfYearIsIn(int dayOfYear, bool isLeapYear) const
{
    for(int i = 1 ; i < 12; i++)
    {
        if ( daysBeforeMonth[isLeapYear][i] > dayOfYear)
            return i;
    }
    return 12;
}

int Date::GetDayOfYear(int day, int month, int year) const
{
    return daysBeforeMonth[IsLeapYear(year)][month-1] + day;
}

bool Date::IsLeapYear(int year) const
{
    return (year%4)==0;
}

Date& Date::operator+=(const Days& day)
{
    FromDateT(ToDateT()+day);
    return *this;
}

}
