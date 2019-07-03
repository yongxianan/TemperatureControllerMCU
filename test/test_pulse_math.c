#include "unity.h"
#include <malloc.h>
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
  Try{
    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
    CCR3Data->FirstCCR = 11000;
    CCR3Data->SecondCCR = 13500;
    CCR3Data->ThirdCCR = 31000;
    CCR3Data->FourthCCR = 33500;
    CCR3Data->Flag = 0;

    //CCRxData *CCR3Data = config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);
    //width = 0 - 100 %
    //angle = 0 - 180
    CCR3Data = config_pulse(CCR3Data,90,50);
    TEST_ASSERT_EQUAL(10000,CCR3Data->FirstCCR);
    TEST_ASSERT_EQUAL(15000,CCR3Data->SecondCCR);
    TEST_ASSERT_EQUAL(30000,CCR3Data->ThirdCCR);
    TEST_ASSERT_EQUAL(35000,CCR3Data->FourthCCR);
  }
  Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}

void test_ConfigWithFlagOne(void)
{
  CEXCEPTION_T ex = NULL;
  Try{
    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
    CCR3Data->FirstCCR = 11000;
    CCR3Data->SecondCCR = 13500;
    CCR3Data->ThirdCCR = 31000;
    CCR3Data->FourthCCR = 33500;
    CCR3Data->Flag = 1;

    //CCRxData *CCR3Data = config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);
    //width = 0 - 100 %
    //angle = 0 - 180
    CCR3Data = config_pulse(CCR3Data,90,50);
    TEST_ASSERT_EQUAL(11000,CCR3Data->FirstCCR);
    TEST_ASSERT_EQUAL(13500,CCR3Data->SecondCCR);
    TEST_ASSERT_EQUAL(31000,CCR3Data->ThirdCCR);
    TEST_ASSERT_EQUAL(33500,CCR3Data->FourthCCR);
  }
  Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}

void test_ConfigOver180Degree(void)
{
  CEXCEPTION_T ex = NULL;
  Try{
    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
    CCR3Data->FirstCCR = 11000;
    CCR3Data->SecondCCR = 13500;
    CCR3Data->ThirdCCR = 31000;
    CCR3Data->FourthCCR = 33500;
    CCR3Data->Flag = 0;

    //CCRxData *CCR3Data = config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);
    //width = 0 - 100 %
    //angle = 0 - 180
    CCR3Data = config_pulse(CCR3Data,220,50);
    TEST_ASSERT_EQUAL(20000,CCR3Data->FirstCCR);
    TEST_ASSERT_EQUAL(20000,CCR3Data->SecondCCR);
    TEST_ASSERT_EQUAL(40000,CCR3Data->ThirdCCR);
    TEST_ASSERT_EQUAL(40000,CCR3Data->FourthCCR);
  }
  Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}

void test_ConfigWidthOver100Percent(void)
{
  CEXCEPTION_T ex = NULL;
  Try{
    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
    CCR3Data->FirstCCR = 11000;
    CCR3Data->SecondCCR = 13500;
    CCR3Data->ThirdCCR = 31000;
    CCR3Data->FourthCCR = 33500;
    CCR3Data->Flag = 0;

    //CCRxData *CCR3Data = config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);
    //width = 0 - 100 %
    //angle = 0 - 180
    CCR3Data = config_pulse(CCR3Data,45,130);
    TEST_ASSERT_EQUAL(5000,CCR3Data->FirstCCR);
    TEST_ASSERT_EQUAL(20000,CCR3Data->SecondCCR);
    TEST_ASSERT_EQUAL(25000,CCR3Data->ThirdCCR);
    TEST_ASSERT_EQUAL(40000,CCR3Data->FourthCCR);
  }
  Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}

void test_ConfigWidthZeroPercent(void)
{
  CEXCEPTION_T ex = NULL;
  Try{
    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
    CCR3Data->FirstCCR = 11000;
    CCR3Data->SecondCCR = 13500;
    CCR3Data->ThirdCCR = 31000;
    CCR3Data->FourthCCR = 33500;
    CCR3Data->Flag = 0;

    //CCRxData *CCR3Data = config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);
    //width = 0 - 100 %
    //angle = 0 - 180
    CCR3Data = config_pulse(CCR3Data,45,0);
    TEST_ASSERT_EQUAL(5000,CCR3Data->FirstCCR);
    TEST_ASSERT_EQUAL(5000,CCR3Data->SecondCCR);
    TEST_ASSERT_EQUAL(25000,CCR3Data->ThirdCCR);
    TEST_ASSERT_EQUAL(25000,CCR3Data->FourthCCR);
  }
  Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}
