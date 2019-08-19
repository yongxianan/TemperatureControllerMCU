/*
 * pidMath.c
 *
 *  Created on: 12 Jul 2019
 *      Author: User
 */


#include "pidMath.h"

int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime){
  int pidProprotional = 0;
  int pidDerivative = 0;
  int pidValue = 0;

  /*
   * find current error.
   * find the time difference for the derivative part of pid.
   */
  double currentError = (pidInfo->setValue)-actualTemp;
  uint32_t  elapsedTime = currentTime-(pidInfo->prevTime);


  pidProprotional = (currentError)*(pidInfo->kp);
  (pidInfo->errorAcc) = ((pidInfo->ki)*currentError)+(pidInfo->errorAcc);
  pidDerivative = (currentError-(pidInfo->prevError))*(pidInfo->kd)/elapsedTime;

  /*
   * this code limit the pidIntegrate to 0 - 180
   */
  if((pidInfo->errorAcc)>=180){
    (pidInfo->errorAcc)=180;
  }
  else if((pidInfo->errorAcc)<=0){
    (pidInfo->errorAcc)=0;
  }

  /*
   * when temperature reach 10 degree (or less) celsius below set temperature,
   * it will reset the pidIntegrate once only, it won't reset the pidIntegrate for the remaining temperature below 10
   * it will reset the pidIntegrate again if the user set a new temperature.
   * pidInfo->reachTemp tell whether the temperature reach 10 degree celsius below once or not.
   */
  if(currentError<=10 && (pidInfo->reachTemp)==false){
	(pidInfo->errorAcc)=90;
	(pidInfo->reachTemp)=true;
  }

  pidValue = (pidInfo->errorAcc)+pidProprotional+pidDerivative;
  if(pidValue<0){
    pidValue=0;
  }
  if(pidValue>180){
    pidValue=180;
  }

  /*
   * hold the current time and current error for the next pid calculation.
   */
  (pidInfo->prevTime) = currentTime;
  (pidInfo->prevError) = currentError;
  return pidValue;
}
