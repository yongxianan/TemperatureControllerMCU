/*
 * SPITemp.c
 *
 *  Created on: 4 Jul 2019
 *      Author: User
 */

#include "SPITemp.h"
#include <malloc.h>


float calculateTemp(uint8_t	*TempData)
{
	float temp=0;

	if (TempData[0] & 0x4) {
		Error_Handler();
	}
	else{
		//each point equal to 0.25 celsius
		temp = (float)(((TempData[1]<<5)|(TempData[0]>>3))*0.25);
	}
  return temp;
}

float getTemp(SPI_HandleTypeDef *hspi){
	HAL_StatusTypeDef status;
	uint8_t	TempData[2]={0};
	float temp=0.0;

	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	status = HAL_SPI_Receive(hspi, &TempData[0], 2, 2000);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	temp = calculateTemp(&TempData[0]);

	return temp;
}
