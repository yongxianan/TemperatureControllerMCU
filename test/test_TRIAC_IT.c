#include "unity.h"
#include <malloc.h>
#include "TRIAC_IT.h"
#include "mock_timer.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_ChangeDataAtSecondCycle(void)
{
  //check flag if the firing angle set
  //there is 2 cycle of sine wave
  //set firing angle twice
  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
  CCR3Data->FirstCCR = 10000;
  CCR3Data->SecondCCR = 12500;
  CCR3Data->ThirdCCR = 30000;
  CCR3Data->FourthCCR = 32500;
  CCR3Data->Flag = 1;

  UpdateCCR3_Expect(10000);
  UpdateCCR3_Expect(12500);
  UpdateCCR3_Expect(30000);
  UpdateCCR3_Expect(32500);

//void TriacTriggerCallback(CCRxData *CCR3Data) is an interrupt
//4 interrupt in 1 cycle sine wave
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

  CCR3Data->FirstCCR = 11000;
  CCR3Data->SecondCCR = 13500;
  CCR3Data->ThirdCCR = 31000;
  CCR3Data->FourthCCR = 33500;
  CCR3Data->Flag = 1;

  UpdateCCR3_Expect(11000);
  UpdateCCR3_Expect(13500);
  UpdateCCR3_Expect(31000);
  UpdateCCR3_Expect(33500);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

}

void test_ExpectedNoChangeInFirstCycleUpdateWhenReachSecondCycle(void)
{
  //expect data to change after first sine wave
  //avoid change in first sine wave
  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
  //CCR value for first sine wave
  CCR3Data->FirstCCR = 10000;
  CCR3Data->SecondCCR = 12500;
  CCR3Data->ThirdCCR = 30000;
  CCR3Data->FourthCCR = 32500;
  CCR3Data->Flag = 1;

  UpdateCCR3_Expect(10000);
  UpdateCCR3_Expect(12500);
  UpdateCCR3_Expect(30000);
  UpdateCCR3_Expect(32500);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

  //user set new firing angle (new CCR value) during first sine wave
  CCR3Data->FirstCCR = 11000;
  CCR3Data->SecondCCR = 13500;
  CCR3Data->ThirdCCR = 31000;
  CCR3Data->FourthCCR = 33500;
  CCR3Data->Flag = 1;

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(1,CCR3Data->Flag);

  UpdateCCR3_Expect(11000);
  UpdateCCR3_Expect(13500);
  UpdateCCR3_Expect(31000);
  UpdateCCR3_Expect(33500);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

}

void test_FlagNotSetInSecondCycle(void)
{
  //check flag if the firing angle set
  //flag = 1 in first cycle (reset due to interrupt use static),
  //flag = 0 in second cycle expect no CCR value set
  //there is 2 cycle of sine wave
  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
  CCR3Data->FirstCCR = 0;
  CCR3Data->SecondCCR = 0;
  CCR3Data->ThirdCCR = 0;
  CCR3Data->FourthCCR = 0;
  CCR3Data->Flag = 1;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

  CCR3Data->FirstCCR = 11000;
  CCR3Data->SecondCCR = 13500;
  CCR3Data->ThirdCCR = 31000;
  CCR3Data->FourthCCR = 33500;
  CCR3Data->Flag = 0;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

}

void test_NoFlagInFirstCycleExpectedNoChange(void)
{
  //flag is 1 in first cycle (reset due to interrupt use static),
  //no data change in second due to flag = 0
  //expect data to change after second sine wave
  //avoid change in second sine wave
  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));
  CCR3Data->FirstCCR = 0;
  CCR3Data->SecondCCR = 0;
  CCR3Data->ThirdCCR = 0;
  CCR3Data->FourthCCR = 0;
  CCR3Data->Flag = 1;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  CCR3Data->FirstCCR = 10000;
  CCR3Data->SecondCCR = 12500;
  CCR3Data->ThirdCCR = 30000;
  CCR3Data->FourthCCR = 32500;
  CCR3Data->Flag = 0;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(0,CCR3Data->Flag);

  CCR3Data->FirstCCR = 11000;
  CCR3Data->SecondCCR = 13500;
  CCR3Data->ThirdCCR = 31000;
  CCR3Data->FourthCCR = 33500;
  CCR3Data->Flag = 1;

  TriacTriggerCallback(CCR3Data);
  TriacTriggerCallback(CCR3Data);

  TEST_ASSERT_EQUAL(1,CCR3Data->Flag);

}
