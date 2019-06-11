#include "PID.h"
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

   //initilize gains

   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;

   // initilize errors

   pErr=0;
   iErr=0;
   dErr=0;

   is_initialized = true;

}

void PID::UpdateError(double cte, double dt)
  {
   // Update PID errors based on cte.

   if(is_initialized==false)
   {
     cteDelta = 0;
   } else {
     cteDelta = cte - ctePrev;
   }

   pErr = cte;
   iErr += cte*dt;
   dErr = cteDelta/dt ;
   ctePrev = cte;
}

double PID::pidController(double cte)
{
  // Calculate and return the control signal (steer value)

  if(is_initialized==false)
  {
    double KpIn;
    double KiIn;
    double KdIn;
    std::cout << "Input Kp, Ki, and Kd values:" << std::endl;
    std::cin >> KpIn >> KiIn >> KdIn;
    std::cout << "Kp: " << KpIn <<", Ki: "<< KiIn << " , Kd: " << KdIn << std::endl;
    Init(KpIn,KiIn,KdIn);
  };

  double u;
  UpdateError(cte, deltaT);

  u = -Kp*pErr - Ki*iErr - Kd*dErr;

  std::cout << "Kp:" << Kp << " | pErr: "<< pErr << " | dErr: " << dErr << "iErr" << iErr <<std::endl;

  return u;  // TODO: Add your total error calc here!
}
