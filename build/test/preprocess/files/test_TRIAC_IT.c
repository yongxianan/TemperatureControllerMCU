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







  CCRxData ccr3Data;

  ccr3Data.firstCCR = 10000;

  ccr3Data.secondCCR = 12500;

  ccr3Data.thirdCCR = 30000;

  ccr3Data.fourthCCR = 32500;

  ccr3Data.flag = 1;



  UpdateCCR3_CMockExpect(24, 10000);

  UpdateCCR3_CMockExpect(25, 12500);

  UpdateCCR3_CMockExpect(26, 30000);

  UpdateCCR3_CMockExpect(27, 32500);







  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);



  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 1;



  UpdateCCR3_CMockExpect(47, 11000);

  UpdateCCR3_CMockExpect(48, 13500);

  UpdateCCR3_CMockExpect(49, 31000);

  UpdateCCR3_CMockExpect(50, 33500);



  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);



}



void test_ExpectedNoChangeInFirstCycleUpdateWhenReachSecondCycle(void)

{





  CCRxData ccr3Data;



  ccr3Data.firstCCR = 10000;

  ccr3Data.secondCCR = 12500;

  ccr3Data.thirdCCR = 30000;

  ccr3Data.fourthCCR = 32500;

  ccr3Data.flag = 1;



  UpdateCCR3_CMockExpect(76, 10000);

  UpdateCCR3_CMockExpect(77, 12500);

  UpdateCCR3_CMockExpect(78, 30000);

  UpdateCCR3_CMockExpect(79, 32500);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);





  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 1;



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);



  UpdateCCR3_CMockExpect(98, 11000);

  UpdateCCR3_CMockExpect(99, 13500);

  UpdateCCR3_CMockExpect(100, 31000);

  UpdateCCR3_CMockExpect(101, 33500);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);



}



void test_FlagNotSetInSecondCycle(void)

{









  CCRxData ccr3Data;

  ccr3Data.firstCCR = 0;

  ccr3Data.secondCCR = 0;

  ccr3Data.thirdCCR = 0;

  ccr3Data.fourthCCR = 0;

  ccr3Data.flag = 1;



  UpdateCCR3_CMockExpect(124, 0);

  UpdateCCR3_CMockExpect(125, 0);

  UpdateCCR3_CMockExpect(126, 0);

  UpdateCCR3_CMockExpect(127, 0);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);



  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 0;



  UpdateCCR3_CMockExpect(142, 0);

  UpdateCCR3_CMockExpect(143, 0);

  UpdateCCR3_CMockExpect(144, 0);

  UpdateCCR3_CMockExpect(145, 0);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_INT);



}



void test_NoFlagInFirstCycleExpectedNoChange(void)

{









  CCRxData ccr3Data;

  ccr3Data.firstCCR = 0;

  ccr3Data.secondCCR = 0;

  ccr3Data.thirdCCR = 0;

  ccr3Data.fourthCCR = 0;

  ccr3Data.flag = 1;



  UpdateCCR3_CMockExpect(169, 0);

  UpdateCCR3_CMockExpect(170, 0);

  UpdateCCR3_CMockExpect(171, 0);

  UpdateCCR3_CMockExpect(172, 0);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  ccr3Data.firstCCR = 10000;

  ccr3Data.secondCCR = 12500;

  ccr3Data.thirdCCR = 30000;

  ccr3Data.fourthCCR = 32500;

  ccr3Data.flag = 0;



  UpdateCCR3_CMockExpect(185, 0);

  UpdateCCR3_CMockExpect(186, 0);

  UpdateCCR3_CMockExpect(187, 0);

  UpdateCCR3_CMockExpect(188, 0);



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_INT);



  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 1;



  TriacTriggerCallback(&ccr3Data);

  TriacTriggerCallback(&ccr3Data);



  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ccr3Data.flag)), (

 ((void *)0)

 ), (UNITY_UINT)(204), UNITY_DISPLAY_STYLE_INT);



}
