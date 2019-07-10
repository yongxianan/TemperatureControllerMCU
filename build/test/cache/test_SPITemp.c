#include "build/temp/_test_SPITemp.c"
#include "CException.h"
#include "Exception.h"
#include "Error.h"
#include "SPITemp.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_calculateTempFromBinary(void)

{





    uint8_t TempData[2];

    TempData[0] = 0b11000000;

    TempData[1] = 0b00000011;

    int temp = calculateTemp(&TempData[0]);

    UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((temp)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}





void test_calculateTempThermocoupleIsOpen(void)

{

    ExceptionPtr ex = 

                     ((void *)0)

                         ;







    uint8_t TempData[2];

    TempData[0] = 0b11000100;

    TempData[1] = 0b00000011;

    int temp = 0;



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

      temp = calculateTemp(&TempData[0]);

      UnityFail( (("expect exception to be thrown")), (UNITY_UINT)(40));

    }

    else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

      dumpException(ex);

      UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((temp)), (

     ((void *)0)

     ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

      freeException(ex);

    }

}
