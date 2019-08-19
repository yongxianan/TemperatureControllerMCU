/*
 * timer.h
 *
 *  Created on: Jun 20, 2019
 *      Author: User
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
//#include "rcc.h"

#define TIMER2_BASE_ADDR		0x40000000
#define TIM2 					((TIMx_REG *)(TIMER2_BASE_ADDR))

typedef struct TIMx_REG TIMx_REG;
struct TIMx_REG {
	volatile uint32_t CR1;				//0h
	volatile uint32_t CR2;				//4h
	volatile uint32_t SMCR;				//8h
	volatile uint32_t DIER;				//ch
	volatile uint32_t SR;				//10h
	volatile uint32_t EGR;				//14h
	volatile uint32_t CCMR1;			//18h
	volatile uint32_t CCMR2;			//1ch
	volatile uint32_t CCER;				//20h
	volatile uint32_t CNT;				//24h
	volatile uint32_t PSC;				//28h
	volatile uint32_t ARR;				//2ch
	volatile uint32_t Reserved0;		//30h
	volatile uint32_t CCR1;				//34h
	volatile uint32_t CCR2;				//38h
	volatile uint32_t CCR3;				//3ch
	volatile uint32_t CCR4;				//40h
	volatile uint32_t Reserved1;		//44h
	volatile uint32_t DCR;				//48h
	volatile uint32_t DMAR;				//4ch

};

typedef enum{
	frozen,
	activeOnMatch,
	inactiveOnMatch,
	toggleOnMatch,
	forcedAction,
	forcedInactive
}Mode;

//void enableTimer2();
void UpdateCCR3(uint32_t CCR3);
void enable_OC3_interrupt();
void outputCompareMode(Mode mode);
#endif /* TIMER_H_ */
