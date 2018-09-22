/**
 * @file      main.cpp
 * @author    Adarsh Jagan S
 * @copyright
 * @brief     Main function for running gtest.
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
