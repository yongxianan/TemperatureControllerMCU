#include "unity.h"
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
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 10000;
  ccr3Data.secondCCR = 12500;
  ccr3Data.thirdCCR = 30000;
  ccr3Data.fourthCCR = 32500;
  ccr3Data.flag = 1;

  UpdateCCR3_Expect(10000);
  UpdateCCR3_Expect(12500);
  UpdateCCR3_Expect(30000);
  UpdateCCR3_Expect(32500);

//void TriacTriggerCallback(CCRxData *ccr3Data) is an interrupt
//4 interrupt in 1 cycle sine wave
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 1;

  UpdateCCR3_Expect(11000);
  UpdateCCR3_Expect(13500);
  UpdateCCR3_Expect(31000);
  UpdateCCR3_Expect(33500);

  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

}

void test_ExpectedNoChangeInFirstCycleUpdateWhenReachSecondCycle(void)
{
  //expect data to change after first sine wave
  //avoid change in first sine wave
  CCRxData ccr3Data;
  //CCR value for first sine wave
  ccr3Data.firstCCR = 10000;
  ccr3Data.secondCCR = 12500;
  ccr3Data.thirdCCR = 30000;
  ccr3Data.fourthCCR = 32500;
  ccr3Data.flag = 1;

  UpdateCCR3_Expect(10000);
  UpdateCCR3_Expect(12500);
  UpdateCCR3_Expect(30000);
  UpdateCCR3_Expect(32500);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

  //user set new firing angle (new CCR value) during first sine wave
  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 1;

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(1,ccr3Data.flag);

  UpdateCCR3_Expect(11000);
  UpdateCCR3_Expect(13500);
  UpdateCCR3_Expect(31000);
  UpdateCCR3_Expect(33500);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

}

void test_FlagNotSetInSecondCycle(void)
{
  //check flag if the firing angle set
  //flag = 1 in first cycle (reset due to interrupt use static),
  //flag = 0 in second cycle expect no CCR value set
  //there is 2 cycle of sine wave
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 0;
  ccr3Data.secondCCR = 0;
  ccr3Data.thirdCCR = 0;
  ccr3Data.fourthCCR = 0;
  ccr3Data.flag = 1;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 0;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

}

void test_NoFlagInFirstCycleExpectedNoChange(void)
{
  //flag is 1 in first cycle (reset due to interrupt use static),
  //no data change in second due to flag = 0
  //expect data to change after second sine wave
  //avoid change in second sine wave
  CCRxData ccr3Data;
  ccr3Data.firstCCR = 0;
  ccr3Data.secondCCR = 0;
  ccr3Data.thirdCCR = 0;
  ccr3Data.fourthCCR = 0;
  ccr3Data.flag = 1;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  ccr3Data.firstCCR = 10000;
  ccr3Data.secondCCR = 12500;
  ccr3Data.thirdCCR = 30000;
  ccr3Data.fourthCCR = 32500;
  ccr3Data.flag = 0;

  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);
  UpdateCCR3_Expect(0);

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(0,ccr3Data.flag);

  ccr3Data.firstCCR = 11000;
  ccr3Data.secondCCR = 13500;
  ccr3Data.thirdCCR = 31000;
  ccr3Data.fourthCCR = 33500;
  ccr3Data.flag = 1;

  TriacTriggerCallback(&ccr3Data);
  TriacTriggerCallback(&ccr3Data);

  TEST_ASSERT_EQUAL(1,ccr3Data.flag);

}
