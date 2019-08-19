/*
 * timer.c
 *
 *  Created on: Jun 20, 2019
 *      Author: User
 */

#include "timer.h"
/*
void enableTimer2(){
	RCC->APB1RSTR &= ~(1);
	RCC->APB1ENR |= 1;
}
*/
void UpdateCCR3(uint32_t CCR1){
	TIM2->CCR1 = CCR1;
}

void enable_OC3_interrupt(){
	TIM2->DIER &= ~(1<<3);
	TIM2->DIER |= (1<<3);
}

void outputCompareMode(Mode mode){
	TIM2->CCMR1 &=~(7<<4);
	TIM2->CCMR1 |=(mode<<4);
}
