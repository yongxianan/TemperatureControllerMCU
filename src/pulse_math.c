#include "pulse_math.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"

void config_pulse(CCRxData *ccr3Data, uint32_t firingAngle, uint32_t width){
	//while(flag == 1){};

	if(firingAngle>=180){
		firingAngle = 180;
	}
	if((firingAngle+width)>=180){
		width = 180-firingAngle;
	}
	if(ccr3Data->flag == 1){
		//return CCR3Data;
		throwException(CCR3DATA_FLAG_1,NULL,"ccr3Data->flag == 1, can't config CCR3!");
	}

	ccr3Data->firstCCR = firingAngle*20000/180;
	ccr3Data->secondCCR = (width*20000/180)+(ccr3Data->firstCCR);
	ccr3Data->thirdCCR = (ccr3Data->firstCCR)+20000;
	ccr3Data->fourthCCR = (ccr3Data->secondCCR)+20000;
	ccr3Data->flag = 1;
}
