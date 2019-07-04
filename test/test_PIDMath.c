#include "unity.h"
#include "PIDMath.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//FindErrorsValues(PIDErr *PIDErrors, int SetTemp, int ActualTemp)
void test_FindErrorsValues(void)
{
    PIDErr *PIDErrors = (PIDErr *)malloc(sizeof(PIDErr));
    FindErrorsValues(PIDErrors, 80, -50);
    FindErrorsValues(PIDErrors, 80, 70);
    FindErrorsValues(PIDErrors, 80, 90);
    TEST_ASSERT_EQUAL(10,PIDErrors->Previous);
    TEST_ASSERT_EQUAL(-10,PIDErrors->Present);
}

//int FindPIDValue(PIDConst *PID, PIDErr *PIDErrors, float ElapsedTime)
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
  TEST_ASSERT_EQUAL(40,PIDValue);
}

void test_FindPIDValueWithPIDIntegrate(void){
  //PIDIntegrate have integrate errors that caused by
  //previous called of function
  //int FindPIDValue(PIDConst *PID,PIDErr *PIDErrors,float ElapsedTime,int *PIDIn)
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
  TEST_ASSERT_EQUAL(40,PIDValue);

  PIDErrors->Previous = 10;
  PIDErrors->Present = 10;
  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);
  TEST_ASSERT_EQUAL(70,PIDValue);
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
  TEST_ASSERT_EQUAL(40,PIDValue);

  PIDErrors->Previous = 10;
  PIDErrors->Present = 10;
  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);
  TEST_ASSERT_EQUAL(70,PIDValue);

  PIDErrors->Previous = 10;
  PIDErrors->Present = 30;
  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);
  TEST_ASSERT_EQUAL(90,PIDValue);
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
  TEST_ASSERT_EQUAL(10,PIDValue);

  PIDErrors->Previous = 5;
  PIDErrors->Present = 31;
  PIDValue = FindPIDValue(PID,PIDErrors,1,PIDIn);
  TEST_ASSERT_EQUAL(88,PIDValue);
}
