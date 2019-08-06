/*
 * LinearMotion1DTest.cpp
 *
 *  Created on: Aug 1, 2019
 *      Author: gazihan
 */

#include "gtest/gtest.h"
#include "../src/LinearMotion1D.h"

namespace {

class LinearMotion1DTest: public ::testing::Test {
};

TEST_F(LinearMotion1DTest, CanMoveRight) {
	LinearMotion1D l;
	l.position = 10;
	l.velocity = 2;
	l.advanceTimeBy(3);
	EXPECT_DOUBLE_EQ(16, l.position);
}

TEST_F(LinearMotion1DTest, CanMoveLeft) {
	LinearMotion1D l;
	l.position = 10;
	l.velocity = -2;
	l.advanceTimeBy(3);
	EXPECT_DOUBLE_EQ(4, l.position);
}

}

