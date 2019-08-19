/*
 * pulse_math.h
 *
 *  Created on: 27 Jun 2019
 *      Author: User
 */

#ifndef PULSE_MATH_H_
#define PULSE_MATH_H_


#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct{
	uint32_t	firstCCR;
	uint32_t	secondCCR;
	uint32_t	thirdCCR;
	uint32_t	fourthCCR;
	bool		flag;
	bool		triacOnOff
}CCRxData;



void TriacTriggerCallback(CCRxData *ccr3Data);
void config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);

#endif /* PULSE_MATH_H_ */
