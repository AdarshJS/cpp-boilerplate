/*
 * @file      PIDcontroller.hpp
 * @author    Adarsh Jagan S
 * @copyright 2018 Adarsh Jagan S
 * @brief     PIDcontroller class is defined here.
 */

#ifndef INCLUDE_PIDCONTROLLER_HPP_
#define INCLUDE_PIDCONTROLLER_HPP_

#include<iostream>

/**
 * @brief Class PIDcontroller
 * Class PIDcontroller implements the data members and
 * member functions to calculate velocity that minimizes the error
 * with respect to a desired velocity using PID controller.
 */

class PIDcontroller {
 private:
  // Proportional gain
  double kP;
  // Integral gain
  double kI;
  // Derivative gain
  double kD;
  // Actual current velocity
  double currentVelocity;
  // Desired velocity (where PID should take us)
  double desiredVelocity;
  // Difference between desired velocity and actual velocity.
  double currentError;
  // Summation of all previous (errors * delta time)
  double previousErrorSum = 0;
  // Error at previous instant of time
  double previousError = 0;
  // Time increment in sec
  float dTime = 0.05;
  // Threshold below which PID has to take error
  double errorThreshold = 0.001;

 public:
  // Constructor sets constants and current and desired velocities
  PIDcontroller(double kP, double kI, double kD, double currentVelocity,
                double desiredVelocity);
  // Member function to calculate error
  double computeError();
  /* Member function to calculate new velocity
   * converging to desired velocity
   */
  double computeVelocity();
  // Class Destructor
  ~PIDcontroller();

};


#endif /* INCLUDE_PIDCONTROLLER_HPP_ */
