//============================================================================
// Name        : matrix3d.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 2
//============================================================================
#pragma once
#include <cstddef>
#include <initializer_list>
#include <memory>
#include "point3d.hpp"

namespace acpp::gfx {


class Matrix3d
{
public:
    static constexpr size_t NumberRows{4};
    static constexpr size_t NumberColumns{4};

    Matrix3d();
    Matrix3d(std::initializer_list<std::initializer_list<float>> list);

    Matrix3d(const Matrix3d& rhs);
    Matrix3d& operator=(const Matrix3d& rhs);
    Matrix3d(Matrix3d&& rhs);

    Matrix3d& operator*=(const Matrix3d& rhs);

    float operator()(const int row, const int column) const
    {
        return m_data[get_index(row,column)];
    }

    float& operator()(const int row, const int column)
    {
        return m_data[get_index(row,column)];
    }


private:
    size_t get_index(const int row, const int column) const
    {
        return row * NumberColumns + column;
    }
    std::unique_ptr<float[]> m_data;
};

inline Matrix3d operator*(const Matrix3d& lhs, const Matrix3d& rhs)
{
    Matrix3d temp(lhs);
    temp *= rhs;
    return temp;
}

Point3d operator*(const Matrix3d& lhs, const Point3d& rhs);

Matrix3d createTranslationMatrix(float dx, float dy, float dz);
Matrix3d createScaleMatrix(float sx, float sy, float sz);
Matrix3d createRotationMatrixAboutX(float degrees);
Matrix3d createRotationMatrixAboutY(float degrees);
Matrix3d createRotationMatrixAboutZ(float degrees);


}
