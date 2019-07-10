#ifndef _TRIAC_IT_H
#define _TRIAC_IT_H

#include <stdint.h>

typedef struct{
	uint32_t	firstCCR;
	uint32_t	secondCCR;
	uint32_t	thirdCCR;
	uint32_t	fourthCCR;
	uint32_t	flag;
}CCRxData;
void TriacTriggerCallback(CCRxData *CCR3Data);

#endif // _TRIAC_IT_H
