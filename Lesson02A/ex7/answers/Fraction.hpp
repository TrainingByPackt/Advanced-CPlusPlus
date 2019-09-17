//============================================================================
// Name        : Fractions.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 7 Lesson 2
//============================================================================
#include <iostream>

#define EXERCISE7_STEP    1

class Fraction
{
public:
    Fraction(int numerator=0, int denominator=1);

    int getNumerator() const
    {
        return m_numerator;
    }

    int getDenominator() const
    {
        return m_denominator;
    }

    Fraction& operator*=(const Fraction& rhs);
    Fraction& operator+=(const Fraction& rhs);
    Fraction& operator-=(const Fraction& rhs);
    Fraction& operator/=(const Fraction& rhs);

private:
    int m_numerator{0};
    int m_denominator{1};
};

inline Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    Fraction tmp(lhs);
    tmp *= rhs;
    return tmp;
}

inline Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction tmp(lhs);
    tmp += rhs;
    return tmp;
}

inline Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    Fraction tmp(lhs);
    tmp -= rhs;
    return tmp;
}

inline Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    Fraction tmp(lhs);
    tmp /= rhs;
    return tmp;
}

inline std::ostream& operator<< (std::ostream &out, const Fraction &rhs)
{
    out << rhs.getNumerator() << " / " << rhs.getDenominator();
    return out;
}
