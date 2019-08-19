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

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((-10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

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

 ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,70,3);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}





void test_FindPIDValueWithPIDIntegrateAndAvoidPIDValueOver180(void){

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

 ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,70,3);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,50,4);

  UnityAssertEqualNumber((UNITY_INT)((180)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((100)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueWithPIDInWithinRange(void){

  PidInfo pidInfo;

  pidInfo.kp = 1;

  pidInfo.ki = 10;

  pidInfo.kd = 1;

  pidInfo.prevError = 5;

  pidInfo.setValue = 80;

  pidInfo.errorAcc = 0;

  pidInfo.prevTime = 1;

  int PIDValue = findPIDValue(&pidInfo,10,2);

  UnityAssertEqualNumber((UNITY_INT)((180)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(123), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((180)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_INT);



  PIDValue = findPIDValue(&pidInfo,130,3);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((-50)), (UNITY_INT)((pidInfo.prevError)), (

 ((void *)0)

 ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((pidInfo.errorAcc)), (

 ((void *)0)

 ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((pidInfo.prevTime)), (

 ((void *)0)

 ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

}
