#include "SPITemp.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

int calculateTemp(uint8_t	*TempData)
{
	int temp=0;

	if (TempData[0] & 0x4) {
		throwException(THERMOCOUPLE_INPUT_OPEN,NULL,"bit 2 = 1, thermocouple input is open.");
	}
	else{
		//each point equal to 0.25 celsius
    //data is store from bit 14 - bit 3
		temp = (int)(((TempData[1]<<5)|(TempData[0]>>3))*0.25);
	}
  return temp;
}
