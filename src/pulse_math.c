#include "pulse_math.h"


CCRxData *config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width){
	//while(flag == 1){};

	if(angle>=180){
		angle = 180;
	}
	if(width>=100){
		width = 100;
	}
	if(CCR3Data->Flag == 1){
		//return CCR3Data;
		throwException(0,NULL,"CCR3Data->Flag == 1, can't config CCR3!");
	}
	uint32_t WidthLength = 0;
	CCR3Data->FirstCCR = angle*20000/180;
	WidthLength = 20000 - (CCR3Data->FirstCCR);
	WidthLength = width*WidthLength/100;
	CCR3Data->ThirdCCR = (CCR3Data->FirstCCR)+20000;
	CCR3Data->SecondCCR = (CCR3Data->FirstCCR)+WidthLength;
	CCR3Data->FourthCCR = (CCR3Data->ThirdCCR)+WidthLength;
	CCR3Data->Flag = 1;

	return CCR3Data;
}
