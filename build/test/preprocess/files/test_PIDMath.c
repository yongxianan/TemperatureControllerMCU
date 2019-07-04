#include "build/temp/_test_PIDMath.c"
#include "PIDMath.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}





void test_FindErrorsValues(void)

{

    PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));

    FindErrorsValues(PIDErrors, 80, -50);

    FindErrorsValues(PIDErrors, 80, 70);

    FindErrorsValues(PIDErrors, 80, 90);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((PIDErrors->Previous)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((-10)), (UNITY_INT)((PIDErrors->Present)), (

   ((void *)0)

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}





void test_FindPIDValue(void){

  PIDConst *PID = (PIDConst *)malloc(sizeof(PIDConst));

  PID->Kp = 3;

  PID->Ki = 2;

  PID->Kd = 1;

  PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));

  PIDErrors->Previous = 20;

  PIDErrors->Present = 10;

  int *PIDIn = (int *)malloc(sizeof(int));

  *PIDIn = 0;

  int PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueWithPIDIntegrate(void){







  PIDConst *PID = (PIDConst *)malloc(sizeof(PIDConst));

  PID->Kp = 3;

  PID->Ki = 2;

  PID->Kd = 1;

  PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));

  PIDErrors->Previous = 20;

  PIDErrors->Present = 10;

  int *PIDIn = (int *)malloc(sizeof(int));

  *PIDIn = 0;

  int PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);



  PIDErrors->Previous = 10;

  PIDErrors->Present = 10;

  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

}





void test_FindPIDValueWithPIDIntegrateAndAvoidPIDValueOver90(void){

  PIDConst *PID = (PIDConst *)malloc(sizeof(PIDConst));

  PID->Kp = 3;

  PID->Ki = 2;

  PID->Kd = 1;

  PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));

  PIDErrors->Previous = 20;

  PIDErrors->Present = 10;

  int *PIDIn = (int *)malloc(sizeof(int));

  *PIDIn = 0;

  int PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((40)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);



  PIDErrors->Previous = 10;

  PIDErrors->Present = 10;

  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((70)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);



  PIDErrors->Previous = 10;

  PIDErrors->Present = 30;

  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((90)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

}



void test_FindPIDValueWithPIDInReset(void){

  PIDConst *PID = (PIDConst *)malloc(sizeof(PIDConst));

  PID->Kp = 1;

  PID->Ki = 1;

  PID->Kd = 1;

  PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));

  PIDErrors->Previous = 5;

  PIDErrors->Present = 5;

  int *PIDIn = (int *)malloc(sizeof(int));

  *PIDIn = 0;

  int PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);



  PIDErrors->Previous = 5;

  PIDErrors->Present = 31;

  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);

  UnityAssertEqualNumber((UNITY_INT)((88)), (UNITY_INT)((PIDValue)), (

 ((void *)0)

 ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_INT);

}
