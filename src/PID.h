#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte, double dt);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double pidController(double cte);

  // set initialization boolean

  bool is_initialized = false;

 private:
  /**
   * PID Errors
   */
  double pErr;
  double iErr;
  double dErr;

  /**
   * PID Coefficients
   */
  double Kp;
  double Ki;
  double Kd;

  // cte error variables

  double ctePrev = 0; // previous value of cte
  double cteDelta; //change in cte with change in time

  // time increment

  double deltaT = 0.1; // seconds
};

#endif  // PID_H
