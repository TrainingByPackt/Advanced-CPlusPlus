//============================================================================
// Name        : main.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include <iostream>
#include <sstream>
#include "point3d.hpp"
#include "matrix3d.hpp"
#include "serialise3d.hpp"
#include <vector>

using Point3dVec = std::vector<Point3d>;

int main()
{
    Point3d pt{{1,4,5,0}};
    Matrix3d mat;

    Point3dVec points;
    points.push_back({1.0F,2.0F,3.0F,1.0F});
    points.push_back({2.0F,2.0F,3.0F,1.0F});
    points.push_back({3.0F,2.0F,3.0F,1.0F});
    points.push_back({4.0F,2.0F,3.0F,1.0F});


    nlohmann::json j = pt;

    std::cout << j << std::endl;



    std::stringstream buffer;

    buffer << j;
    nlohmann::json j2;
    buffer >> j2;
    auto p2 = j2.get<Point3d>();

    if (pt == p2)
        std::cout << "Points are the same\n";
    else
        std::cout << "Points are NOT the same\n";

    j = mat;
    std::cout << j << std::endl;
    std::stringstream buffer2;
    buffer2 << j;
    nlohmann::json j3;
    buffer2 >> j3;
    auto m2 = j3.get<Matrix3d>();
    if (mat == m2)
        std::cout << "Matrices are the same\n";
    else
        std::cout << "Matrices are NOT the same\n";

    try
    {
        std::cout << "Doing vector of points\n";
        nlohmann::json j4 = points;
    std::cout << "vector of points " << j4 << "\n";
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    return 0;
}




