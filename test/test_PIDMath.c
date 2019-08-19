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
  TEST_ASSERT_EQUAL(10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(20,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(2,pidInfo.prevTime);
}

void test_FindPIDValueNegativeCurrentError(void){
  //expect PIDValue = 0, can't go negative value
  PidInfo pidInfo;
  pidInfo.kp = 3;
  pidInfo.ki = 2;
  pidInfo.kd = 1;
  pidInfo.prevError = 20;
  pidInfo.setValue = 80;
  pidInfo.errorAcc = 0;
  pidInfo.prevTime = 1;
  int PIDValue = findPIDValue(&pidInfo,90,2);
  TEST_ASSERT_EQUAL(0,PIDValue);
  TEST_ASSERT_EQUAL(-10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(0,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(2,pidInfo.prevTime);
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
  TEST_ASSERT_EQUAL(10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(20,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(2,pidInfo.prevTime);

  PIDValue = findPIDValue(&pidInfo,70,3);
  TEST_ASSERT_EQUAL(70,PIDValue);
  TEST_ASSERT_EQUAL(10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(40,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(3,pidInfo.prevTime);
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
  TEST_ASSERT_EQUAL(40,PIDValue);
  TEST_ASSERT_EQUAL(10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(20,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(2,pidInfo.prevTime);

  PIDValue = findPIDValue(&pidInfo,70,3);
  TEST_ASSERT_EQUAL(70,PIDValue);
  TEST_ASSERT_EQUAL(10,pidInfo.prevError);
  TEST_ASSERT_EQUAL(40,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(3,pidInfo.prevTime);

  PIDValue = findPIDValue(&pidInfo,50,4);
  TEST_ASSERT_EQUAL(180,PIDValue);
  TEST_ASSERT_EQUAL(30,pidInfo.prevError);
  TEST_ASSERT_EQUAL(100,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(4,pidInfo.prevTime);
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
  TEST_ASSERT_EQUAL(180,PIDValue);
  TEST_ASSERT_EQUAL(70,pidInfo.prevError);
  TEST_ASSERT_EQUAL(180,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(2,pidInfo.prevTime);

  PIDValue = findPIDValue(&pidInfo,130,3);
  TEST_ASSERT_EQUAL(0,PIDValue);
  TEST_ASSERT_EQUAL(-50,pidInfo.prevError);
  TEST_ASSERT_EQUAL(0,pidInfo.errorAcc);
  TEST_ASSERT_EQUAL(3,pidInfo.prevTime);
}
