#include "PIDMath.h"


void FindErrorsValues(PIDErr *PIDErrors, float SetTemp, float ActualTemp){
  PIDErrors->Previous = PIDErrors->Present;
  PIDErrors->Present = SetTemp-ActualTemp;
}


int FindPIDValue(PIDConst *PID,PIDErr *PIDErrors,float ElapsedTime,int *PIDIn){
  int PIDProprotional = 0;
  int PIDDerivative = 0;
  int PIDValue = 0;
  //integral constant will only affect errors below 30ºC
  if(PIDErrors->Present>30){
    *PIDIn = 0;
  }
  PIDProprotional = (PIDErrors->Present)*(PID->Kp);
  *PIDIn = ((PID->Ki)*(PIDErrors->Present))+(*PIDIn);
  PIDDerivative = ((PIDErrors->Present)-(PIDErrors->Previous))*(PID->Kd)/ElapsedTime;
  PIDValue = (*PIDIn)+PIDProprotional+PIDDerivative;
  if(PIDValue<-90){
    PIDValue=0;
  }
  if(PIDValue>90){
    PIDValue=90;
  }
  return PIDValue;
}
