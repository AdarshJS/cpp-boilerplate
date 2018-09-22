#include <gtest/gtest.h>
#include "PIDcontroller.hpp"

TEST(PIDtest1, checkErrorCalculation) {
  PIDcontroller pid1(0.1, 0.1, 0.1, 2.0, 1.0);
  PIDcontroller pid2(0.1, 0.1, 0.1, 1.0, 1.5);
  ASSERT_DOUBLE_EQ(pid1.computeError(), -1);  //Error = (desiredVel - currentVel)
  ASSERT_DOUBLE_EQ(pid2.computeError(), 0.5);
}

TEST(PIDtest2, checkVelocityCalculation) {
  PIDcontroller pid(0.1, 0.1, 0.1, 1.0, 2.0);
  EXPECT_NEAR(pid.computeVelocity(), 2.0, 0.001);
}
