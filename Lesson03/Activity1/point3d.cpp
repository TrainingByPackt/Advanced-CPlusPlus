///============================================================================
// Name        : point3d.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "point3d.hpp"
#include <exception>

Point3d::Point3d()
{
    for(auto& item : m_data)
    {
        item = 0;
    }
    m_data[NumberRows-1] = 1;
}

Point3d::Point3d(std::initializer_list<float> list)
{
    if ((list.size() != (NumberRows-1)) && (list.size() != NumberRows))
        throw std::invalid_argument("Wrong number ordinates in initialiser");

    m_data[NumberRows-1] = 1;
    int i{0};
    for(auto it1 = list.begin(); i<NumberRows && it1 != list.end() ; ++it1, ++i)
    {
        m_data[i] = *it1;
    }
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



