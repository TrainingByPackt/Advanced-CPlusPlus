//============================================================================
// Name        : date.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 2 Lesson 3
//============================================================================
#pragma once
#include <cstdint>

namespace acpp::date
{

using date_t=int64_t;

class Days
{
public:
    Days() = default;
    explicit Days(int days) : m_days{days}
    {
    }

    operator int() const
    {
        return m_days;
    }

private:

    int m_days{0};
};

class Date
{
public:
    static constexpr int EpochYear = 1970;
    static constexpr int DaysPerCommonYear = 365;
    static constexpr int YearsBetweenLeapYears = 4;


    Date() = default;
    Date(const Date&) = default;
    Date& operator=(const Date&) = default;

    Date(int day, int month, int year) :
            m_year{year}, m_month{month}, m_day{day}
    {
    }

    int Day()   const {return m_day;}
    int Month() const {return m_month;}
    int Year()  const {return m_year;}


    date_t ToDateT() const;
    void FromDateT(date_t date);

    Date& operator+=(const Days& day);
    Days operator-(const Date& rhs) const;

private:
    int GetDayOfYear(int day, int month, int year) const;
    bool IsLeapYear(int year) const;
    int CalcMonthDayOfYearIsIn(int dayOfYear, bool IsLeapYear) const;
    int CalcNumberLeapYearsFromEpoch(int year) const;

    int m_day{1};
    int m_month{1};
    int m_year {EpochYear};
};

inline Date operator+(const Date& lhs, const Days& rhs )
{
    Date tmp(lhs);
    tmp += rhs;
    return tmp;
}

inline Days Date::operator-(const Date& rhs) const
{
    return Days(ToDateT() - rhs.ToDateT());
}
}
