//============================================================================
// Name        : main.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 2
//============================================================================
#include <iostream>

// #define ACTIVITY1

#if defined(ACTIVITY1)
#include "point3d.hpp"
#include "matrix3d.hpp"
#endif

int main()
{
    std::cout << "\n------ Activity 1 ------\n";
#if defined(ACTIVITY1)
    Point3d thePoint{1,1,1};

    std::cout << "The point " << thePoint << "\n";
    std::cout << "...rotated around X by 90 degrees\n";
    auto rotX = createRotationMatrixAboutX(90.0F);
    thePoint = rotX * thePoint;

    std::cout << "...rotated around Y by 90 degrees\n";
    auto rotY = createRotationMatrixAboutY(90.0F);
    thePoint = rotY * thePoint;

    std::cout << "...rotated around Z by 90 degrees\n";
    auto rotZ = createRotationMatrixAboutZ(90.0F);
    thePoint = rotZ * thePoint;

    std::cout << "moves to " << thePoint << "\n";

    std::cout << "...scaled by x=2, y = 3, z = 4\n";
    auto scale = createScaleMatrix(2, 3, 4);
    thePoint = scale * thePoint;

    std::cout << "moves to " << thePoint << "\n";

    std::cout << "...translated by dx=-2, dy = 1, dz = -3\n";
    auto translate = createTranslationMatrix(-2, 1, -3);
    thePoint = translate * thePoint;

    std::cout << "moves to " << thePoint << "\n";
#else
    std::cout << "\nWait until the implementation of Point3d and Matrix3d are complete.\n";
    std::cout << "\nThen remove comment from #define ACTIVITY1 and re-run\n";
#endif
    std::cout << "\nComplete.\n";
    return 0;
}




