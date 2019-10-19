//============================================================================
// Name        : matrix3dTests.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 2
//============================================================================
#include "gtest/gtest.h"
#include "../matrix3d.hpp"
#include <cmath>

using namespace acpp::gfx;

class Matrix3dTest : public ::testing::Test
{
public:
    static constexpr float Epsilon{1e-12};
    void VerifyMatrixIsIdentity(Matrix3d& mat);
    void VerifyMatrixResult(Matrix3d& expected, Matrix3d& actual);
};

void Matrix3dTest::VerifyMatrixIsIdentity(Matrix3d& mat)
{
    for( int row{0} ; row<4 ; row++)
        for( int col{0} ; col<4 ; col++)
        {
            int expected = (row==col) ? 1 : 0;
            ASSERT_FLOAT_EQ(expected, mat(row,col)) << "cell[" << row << "][" << col << "]";
        }
}

void Matrix3dTest::VerifyMatrixResult(Matrix3d& expected, Matrix3d& actual)
{
    for( int row{0} ; row<4 ; row++)
        for( int col{0} ; col<4 ; col++)
        {
            ASSERT_NEAR(expected(row,col), actual(row,col), Epsilon) << "cell[" << row << "][" << col << "]";
        }
}



TEST_F(Matrix3dTest, DefaultConstructorIsIdentity)
{
    Matrix3d mat;

    VerifyMatrixIsIdentity(mat);
}

TEST_F(Matrix3dTest, InitListConstructor)
{
    Matrix3d mat{ {1,2,3,4}, {5,6,7,8},{9,10,11,12}, {13,14,15,16}};

    int expected{1};
    for( int row{0} ; row<4 ; row++)
        for( int col{0} ; col<4 ; col++, expected++)
        {
            ASSERT_FLOAT_EQ(expected, mat(row,col)) << "cell[" << row << "][" << col << "]";
        }
}

TEST_F(Matrix3dTest, MultiplyTwoMatricesGiveExpectedResult)
{
    Matrix3d mat1{ {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};
    Matrix3d mat2{ {1,2,3,4}, {5,6,7,8},    {9,10,11,12},  {13,14,15,16}};
    Matrix3d expected{ {202,228,254,280},
                       {314,356,398,440},
                       {426,484,542,600},
                       {538,612,686,760}};


    Matrix3d result = mat1 * mat2;
    VerifyMatrixResult(expected, result);
}

TEST_F(Matrix3dTest, IdentityTimesIdentityIsIdentity)
{
    Matrix3d mat;

    Matrix3d result = mat * mat;
    VerifyMatrixIsIdentity(result);
}

TEST_F(Matrix3dTest, MultiplyMatrixWithPoint)
{
    Matrix3d mat { {1,2,3,4}, {5,6,7,8},    {9,10,11,12},  {13,14,15,16}};
    Point3d pt {15, 25, 35, 45};
    Point3d expected{350, 830, 1310, 1790};

    Point3d pt2 = mat * pt;

    ASSERT_EQ(expected, pt2);
}

TEST_F(Matrix3dTest, CreateTranslateIsCorrect)
{
    Matrix3d mat = createTranslationMatrix(-0.5, 2.5, 10.0);
    Matrix3d expected {{1.0, 0.0, 0.0, -0.5},
                       {0.0, 1.0, 0.0, 2.5},
                       {0.0, 0.0, 1.0, 10.0},
                       {0.0, 0.0, 0.0, 1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateScaleIsCorrect)
{
    Matrix3d mat = createScaleMatrix(3.0, 2.5, 11.0);
    Matrix3d expected {{3.0, 0.0,  0.0, 0.0},
                       {0.0, 2.5,  0.0, 0.0},
                       {0.0, 0.0, 11.0, 0.0},
                       {0.0, 0.0,  0.0, 1.0}
    };
    VerifyMatrixResult(expected, mat);
}


TEST_F(Matrix3dTest, CreateRotateX90IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutX(90.0F);

    Matrix3d expected {{1.0, 0.0,  0.0, 0.0},
                       {0.0, 0.0, -1.0, 0.0},
                       {0.0, 1.0,  0.0, 0.0},
                       {0.0, 0.0,  0.0, 1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateRotateX60IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutX(60.0F);
    float sqrt3_2 = static_cast<float>(std::sqrt(3.0)/2.0);

    Matrix3d expected {{1.0, 0.0,     0.0,     0.0},
                       {0.0, 0.5,    -sqrt3_2, 0.0},
                       {0.0, sqrt3_2,  0.5,    0.0},
                       {0.0, 0.0,     0.0,     1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateRotateY90IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutY(90.0F);

    Matrix3d expected {{0.0, 0.0,  1.0, 0.0},
                       {0.0, 1.0,  0.0, 0.0},
                       {-1.0, 0.0, 0.0, 0.0},
                       {0.0, 0.0,  0.0, 1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateRotateY60IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutY(60.0F);
    float sqrt3_2 = static_cast<float>(std::sqrt(3.0)/2.0);

    Matrix3d expected {{0.5,      0.0,   sqrt3_2,  0.0},
                       {0.0,      1.0,    0.0,     0.0},
                       {-sqrt3_2, 0.0,    0.5,     0.0},
                       {0.0,      0.0,    0.0,     1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateRotateZ90IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutZ(90.0F);

    Matrix3d expected {{0.0, -1.0,  0.0, 0.0},
                       {1.0, 0.0,  0.0, 0.0},
                       {0.0, 0.0,  1.0, 0.0},
                       {0.0, 0.0,  0.0, 1.0}
    };
    VerifyMatrixResult(expected, mat);
}

TEST_F(Matrix3dTest, CreateRotateZ60IsCorrect)
{
    Matrix3d mat = createRotationMatrixAboutZ(60.0F);
    float sqrt3_2 = static_cast<float>(std::sqrt(3.0)/2.0);

    Matrix3d expected {{0.5,     -sqrt3_2,   0.0,  0.0},
                       {sqrt3_2,      0.5,   0.0,  0.0},
                       {0.0,          0.0,   1.0,  0.0},
                       {0.0,          0.0,   0.0,  1.0}
    };
    VerifyMatrixResult(expected, mat);
}



