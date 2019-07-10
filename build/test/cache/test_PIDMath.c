#include "build/temp/_test_PIDMath.c"
#include "PIDMath.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_FindPIDValue(void){

  PidInfo pidInfo;

  pidInfo.kp = 3;

  pidInfo.ki = 2;

  pidInfo.kd = 1;

  pidInfo.prevError = 20;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,70,2);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueNegativeCurrentError(void){

  PidInfo pidInfo;

  pidInfo.kp = 3;

  pidInfo.ki = 2;

  pidInfo.kd = 1;

  pidInfo.prevError = 20;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,90,2);

  UnityAssertEqualNumber((UNITY_INT)((-80)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueWithPIDIntegrate(void){







  PidInfo pidInfo;

  pidInfo.kp = 3;

  pidInfo.ki = 2;

  pidInfo.kd = 1;

  pidInfo.prevError = 20;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,70,2);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,70,3);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}





void test_FindPIDValueWithPIDIntegrateAndAvoidPIDValueOver90(void){

  PidInfo pidInfo;

  pidInfo.kp = 3;

  pidInfo.ki = 2;

  pidInfo.kd = 1;

  pidInfo.prevError = 20;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,70,2);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,70,3);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,50,4);

  UnityAssertEqualNumber((UNITY_INT)((90)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueWithPIDInReset(void){

  PidInfo pidInfo;

  pidInfo.kp = 1;

  pidInfo.ki = 1;

  pidInfo.kd = 1;

  pidInfo.prevError = 5;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,75,2);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,49,3);

  UnityAssertEqualNumber((UNITY_INT)((88)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}
