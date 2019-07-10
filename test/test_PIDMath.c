#include "unity.h"
#include "PIDMath.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*
typedef struct{
  double setValue;
  double kp;
  double ki;
  double kd;
  double errorAcc;
  double prevError;
  uint32_t  firingAngle;
  uint32_t  prevTime;
}PidInfo;
*/

//int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime)
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
  TEST_ASSERT_EQUAL(40,PIDValue);
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
  TEST_ASSERT_EQUAL(-80,PIDValue);
}

void test_FindPIDValueWithPIDIntegrate(void){
  //PIDIntegrate have integrate errors that caused by
  //previous called of function
  //int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime)
  PidInfo pidInfo;
  pidInfo.kp = 3;
  pidInfo.ki = 2;
  pidInfo.kd = 1;
  pidInfo.prevError = 20;
  pidInfo.setValue = 80;
  pidInfo.errorAcc = 0;
  pidInfo.prevTime = 1;
  int PIDValue = findPIDValue(&pidInfo,70,2);
  TEST_ASSERT_EQUAL(40,PIDValue);

  PIDValue = findPIDValue(&pidInfo,70,3);
  TEST_ASSERT_EQUAL(70,PIDValue);
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
  TEST_ASSERT_EQUAL(40,PIDValue);

  PIDValue = findPIDValue(&pidInfo,70,3);
  TEST_ASSERT_EQUAL(70,PIDValue);

  PIDValue = findPIDValue(&pidInfo,50,4);
  TEST_ASSERT_EQUAL(90,PIDValue);
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
  TEST_ASSERT_EQUAL(10,PIDValue);

  PIDValue = findPIDValue(&pidInfo,49,3);
  TEST_ASSERT_EQUAL(88,PIDValue);
}
