#ifndef PID_H
#define PID_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

class PID {
    double prev_cte;
public:
//    string outFileName = "";
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
    double Kp = 0;
  double Ki = 0;
  double Kd = 0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
    
    string outFileName;
void writeToFile(double cte, double steer, double throttle);
};

#endif /* PID_H */
