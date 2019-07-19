#ifndef _UARTINTERFACE_H
#define _UARTINTERFACE_H


#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct{
	uint8_t rxIndx;
	char rxBuffer[100];
	char rxData[2];
	bool transferCplt;
}UartInfo;

typedef char UART_HandleTypeDef;

void interruptRxTx(UART_HandleTypeDef *huart1, UartInfo *uart);


#endif // _UARTINTERFACE_H
