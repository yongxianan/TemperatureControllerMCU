#include "PIDMath.h"

int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime){
  int pidProprotional = 0;
  int pidDerivative = 0;
  int pidValue = 0;
  double currentError = (pidInfo->setValue)-actualTemp;
  uint32_t  elapsedTime = currentTime-(pidInfo->prevTime);


  pidProprotional = (currentError)*(pidInfo->kp);
  (pidInfo->errorAcc) = ((pidInfo->ki)*currentError)+(pidInfo->errorAcc);
  pidDerivative = (currentError-(pidInfo->prevError))*(pidInfo->kd)/elapsedTime;

  if((pidInfo->errorAcc)>=180){
    (pidInfo->errorAcc)=180;
  }
  else if((pidInfo->errorAcc)<=0){
    (pidInfo->errorAcc)=0;
  }

  if(currentError<0){
    (pidInfo->errorAcc)=90;
  }

  pidValue = (pidInfo->errorAcc)+pidProprotional+pidDerivative;
  if(pidValue<0){
    pidValue=0;
  }
  if(pidValue>180){
    pidValue=180;
  }
  (pidInfo->prevTime) = currentTime;
  (pidInfo->prevError) = currentError;
  return pidValue;
}
