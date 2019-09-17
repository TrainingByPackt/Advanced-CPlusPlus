//============================================================================
// Name        : serialise3d.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#pragma once

#include "point3d.hpp"
#include "matrix3d.hpp"
#include "nlohmann/json.hpp"

namespace acpp::gfx {


//----------------------------------------------------------------------------
// Serialise Point3d
//----------------------------------------------------------------------------
inline void to_json(nlohmann::json& j, const Point3d& p) {
    //nlohmann::json tmp;
    nlohmann::json array = nlohmann::json::array();
    for(int row{0} ; row < Point3d::NumberRows ; row++)
    {
        array.push_back(p.m_data[row]);
    }
    j["point"] = array;
}

inline void from_json(const nlohmann::json& j, Point3d& p) {
    auto row = j.at("point");
    int i{0};
    for(auto& cell : row)
    {
        p.m_data[i++] = cell.get<float>();
    }
}

//----------------------------------------------------------------------------
// Serialise Matrix3d
//----------------------------------------------------------------------------
inline void to_json(nlohmann::json& j, const Matrix3d& mat) {
    //nlohmann::json tmp;
    nlohmann::json matrix = nlohmann::json::array();
    for(int row{0} ; row < Matrix3d::NumberRows ; row++)
    {
        nlohmann::json array = nlohmann::json::array();
        for(int col{0} ; col < Matrix3d::NumberColumns ; col++)
        {
            array.push_back(mat(row,col));
        }
        matrix.push_back(array);
    }
    j["matrix"] = matrix;
}

inline void from_json(const nlohmann::json& j, Matrix3d& mat) {
    auto ary = j.at("matrix");
    int i{0};
    for(auto& row : ary)
    {
        int j{0};
        for (auto& cell : row)
        {
            mat.m_data[mat.get_index(i,j)] = cell.get<float>();
            ++j;
        }
        ++i;
    }
}

}
