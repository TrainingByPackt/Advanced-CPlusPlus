//============================================================================
// Name        : point3d.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#pragma once
#include <memory>
#include <initializer_list>
#include "nlohmann/json_fwd.hpp"

namespace acpp::gfx {

class Point3d
{
public:
    static constexpr size_t NumberRows{4};

    Point3d();
    Point3d(std::initializer_list<float> list);
    Point3d(const Point3d&);
    Point3d& operator=(const Point3d&);

    bool operator==(const Point3d& rhs) const;
    bool operator!=(const Point3d& rhs) const
    {
        return !operator==(rhs);
    }

    float operator()(const int index) const
    {
        check_index(index);
        return m_data[index];
    }

    float& operator()(const int index)
    {
        check_index(index);
        return m_data[index];
    }


private:
    void check_index(size_t index) const;
    std::unique_ptr<float[]> m_data;

    friend void to_json(nlohmann::json& j, const Point3d& p);
    friend void from_json(const nlohmann::json& j, Point3d& p);
};


}
