#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    
    this->prev_cte = 0.0;
    this->i_error = 0.0;
    
    this->outFileName = "PID_thr_0.6_" + std::to_string(this->Kp) + "_" + std::to_string(this->Ki) + "_" + std::to_string(this->Kd) + ".csv";
    ofstream myfile;
    myfile.open(outFileName);//,ios::app);
    myfile << "cte,steer,throttle" << std::endl;
    myfile.close();
}

void PID::UpdateError(double cte) {
    this->p_error = cte;
    if (prev_cte*cte <  0)
    {
        this->i_error = 0;
    }
    else
    {
        this->i_error += cte;
    }
    this->d_error = cte - this->prev_cte;
    this->prev_cte = cte;
}

double PID::TotalError() {
    return 0.0;
}

void PID::writeToFile(double cte, double steer, double throttle) {
    ofstream myfile;
//    string outFileName = "PID_" + std::to_string(Kp) + "_" + std::to_string(Ki) + "_" + std::to_string(Kd) + ".csv";
    myfile.open(this->outFileName,ios::app);
    myfile << cte << "," << steer << "," << throttle << std::endl;
    myfile.close();
}

