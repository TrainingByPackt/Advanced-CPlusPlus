//============================================================================
// Name        : matrix3d.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#pragma once
#include "point3d.hpp"

class Matrix3d
{
public:
    static constexpr size_t NumberRows{4};
    static constexpr size_t NumberColumns{4};

    Matrix3d();
    Matrix3d(std::initializer_list<std::initializer_list<float>> list);

    Matrix3d& operator*=(const Matrix3d& rhs);

    bool operator==(const Matrix3d& rhs) const;

    float get_cell(int row, int col) const;
    void  set_cell(int row, int col, float value);

    float operator()(const int row, const int column) const
    {
        return m_data[row][column];
    }
    float& operator()(const int row, const int column)
    {
        return m_data[row][column];
    }


private:
    void check_ranges(int row, int col) const;

    float m_data[NumberRows][NumberColumns];

    friend void to_json(nlohmann::json& j, const Matrix3d& mat);
    friend void from_json(const nlohmann::json& j, Matrix3d& mat);
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
