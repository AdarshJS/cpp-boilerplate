/**
 * @file       test.cpp
 * @author     Adarsh Jagan S
 * @copyright  GNU Public License
 * @brief      Defines test cases for class PIDcontroller's
 *             member functions.
 */

#include <gtest/gtest.h>
#include "PIDcontroller.hpp"

/**
 * @brief Tests if computeError function computes error correctly.
 */

TEST(PIDtest1, checkErrorCalculation) {
  PIDcontroller pid1(0.1, 0.1, 0.1, 2.0, 1.0);
  PIDcontroller pid2(0.1, 0.1, 0.1, 1.0, 1.5);

  // Error = (desiredVel - currentVel)
  ASSERT_DOUBLE_EQ(pid1.computeError(), -1);
  ASSERT_DOUBLE_EQ(pid2.computeError(), 0.5);
}

/**
 * @brief   Tests if computeVelocity function reduces the error almost to zero.
 * The function will return a value close to the desired velocity.
 */

TEST(PIDtest2, checkVelocityCalculation) {
  PIDcontroller pid(0.1, 0.1, 0.1, 1.0, 2.0);
  EXPECT_NEAR(pid.computeVelocity(), 2.0, 0.001);
}
