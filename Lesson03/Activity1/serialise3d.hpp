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

//----------------------------------------------------------------------------
// Serialise Point3d
//----------------------------------------------------------------------------
inline void to_json(nlohmann::json& j, const Point3d& p) {
    j = nlohmann::json{{"point", p.m_data}};
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
    j = nlohmann::json{{"matrix", mat.m_data}};
}

inline void from_json(const nlohmann::json& j, Matrix3d& mat) {
    auto ary = j.at("matrix");
    int i{0};
    for(auto& row : ary)
    {
        int j{0};
        for (auto& cell : row)
        {
            mat.m_data[i][j++] = cell.get<float>();
        }
        ++i;
    }
}
