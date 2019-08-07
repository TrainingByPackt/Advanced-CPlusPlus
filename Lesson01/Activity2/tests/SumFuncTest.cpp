/*
 * SumFuncTest.cpp
 *
 *  Created on: Aug 1, 2019
 *      Author: gazihan
 */
#include "gtest/gtest.h"
#include "../src/SumFunc.h"

namespace {

  class SumFuncTest: public ::testing::Test {};

  TEST_F(SumFuncTest, CanSumCorrectly) {
    EXPECT_EQ(7, sum(3, 4));
  }

  TEST_F(SumFuncTest, CanUseNegativeValues) {
    EXPECT_EQ(0, sum(3, -3));
  }

}




