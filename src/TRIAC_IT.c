#include "TRIAC_IT.h"
#include "unity.h"
#include <stdlib.h>
#include <stdio.h>
//#include "pulse_math.h"



void TriacTriggerCallback(CCRxData *CCR3Data){
	uint32_t pulse=0;

	typedef enum{
		FirstRising,
		FirstFalling,
		SecondRising,
		SecondFalling
	}state;

	static state state1 = FirstRising;

	static uint32_t FirstCCR=0;
  static uint32_t SecondCCR=0;
  static uint32_t ThirdCCR=0;
  static uint32_t FourthCCR=0;

	if(CCR3Data->Flag == 1 && state1==FirstRising){
		FirstCCR = CCR3Data->FirstCCR;
		SecondCCR = CCR3Data->SecondCCR;
		ThirdCCR = CCR3Data->ThirdCCR;
		FourthCCR = CCR3Data->FourthCCR;
		CCR3Data->Flag = 0;
	}

	switch(state1){
	case FirstRising:
		//CCR3 value is 0 in the beginning
		//load CCR3 = 10000 when CNT reach 32500 or 0
		UpdateCCR3(FirstCCR);
		state1 = FirstFalling;
		break;

	case FirstFalling:
		//load CCR3 = 12500 when CNT reach 10000
		UpdateCCR3(SecondCCR);
		state1 = SecondRising;
		break;

	case SecondRising:
		//load CCR3 = 30000 when CNT reach 12500
		UpdateCCR3(ThirdCCR);
		state1 = SecondFalling;
		break;

	case SecondFalling:
		//load CCR3 = 32500 when CNT reach 30000
		UpdateCCR3(FourthCCR);
		state1=FirstRising;
		break;
	}
}
