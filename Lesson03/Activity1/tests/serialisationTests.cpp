//============================================================================
// Name        : serialisationTests.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#include "gtest/gtest.h"
#include <sstream>
#include <string>
#include "../serialise3d.hpp"


class SerialisationTest : public ::testing::Test
{
public:

};

TEST_F(SerialisationTest, StreamPoint3dToJson)
{
    // Note for this test to be easy to write the fractional part
    // of the value must be easy to create from sum of 2^-n values.
    Point3d pt {5.25, 3.5, 6.75, 2.0};
    std::stringstream buffer;
    nlohmann::json json_object;
    const char* expected = "{\"point\":[5.25,3.5,6.75,2.0]}";

    json_object = pt;
    buffer << json_object;
    std::string actual = buffer.str();
    ASSERT_STREQ(expected, actual.c_str());
}

TEST_F(SerialisationTest, StreamPoint3dFromJson)
{
    // Note for this test to be easy to write the fractional part
    // of the value must be easy to create from sum of 2^-n values.
    Point3d expected {5.25,3.5,6.75,2.0};

    std::stringstream buffer;
    nlohmann::json json_object;
    const char* stream = "{\"point\":[5.25,3.5,6.75,2.0]}";

    buffer << stream;
    buffer >> json_object;
    auto pt = json_object.get<Point3d>();
    ASSERT_EQ(expected, pt);
}

TEST_F(SerialisationTest, StreamMatrix3dToJson)
{
    // Note for this test to be easy to write the fractional part
    // of the value must be easy to create from sum of 2^-n values.
    Matrix3d matrix {{1.0, 0.0,  0.0, 0.0},
                     {0.0, 0.0, -1.0, 0.0},
                     {0.0, 1.0,  0.0, 0.0},
                     {0.0, 0.0,  0.0, 1.0}
                    };

    std::stringstream buffer;
    nlohmann::json json_object;
    const char* expected = "{\"matrix\":[[1.0,0.0,0.0,0.0],[0.0,0.0,-1.0,0.0],[0.0,1.0,0.0,0.0],[0.0,0.0,0.0,1.0]]}";

    json_object = matrix;
    buffer << json_object;
    std::string actual = buffer.str();
    ASSERT_STREQ(expected, actual.c_str());
}

TEST_F(SerialisationTest, StreamMatrix3dFromJson)
{
    // Note for this test to be easy to write the fractional part
    // of the value must be easy to create from sum of 2^-n values.
    Matrix3d expected {{5.0, 0.0,  0.0, 0.0},
                       {0.0, 60.0, 1.0, 0.0},
                       {0.0, 1.0,  30.0, 0.0},
                       {0.0, 0.0,  0.0, 10.0}
    };

    std::stringstream buffer;
    nlohmann::json json_object;
    const char* stream = "{\"matrix\":[[5.0,0.0,0.0,0.0],[0.0,60.0,1.0,0.0],[0.0,1.0,30.0,0.0],[0.0,0.0,0.0,10.0]]}";

    buffer << stream;
    buffer >> json_object;
    auto matrix = json_object.get<Matrix3d>();
    ASSERT_EQ(expected, matrix);
}

