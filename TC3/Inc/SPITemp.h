/*
 * SPITemp.h
 *
 *  Created on: 4 Jul 2019
 *      Author: User
 */

#ifndef SPITEMP_H_
#define SPITEMP_H_


#include <stdint.h>
#include "stm32f1xx_hal.h"

float calculateTemp(uint8_t	*TempData);
float getTemp(SPI_HandleTypeDef *hspi);


#endif /* SPITEMP_H_ */
