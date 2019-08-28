//============================================================================
// Name        : matrix3dtest.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "gtest/gtest.h"
#include "../matrix3d.hpp"
#include <sstream>
#include <cmath>

using namespace acpp::gfx;

class Matrix3dTest : public ::testing::Test
{
public:
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
            ASSERT_NEAR(expected(row,col), actual(row,col), 1e-12) << "cell[" << row << "][" << col << "]";
        }
}

TEST_F(Matrix3dTest, DefaultConstructorIsIdentity)
{
    Matrix3d mat;

    VerifyMatrixIsIdentity(mat);

    for( int row{0} ; row<4 ; row++)
        for( int col{0} ; col<4 ; col++)
        {
            float expected = (row==col) ? 1 : 0;
            ASSERT_FLOAT_EQ(expected, mat(row,col)) << "cell[" << row << "][" << col << "]";
        }
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

TEST_F(Matrix3dTest, IdentityTimesIdentityIsIdentity)
{
    Matrix3d mat;

    Matrix3d result = mat * mat;
    VerifyMatrixIsIdentity(result);
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

TEST_F(Matrix3dTest, MultiplyIdentityWithPoint)
{
    Point3d pt2;
    Matrix3d mat;
    Point3d pt{1.0,1.0,1.0};

    pt2 = mat * pt;

    ASSERT_EQ(pt, pt2);
}

TEST_F(Matrix3dTest, MultiplyRotatePlus90WithRotateMinus90GivesIdentity)
{
    Matrix3d mat1 = createRotationMatrixAboutX(90.0F);
    Matrix3d mat2 = createRotationMatrixAboutX(-90.0F);

    Matrix3d expected {{1.0, 0.0,  0.0, 0.0},
                       {0.0, 0.0, -1.0, 0.0},
                       {0.0, 1.0,  0.0, 0.0},
                       {0.0, 0.0,  0.0, 1.0}
    };
    auto result = mat1 * mat2;
    VerifyMatrixIsIdentity(result);
}

TEST_F(Matrix3dTest, MultiplyRotatePlus90WithRotatePlus90GivesNegativeYZ)
{
    Matrix3d mat1 = createRotationMatrixAboutX(90.0F);

    Matrix3d expected {{1.0,  0.0,  0.0, 0.0},
                       {0.0, -1.0,  0.0, 0.0},
                       {0.0,  0.0, -1.0, 0.0},
                       {0.0,  0.0,  0.0, 1.0}
    };
    auto result = mat1 * mat1;
    VerifyMatrixResult(expected, result);
}


TEST_F(Matrix3dTest, MultiplyLots)
{
    Matrix3d matx = createRotationMatrixAboutX(60.0F);
    Matrix3d maty = createRotationMatrixAboutY(60.0F);
    Matrix3d matz = createRotationMatrixAboutZ(60.0F);

    Point3d pt2;
    Point3d pt{0.0,0.0,0.0};

    pt2 = matx * maty * matz * pt;

    ASSERT_EQ(pt, pt2);
}
