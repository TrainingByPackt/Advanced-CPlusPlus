//============================================================================
// Name        : Fraction.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 7 Lesson 2
//============================================================================
#include "Fraction.hpp"
#include <cmath>
#include <numeric>

namespace {
inline int signum(int val) {
    return (0 < val) - (val < 0);
}

}

Fraction::Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator}
{
    int sign{(signum(m_numerator)*signum(m_denominator))};
    m_numerator = std::abs(m_numerator);
    m_denominator = std::abs(m_denominator);

    int divisor{std::gcd(m_numerator, m_denominator)};
    m_numerator = sign * m_numerator / divisor;
    m_denominator = m_denominator / divisor;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
    Fraction tmp(m_numerator*rhs.m_numerator, m_denominator*rhs.m_denominator);
    *this = tmp;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
    return *this;
}
