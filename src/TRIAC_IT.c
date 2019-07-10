#include "TRIAC_IT.h"
#include "unity.h"
#include <stdlib.h>
#include <stdio.h>
#include "mock_timer.h"
//#include "pulse_math.h"



void TriacTriggerCallback(CCRxData *ccr3Data){
	uint32_t pulse=0;

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

	if(ccr3Data->flag == 1 && state1==FirstRising){
		firstCCR = ccr3Data->firstCCR;
		secondCCR = ccr3Data->secondCCR;
		thirdCCR = ccr3Data->thirdCCR;
		fourthCCR = ccr3Data->fourthCCR;
		ccr3Data->flag = 0;
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
