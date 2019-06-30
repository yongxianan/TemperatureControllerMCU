#ifndef _TRIAC_IT_H
#define _TRIAC_IT_H

#include <stdint.h>
#include <malloc.h>

typedef struct{
	uint32_t	FirstCCR;
	uint32_t	SecondCCR;
	uint32_t	ThirdCCR;
	uint32_t	FourthCCR;
	uint32_t	Flag;
}CCRxData;
void TriacTriggerCallback(CCRxData *CCR3Data);

#endif // _TRIAC_IT_H
