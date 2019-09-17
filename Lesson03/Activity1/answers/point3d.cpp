///============================================================================
// Name        : point3d.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "point3d.hpp"
#include <exception>

namespace acpp::gfx {


Point3d::Point3d() : m_data{new float[NumberRows]}
{
    for(int i{0} ; i < NumberRows-1 ; i++) {
        m_data[i] = 0;
    }
    m_data[NumberRows-1] = 1;
}

Point3d::Point3d(std::initializer_list<float> list) : m_data{new float[NumberRows]}
{
    if ((list.size() != (NumberRows-1)) && (list.size() != NumberRows))
        throw std::invalid_argument("Wrong number ordinates in initialiser");

    m_data[NumberRows-1] = 1;
    int i{0};
    for(auto it1 = list.begin(); i<4 && it1 != list.end() ; ++it1, ++i)
    {
        m_data[i] = *it1;
    }
}

Point3d::Point3d(const Point3d& lhs) : m_data{new float[NumberRows]}
{
    *this = lhs;
}

Point3d& Point3d::operator=(const Point3d& lhs)
{
    for(int i=0 ; i<NumberRows; i++)
        m_data[i] = lhs.m_data[i];
    return *this;
}

bool Point3d::operator==(const Point3d& rhs) const
{
    for(int i=0 ; i<NumberRows ; i++)
    {
        if (m_data[i] != rhs.m_data[i])
        {
            return false;
        }
    }
    return true;
}

void Point3d::check_index(size_t index) const
{
    if ( index >= NumberRows)
        throw std::out_of_range("index out of range");
}


}
