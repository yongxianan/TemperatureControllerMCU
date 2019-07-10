#include "unity.h"
#include "SPITemp.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_calculateTempFromBinary(void)
{
    //30 celsius * 0.25 = 120 in decimal = 0000 0111 1000 in 12 bit data
    //bit 0 - bit 2 all zeros
    uint8_t TempData[2];
    TempData[0] = 0b11000000;
    TempData[1] = 0b00000011;
    int temp = calculateTemp(&TempData[0]);
    TEST_ASSERT_EQUAL(30, temp);
}


void test_calculateTempThermocoupleIsOpen(void)
{
    CEXCEPTION_T ex = NULL;
    //30 celsius * 0.25 = 120 in decimal = 0000 0111 1000 in 12 bit data
    //bit 0 - bit 1 all zeros
    //bit 2 = 1 to indicate thermocouple input is open
    uint8_t TempData[2];
    TempData[0] = 0b11000100;
    TempData[1] = 0b00000011;
    int temp = 0;

    Try{
      temp = calculateTemp(&TempData[0]);
      TEST_FAIL_MESSAGE("expect exception to be thrown");
    }
    Catch(ex){
      dumpException(ex);
      TEST_ASSERT_EQUAL(0, temp);
      freeException(ex);
    }
}
