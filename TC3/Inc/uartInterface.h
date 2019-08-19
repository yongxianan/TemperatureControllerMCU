/*
 * uartInterface.h
 *
 *  Created on: 18 Jul 2019
 *      Author: User
 */

#ifndef UARTINTERFACE_H_
#define UARTINTERFACE_H_

#include <string.h>
#include "stm32f1xx_hal.h"
#include <stdbool.h>


typedef struct{
	uint8_t rxIndx;
	char rxBuffer[100];
	char rxData[2];
	bool transferCplt;
}UartInfo;


void interruptRxTx(UART_HandleTypeDef *huart1, UartInfo *uart);

#endif /* UARTINTERFACE_H_ */
