#ifndef _PIDMATH_H
#define _PIDMATH_H


#include <stdint.h>

typedef struct{
  double Present;
  double Previous;
}PIDErr;

typedef struct{
  double Kp;
  double Ki;
  double Kd;
}PIDConst;


typedef struct{
  double setValue;
  double kp;
  double ki;
  double kd;
  double errorAcc;
  double prevError;
  uint32_t  prevTime;
}PidInfo;


int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime);

#endif // _PIDMATH_H
