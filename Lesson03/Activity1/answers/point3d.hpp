//============================================================================
// Name        : point3d.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 2
//============================================================================
#pragma once
#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <memory>

namespace acpp::gfx {

class Point3d
{
public:
    static constexpr size_t NumberRows{4};

    Point3d();
    Point3d(std::initializer_list<float> list);

    float operator()(const int index) const
    {
        return m_data[index];
    }

    float& operator()(const int index)
    {
        return m_data[index];
    }

    bool operator==(const Point3d& rhs) const;
    bool operator!=(const Point3d& rhs) const
    {
        return !operator==(rhs);
    }


private:
    std::unique_ptr<float[]> m_data;

    friend std::ostream& operator<<(std::ostream& , const Point3d& );
};

inline std::ostream&
operator<<(std::ostream& os, const Point3d& pt)
{
    const char* sep = "[ ";
    for(int i{0} ; i < Point3d::NumberRows ; i++)
    {
        os << sep  << pt.m_data[i];
        sep = ", ";
    }
    os << " ]";
    return os;
}


}
