#ifndef _PULSE_MATH_H
#define _PULSE_MATH_H

#include <stdint.h>
typedef struct{
	uint32_t	firstCCR;
	uint32_t	secondCCR;
	uint32_t	thirdCCR;
	uint32_t	fourthCCR;
	uint32_t	flag;
}CCRxData;


void config_pulse(CCRxData *CCR3Data, uint32_t angle, uint32_t width);


#endif // _PULSE_MATH_H
