/*
 * pulse_math.c
 *
 *  Created on: 27 Jun 2019
 *      Author: User
 */

#include "pulse_math.h"
#include "timer.h"


void TriacTriggerCallback(CCRxData *ccr3Data){
	typedef enum{
		FirstRising,
		FirstFalling,
		SecondRising,
		SecondFalling
	}state;

	static state state1 = FirstRising;

	static uint32_t firstCCR=0;
	static uint32_t secondCCR=0;
	static uint32_t thirdCCR=0;
	static uint32_t fourthCCR=0;

	if(ccr3Data->flag == true && state1==FirstRising){
		firstCCR = ccr3Data->firstCCR;
		secondCCR = ccr3Data->secondCCR;
		thirdCCR = ccr3Data->thirdCCR;
		fourthCCR = ccr3Data->fourthCCR;
		if(ccr3Data->triacOnOff==false){
			outputCompareMode(forcedInactive);
		}
		else{
			outputCompareMode(toggleOnMatch);
		}
		ccr3Data->flag = false;
	}

	switch(state1){
	case FirstRising:
		//CCR3 value is 0 in the beginning
		//load CCR3 = 10000 when CNT reach 32500 or 0
		UpdateCCR3(firstCCR);
		state1 = FirstFalling;
		break;

	case FirstFalling:
		//load CCR3 = 12500 when CNT reach 10000
		UpdateCCR3(secondCCR);
		state1 = SecondRising;
		break;

	case SecondRising:
		//load CCR3 = 30000 when CNT reach 12500
		UpdateCCR3(thirdCCR);
		state1 = SecondFalling;
		break;

	case SecondFalling:
		//load CCR3 = 32500 when CNT reach 30000
		UpdateCCR3(fourthCCR);
		state1=FirstRising;
		break;
	}
}

void config_pulse(CCRxData *ccr3Data, uint32_t firingAngle, uint32_t width){

	if(width>=160){
		width = 160;
	}
	if((firingAngle+width)>=160){
		firingAngle = 160-width;
		ccr3Data->triacOnOff = false;
	}
	else{
		ccr3Data->triacOnOff = true;
	}

	if(ccr3Data->flag == 1){
		//return CCR3Data;
		Error_Handler();
		//throwException(CCR3DATA_FLAG_1,NULL,"ccr3Data->flag == 1, can't config CCR3!");
	}

	ccr3Data->firstCCR = firingAngle*20000/180;
	ccr3Data->secondCCR = (width*20000/180)+(ccr3Data->firstCCR);
	ccr3Data->thirdCCR = (ccr3Data->firstCCR)+20000;
	ccr3Data->fourthCCR = (ccr3Data->secondCCR)+20000;
	ccr3Data->flag = 1;
}



config_pulse_percent(CCRxData *ccr3Data, uint32_t angle, uint32_t width){
	//while(flag == 1){};

	if(angle>=180){
		angle = 180;
	}
	if(width>=100){
		width = 100;
	}
	if(ccr3Data->flag == 1){
		//return CCR3Data;
		Error_Handler();
		//throwException(0,NULL,"CCR3Data->Flag == 1, can't config CCR3!");
	}
	uint32_t WidthLength = 0;
	ccr3Data->firstCCR = angle*20000/180;
	WidthLength = 20000 - (ccr3Data->firstCCR);
	WidthLength = width*WidthLength/100;
	ccr3Data->thirdCCR = (ccr3Data->firstCCR)+20000;
	ccr3Data->secondCCR = (ccr3Data->firstCCR)+WidthLength;
	ccr3Data->fourthCCR = (ccr3Data->thirdCCR)+WidthLength;
	ccr3Data->flag = 1;
}

