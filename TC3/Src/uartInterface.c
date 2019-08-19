/*
 * uartInterface.c
 *
 *  Created on: 18 Jul 2019
 *      Author: User
 */


#include "uartInterface.h"

void interruptRxTx(UART_HandleTypeDef *huart, UartInfo *uart){
	uint8_t i;
	if(uart->rxIndx==0){
		for(i=0;i<100;i++)
			uart->rxBuffer[i]=0;	//clear Rx_Buffer before receiving new data
		}
	if(uart->rxData[0]!=13){	//if received data different from ascii 13 (enter)
		uart->transferCplt=false;
		uart->rxBuffer[(uart->rxIndx)++]=uart->rxData[0];
		HAL_UART_Transmit(huart, uart->rxData,1, 1000);
	}
	else{
		//uart->rxBuffer[(uart->rxIndx)++]=uart->rxData[0];//testing
		uart->rxIndx=0;
		uart->transferCplt=true;	//transfer complete, data is ready to read
		HAL_UART_Transmit(huart,"\r\n" ,2, 1000);
	}
	HAL_UART_Receive_IT(huart,uart->rxData,1);
	//activate UART receive interrupt every time
}
