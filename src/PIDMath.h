#ifndef _PIDMATH_H
#define _PIDMATH_H


#include <malloc.h>

typedef struct{
  float Present;
  float Previous;
}PIDErr;

typedef struct{
  float Kp;
  float Ki;
  float Kd;
}PIDConst;

void FindErrorsValues(PIDErr *PIDErrors, float SetTemp, float ActualTemp);
int FindPIDValue(PIDConst *PID,PIDErr *PIDErrors,float ElapsedTime,int *PIDIn);

#endif // _PIDMATH_H
