/*
 * pidMath.h
 *
 *  Created on: 12 Jul 2019
 *      Author: User
 */

#ifndef PIDMATH_H_
#define PIDMATH_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct{
  double setValue;
  double kp;
  double ki;
  double kd;
  double errorAcc;
  double prevError;
  uint32_t  prevTime;
  bool reachTemp;
}PidInfo;


int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime);

#endif /* PIDMATH_H_ */
