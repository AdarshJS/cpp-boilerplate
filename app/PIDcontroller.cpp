/*
 * @file       PIDcontroller.cpp
 * @author     Adarsh Jagan S
 * @copyright  2018 Adarsh Jagan S
 * @brief      Definitions for class PIDcontroller.
 */
#include "PIDcontroller.hpp"
#include <math.h>
#include<iostream>
// Add extra headers as needed.


/**
 * @brief               Constructor for PIDcontroller class
 * @param gainP         Proportional gain of type double
 * @param gainI         Integral gain of type double
 * @param gainD         Derivative gain of type double
 * @param currVelocity  Current velocity of type double
 * @param desVelocity   Desired velocity of type double
 *
 * Constructor initializes the values of kP,
 * kI, kD, actual velocity and desired velocity.
 * current error is initialized to zero.
 */

PIDcontroller::PIDcontroller(double gainP, double gainI, double gainD,
  double currVelocity, double desVelocity) {
  currentError = 0.0;
  kP = gainP;
  kI = gainI;
  kD = gainD;
  currentVelocity = currVelocity;
  desiredVelocity = desVelocity;
  std::cout << "Constructor done." << std::endl;
}

/**
 * @brief  function to calculate the current error.
 * @return currentError of type double
 * Calculate the error between desired and current velocity.
 */

double PIDcontroller::computeError() {
  // Calculate the difference between desired and current velocity.
  double error = 0.0;
  error = desiredVelocity - currentVelocity;
  // Return currentError
  return error;
}

/**
 * @brief  function to calculate new velocity.
 * @return newVelocity of type double
 * Function that computes new velocities until it
 * converges to desiredVelocity using PID controller.
 */

double PIDcontroller::computeVelocity() {
  // Add newVelocity as data member if it makes more sense.
  double finalVelocity = 0;

  while (fabs(desiredVelocity - currentVelocity) > errorThreshold) {
    double proportionalError = computeError();
    double derivativeError = (proportionalError - previousError) / dTime;
    previousErrorSum += (proportionalError*dTime);
    double integralError = previousErrorSum;
    double controllerOutput = kP * proportionalError + kD * derivativeError
      + kI * integralError;
    currentVelocity += controllerOutput;
  }
  finalVelocity = currentVelocity;
	/* Implement loop to continuously calculate new velocity
	 * until it converges to desiredVelocity (less than error threshold).
	 * Use computeError to calculate error for PID equation.
	 * Calculate the controller output based on the PID equation.
	 * Add the controller output to the current velocity.
	 * Use appropriately named data members to store other components
	 * of the PID equation.
	 *
	 * Time increment and error threshold have been defined in the header.
	 * While testing, change PID constants in main() for convergence.
	 */

  return finalVelocity;
}

/**
 * @brief class PIDcontroller destructor
 */
PIDcontroller::~PIDcontroller() {
}
