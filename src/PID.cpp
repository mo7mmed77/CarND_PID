#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd){}

PID::~PID() {}



void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // differential , propotional and integral errors 
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
 // Combing all PID controller gains and errors
  double steer = -Kp * p_error - Kd * d_error - Ki * i_error;

  // returning -1 for steer value if steer is less than -1
  if (steer < -1) {
    steer = -1;
  }

  //returning 1 if steer is more than 1
  if (steer > 1) {
    steer = 1;
  }

  // return steer value if steer between -1 and 1. 
  return steer;}