#include "PIDMath.h"

int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime){
  int pidProprotional = 0;
  int pidDerivative = 0;
  int pidValue = 0;
  double currentError = (pidInfo->setValue)-actualTemp;
  uint32_t  elapsedTime = currentTime-(pidInfo->prevTime);
  //integral constant will only affect errors below 30ºC
  if(currentError>30){
    (pidInfo->errorAcc)=0;
  }

  pidProprotional = (currentError)*(pidInfo->kp);
  (pidInfo->errorAcc) = ((pidInfo->ki)*currentError)+(pidInfo->errorAcc);
  pidDerivative = (currentError-(pidInfo->prevError))*(pidInfo->kd)/elapsedTime;

  pidValue = (pidInfo->errorAcc)+pidProprotional+pidDerivative;
  if(pidValue<-90){
    pidValue=-90;
  }
  if(pidValue>90){
    pidValue=90;
  }
  (pidInfo->prevTime) = currentTime;
  (pidInfo->prevError) = currentError;
  return pidValue;
}
