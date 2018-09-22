/*
 * @file       main.cpp
 * @author     Adarsh Jagan S
 * @copyright  2018 Adarsh Jagan S
 * @brief      Creates an object of the class PIDcontroller with initial values
 *             for constants, actual and desired velocity
 */

#include"PIDcontroller.hpp"
#include<iostream>

int main() {
  PIDcontroller pid(0.1, 0.1, 0.1, 5.0, 10.0);
}



