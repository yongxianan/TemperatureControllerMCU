#include "build/temp/_test_pulse_math.c"
#include "CException.h"
#include "Exception.h"
#include "Error.h"
#include "pulse_math.h"
#include "unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_ConfigWithFlagZero(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){

    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

    CCR3Data->FirstCCR = 11000;

    CCR3Data->SecondCCR = 13500;

    CCR3Data->ThirdCCR = 31000;

    CCR3Data->FourthCCR = 33500;

    CCR3Data->Flag = 0;









    CCR3Data = config_pulse(CCR3Data,90,50);

    UnityAssertEqualNumber((UNITY_INT)((10000)), (UNITY_INT)((CCR3Data->FirstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15000)), (UNITY_INT)((CCR3Data->SecondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((30000)), (UNITY_INT)((CCR3Data->ThirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((35000)), (UNITY_INT)((CCR3Data->FourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

  }

  freeException(ex);

}



void test_ConfigWithFlagOne(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){

    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

    CCR3Data->FirstCCR = 11000;

    CCR3Data->SecondCCR = 13500;

    CCR3Data->ThirdCCR = 31000;

    CCR3Data->FourthCCR = 33500;

    CCR3Data->Flag = 1;









    CCR3Data = config_pulse(CCR3Data,90,50);

    UnityAssertEqualNumber((UNITY_INT)((11000)), (UNITY_INT)((CCR3Data->FirstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((13500)), (UNITY_INT)((CCR3Data->SecondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((31000)), (UNITY_INT)((CCR3Data->ThirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((33500)), (UNITY_INT)((CCR3Data->FourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

  }

  freeException(ex);

}



void test_ConfigOver180Degree(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){

    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

    CCR3Data->FirstCCR = 11000;

    CCR3Data->SecondCCR = 13500;

    CCR3Data->ThirdCCR = 31000;

    CCR3Data->FourthCCR = 33500;

    CCR3Data->Flag = 0;









    CCR3Data = config_pulse(CCR3Data,220,50);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((CCR3Data->FirstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((CCR3Data->SecondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((CCR3Data->ThirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((CCR3Data->FourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

  }

  freeException(ex);

}



void test_ConfigWidthOver100Percent(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){

    CCRxData *CCR3Data = (CCRxData*)malloc(sizeof(CCRxData));

    CCR3Data->FirstCCR = 11000;

    CCR3Data->SecondCCR = 13500;

    CCR3Data->ThirdCCR = 31000;

    CCR3Data->FourthCCR = 33500;

    CCR3Data->Flag = 0;









    CCR3Data = config_pulse(CCR3Data,45,130);

    UnityAssertEqualNumber((UNITY_INT)((5000)), (UNITY_INT)((CCR3Data->FirstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((CCR3Data->SecondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25000)), (UNITY_INT)((CCR3Data->ThirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((CCR3Data->FourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

  }

  freeException(ex);

}
