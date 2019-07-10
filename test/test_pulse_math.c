#include "unity.h"
#include "pulse_math.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"
//#include "TRIAC_IT.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ConfigWithFlagZero(void)
{
  CEXCEPTION_T ex = NULL;
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 0;
  Try{
    //config_pulse(CCRxData *CCR3Data , uint32_t angle, uint32_t width);
    //width = 0 - 180
    //angle = 0 - 180
    config_pulse(&ccr3Data,90,50);
    TEST_ASSERT_EQUAL(10000,ccr3Data.firstCCR);
    TEST_ASSERT_EQUAL(15555,ccr3Data.secondCCR);
    TEST_ASSERT_EQUAL(30000,ccr3Data.thirdCCR);
    TEST_ASSERT_EQUAL(35555,ccr3Data.fourthCCR);
  }
  Catch(ex){
    dumpException(ex);
    TEST_FAIL_MESSAGE("don't expect exception to be thrown");
    freeException(ex);
  }

}

void test_ConfigWithFlagOne(void)
{
  CEXCEPTION_T ex = NULL;
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 1;
  Try{
    //config_pulse(CCRxData *CCR3Data , uint32_t angle, uint32_t width);
    //width = 0 - 180
    //angle = 0 - 180
    config_pulse(&ccr3Data,90,50);
    TEST_FAIL_MESSAGE("expect exception to be thrown");
  }
  Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(11000,ccr3Data.firstCCR);
    TEST_ASSERT_EQUAL(13500,ccr3Data.secondCCR);
    TEST_ASSERT_EQUAL(31000,ccr3Data.thirdCCR);
    TEST_ASSERT_EQUAL(33500,ccr3Data.fourthCCR);
    TEST_ASSERT_EQUAL(1,ccr3Data.flag);
    freeException(ex);
  }
}

void test_ConfigOver180Degree(void)
{
  CEXCEPTION_T ex = NULL;
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 0;


  Try{
  //config_pulse(CCRxData *CCR3Data , uint32_t angle, uint32_t width);
    //width = 0 - 180
    //angle = 0 - 180
    config_pulse(&ccr3Data,220,50);
    TEST_ASSERT_EQUAL(20000,ccr3Data.firstCCR);
    TEST_ASSERT_EQUAL(20000,ccr3Data.secondCCR);
    TEST_ASSERT_EQUAL(40000,ccr3Data.thirdCCR);
    TEST_ASSERT_EQUAL(40000,ccr3Data.fourthCCR);
  }
  Catch(ex){
    dumpException(ex);
    TEST_FAIL_MESSAGE("don't expect exception to be thrown");
    freeException(ex);
  }
}

void test_ConfigWidthOver180(void)
{
  CEXCEPTION_T ex = NULL;
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 0;


  Try{
    //config_pulse(CCRxData *CCR3Data , uint32_t angle, uint32_t width);
    //width = 0 - 180
    //angle = 0 - 180
    config_pulse(&ccr3Data,45,185);
    TEST_ASSERT_EQUAL(5000,ccr3Data.firstCCR);
    TEST_ASSERT_EQUAL(20000,ccr3Data.secondCCR);
    TEST_ASSERT_EQUAL(25000,ccr3Data.thirdCCR);
    TEST_ASSERT_EQUAL(40000,ccr3Data.fourthCCR);
  }
  Catch(ex){
    dumpException(ex);
    TEST_FAIL_MESSAGE("don't expect exception to be thrown");
    freeException(ex);
  }
}

void test_ConfigWidthZero(void)
{
  CEXCEPTION_T ex = NULL;
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 0;
  Try{


    //config_pulse(CCRxData *CCR3Data , uint32_t angle, uint32_t width);
    //width = 0 - 180
    //angle = 0 - 180
    config_pulse(&ccr3Data,45,0);
    TEST_ASSERT_EQUAL(5000,ccr3Data.firstCCR);
    TEST_ASSERT_EQUAL(5000,ccr3Data.secondCCR);
    TEST_ASSERT_EQUAL(25000,ccr3Data.thirdCCR);
    TEST_ASSERT_EQUAL(25000,ccr3Data.fourthCCR);
  }
  Catch(ex){
    dumpException(ex);
    TEST_FAIL_MESSAGE("don't expect exception to be thrown");
    freeException(ex);
  }
}
