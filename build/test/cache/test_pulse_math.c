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

  CCRxData ccr3Data;

  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 0;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){







    config_pulse(&ccr3Data,90,50);

    UnityAssertEqualNumber((UNITY_INT)((10000)), (UNITY_INT)((ccr3Data.firstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15555)), (UNITY_INT)((ccr3Data.secondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((30000)), (UNITY_INT)((ccr3Data.thirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((35555)), (UNITY_INT)((ccr3Data.fourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    UnityFail( (("don't expect exception to be thrown")), (UNITY_UINT)(37));

    freeException(ex);

  }



}



void test_ConfigWithFlagOne(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  CCRxData ccr3Data;

  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 1;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){







    config_pulse(&ccr3Data,90,50);

    UnityFail( (("expect exception to be thrown")), (UNITY_UINT)(57));

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    UnityAssertEqualNumber((UNITY_INT)((11000)), (UNITY_INT)((ccr3Data.firstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((13500)), (UNITY_INT)((ccr3Data.secondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((31000)), (UNITY_INT)((ccr3Data.thirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((33500)), (UNITY_INT)((ccr3Data.fourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ccr3Data.flag)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

    freeException(ex);

  }

}



void test_ConfigOver180Degree(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  CCRxData ccr3Data;

  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 0;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){







    config_pulse(&ccr3Data,220,50);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((ccr3Data.firstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((ccr3Data.secondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((ccr3Data.thirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((ccr3Data.fourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    UnityFail( (("don't expect exception to be thrown")), (UNITY_UINT)(93));

    freeException(ex);

  }

}



void test_ConfigWidthOver180(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  CCRxData ccr3Data;

  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 0;





  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){







    config_pulse(&ccr3Data,45,185);

    UnityAssertEqualNumber((UNITY_INT)((5000)), (UNITY_INT)((ccr3Data.firstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((20000)), (UNITY_INT)((ccr3Data.secondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25000)), (UNITY_INT)((ccr3Data.thirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((40000)), (UNITY_INT)((ccr3Data.fourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    UnityFail( (("don't expect exception to be thrown")), (UNITY_UINT)(121));

    freeException(ex);

  }

}



void test_ConfigWidthZero(void)

{

  ExceptionPtr ex = 

                   ((void *)0)

                       ;

  CCRxData ccr3Data;

  ccr3Data.firstCCR = 11000;

  ccr3Data.secondCCR = 13500;

  ccr3Data.thirdCCR = 31000;

  ccr3Data.fourthCCR = 33500;

  ccr3Data.flag = 0;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1){











    config_pulse(&ccr3Data,45,0);

    UnityAssertEqualNumber((UNITY_INT)((5000)), (UNITY_INT)((ccr3Data.firstCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((5000)), (UNITY_INT)((ccr3Data.secondCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25000)), (UNITY_INT)((ccr3Data.thirdCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25000)), (UNITY_INT)((ccr3Data.fourthCCR)), (

   ((void *)0)

   ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    UnityFail( (("don't expect exception to be thrown")), (UNITY_UINT)(149));

    freeException(ex);

  }

}
