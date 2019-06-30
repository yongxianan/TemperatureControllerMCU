#include "build/temp/_test_TRIAC_IT.c"
#include "mock_timer.h"
#include "TRIAC_IT.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



void test_ChangeDataAtSecondCycle(void)

{







  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

  CCR3Data->FirstCCR = 10000;

  CCR3Data->SecondCCR = 12500;

  CCR3Data->ThirdCCR = 30000;

  CCR3Data->FourthCCR = 32500;

  CCR3Data->Flag = 1;



  UpdateCCR3_CMockExpect(25, 10000);

  UpdateCCR3_CMockExpect(26, 12500);

  UpdateCCR3_CMockExpect(27, 30000);

  UpdateCCR3_CMockExpect(28, 32500);







  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);



  CCR3Data->FirstCCR = 11000;

  CCR3Data->SecondCCR = 13500;

  CCR3Data->ThirdCCR = 31000;

  CCR3Data->FourthCCR = 33500;

  CCR3Data->Flag = 1;



  UpdateCCR3_CMockExpect(45, 11000);

  UpdateCCR3_CMockExpect(46, 13500);

  UpdateCCR3_CMockExpect(47, 31000);

  UpdateCCR3_CMockExpect(48, 33500);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);



}



void test_ExpectedNoChangeInFirstCycleUpdateWhenReachSecondCycle(void)

{





  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));



  CCR3Data->FirstCCR = 10000;

  CCR3Data->SecondCCR = 12500;

  CCR3Data->ThirdCCR = 30000;

  CCR3Data->FourthCCR = 32500;

  CCR3Data->Flag = 1;



  UpdateCCR3_CMockExpect(71, 10000);

  UpdateCCR3_CMockExpect(72, 12500);

  UpdateCCR3_CMockExpect(73, 30000);

  UpdateCCR3_CMockExpect(74, 32500);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);





  CCR3Data->FirstCCR = 11000;

  CCR3Data->SecondCCR = 13500;

  CCR3Data->ThirdCCR = 31000;

  CCR3Data->FourthCCR = 33500;

  CCR3Data->Flag = 1;



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);



  UpdateCCR3_CMockExpect(93, 11000);

  UpdateCCR3_CMockExpect(94, 13500);

  UpdateCCR3_CMockExpect(95, 31000);

  UpdateCCR3_CMockExpect(96, 33500);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);



}



void test_FlagNotSetInSecondCycle(void)

{









  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

  CCR3Data->FirstCCR = 0;

  CCR3Data->SecondCCR = 0;

  CCR3Data->ThirdCCR = 0;

  CCR3Data->FourthCCR = 0;

  CCR3Data->Flag = 1;



  UpdateCCR3_CMockExpect(119, 0);

  UpdateCCR3_CMockExpect(120, 0);

  UpdateCCR3_CMockExpect(121, 0);

  UpdateCCR3_CMockExpect(122, 0);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);



  CCR3Data->FirstCCR = 11000;

  CCR3Data->SecondCCR = 13500;

  CCR3Data->ThirdCCR = 31000;

  CCR3Data->FourthCCR = 33500;

  CCR3Data->Flag = 0;



  UpdateCCR3_CMockExpect(137, 0);

  UpdateCCR3_CMockExpect(138, 0);

  UpdateCCR3_CMockExpect(139, 0);

  UpdateCCR3_CMockExpect(140, 0);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_INT);



}



void test_NoFlagInFirstCycleExpectedNoChange(void)

{









  CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

  CCR3Data->FirstCCR = 0;

  CCR3Data->SecondCCR = 0;

  CCR3Data->ThirdCCR = 0;

  CCR3Data->FourthCCR = 0;

  CCR3Data->Flag = 1;



  UpdateCCR3_CMockExpect(164, 0);

  UpdateCCR3_CMockExpect(165, 0);

  UpdateCCR3_CMockExpect(166, 0);

  UpdateCCR3_CMockExpect(167, 0);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  CCR3Data->FirstCCR = 10000;

  CCR3Data->SecondCCR = 12500;

  CCR3Data->ThirdCCR = 30000;

  CCR3Data->FourthCCR = 32500;

  CCR3Data->Flag = 0;



  UpdateCCR3_CMockExpect(180, 0);

  UpdateCCR3_CMockExpect(181, 0);

  UpdateCCR3_CMockExpect(182, 0);

  UpdateCCR3_CMockExpect(183, 0);



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(188), UNITY_DISPLAY_STYLE_INT);



  CCR3Data->FirstCCR = 11000;

  CCR3Data->SecondCCR = 13500;

  CCR3Data->ThirdCCR = 31000;

  CCR3Data->FourthCCR = 33500;

  CCR3Data->Flag = 1;



  TriacTriggerCallback(CCR3Data);

  TriacTriggerCallback(CCR3Data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((CCR3Data->Flag)), (

 ((void *)0)

 ), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_INT);



}
