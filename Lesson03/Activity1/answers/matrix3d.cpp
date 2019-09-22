//============================================================================
// Name        : matrix3d.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 2
//============================================================================
#include "matrix3d.hpp"
#include <cmath>
#include <utility>
#include <iostream>

namespace acpp::gfx {

Matrix3d::Matrix3d() : m_data{new float[NumberRows*NumberColumns]}
{
    for (int i{0} ; i< NumberRows ; i++)
        for (int j{0} ; j< NumberColumns ; j++)
            m_data[get_index(i,j)] = (i==j);
}

Matrix3d::Matrix3d(const Matrix3d& rhs) : m_data{new float[NumberRows*NumberColumns]}
{
    *this = rhs;
}

Matrix3d::Matrix3d(Matrix3d&& rhs)
{
    //std::cerr << "Matrix3d::Matrix3d(Matrix3d&& rhs)\n";
    std::swap(m_data, rhs.m_data);
}

Matrix3d& Matrix3d::operator=(const Matrix3d& rhs)
{
    for (int i{0} ; i< NumberRows*NumberColumns ; i++)
        m_data[i] = rhs.m_data[i];
    return *this;
}


Matrix3d::Matrix3d(std::initializer_list<std::initializer_list<float>> list)
    : m_data{new float[NumberRows*NumberColumns]}
{
    int i{0};
    for(auto it1 = list.begin(); i<NumberRows ; ++it1, ++i)
    {
        int j{0};
        for(auto it2 = it1->begin(); j<NumberColumns ; ++it2, ++j)
            m_data[get_index(i,j)] = *it2;
    }
}

Matrix3d& Matrix3d::operator*=(const Matrix3d& rhs)
{
    Matrix3d temp;

    for(int i=0 ; i<NumberRows ; i++)
        for(int j=0 ; j<NumberColumns ; j++)
        {
            temp.m_data[get_index(i,j)] = 0;
            for (int k=0 ; k<NumberRows ; k++)
                temp.m_data[get_index(i,j)] += m_data[get_index(i,k)] * rhs.m_data[get_index(k,j)];
        }

    *this = temp;
    return *this;
}

Point3d operator*(const Matrix3d& lhs, const Point3d& rhs)
{
    Point3d pt;
    for(int row{0} ; row<Matrix3d::NumberRows ; row++)
    {
        float sum{0};
        for(int col{0} ; col<Matrix3d::NumberColumns ; col++)
        {
            sum += lhs(row, col) * rhs(col);
        }
        pt(row) = sum;
    }
    return pt;
}

Matrix3d createTranslationMatrix(float dx, float dy, float dz)
{
    Matrix3d matrix;
    matrix(0, 3) = dx;
    matrix(1, 3) = dy;
    matrix(2, 3) = dz;
    return std::move(matrix);
}

Matrix3d createScaleMatrix(float sx, float sy, float sz)
{
    Matrix3d matrix;
    matrix(0, 0) = sx;
    matrix(1, 1) = sy;
    matrix(2, 2) = sz;
    return matrix;

}

Matrix3d createRotationMatrixAboutX(float degrees)
{
    Matrix3d matrix;
    double pi{4.0F*atan(1.0F)};
    double radians = degrees / 180.0 * pi;

    float cos_theta = static_cast<float>(cos(radians));
    float sin_theta = static_cast<float>(sin(radians));

    matrix(1, 1) =  cos_theta;
    matrix(2, 2) =  cos_theta;
    matrix(1, 2) = -sin_theta;
    matrix(2, 1) =  sin_theta;

    return matrix;
}

Matrix3d createRotationMatrixAboutY(float degrees)
{
    Matrix3d matrix;
    double pi{4.0F*atan(1.0F)};
    double radians = degrees / 180.0 * pi;

    float cos_theta = static_cast<float>(cos(radians));
    float sin_theta = static_cast<float>(sin(radians));

    matrix(0, 0) =  cos_theta;
    matrix(2, 2) =  cos_theta;
    matrix(0, 2) =  sin_theta;
    matrix(2, 0) = -sin_theta;

    return matrix;
}

Matrix3d createRotationMatrixAboutZ(float degrees)
{
    Matrix3d matrix;
    double pi{4.0F*atan(1.0F)};
    double radians = degrees / 180.0 * pi;

    float cos_theta = static_cast<float>(cos(radians));
    float sin_theta = static_cast<float>(sin(radians));

    matrix(0, 0) =  cos_theta;
    matrix(1, 1) =  cos_theta;
    matrix(0, 1) = -sin_theta;
    matrix(1, 0) =  sin_theta;

    return matrix;
}


}
