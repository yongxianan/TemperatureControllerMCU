#include "uartInterface.h"
#include "unity.h"
#include "mock_timer.h"

void interruptRxTx(UART_HandleTypeDef *huart1, UartInfo *uart){
	uint8_t i;
	if(uart->rxIndx==0){
		for(i=0;i<100;i++)
			uart->rxBuffer[i]=0;	//clear Rx_Buffer before receiving new data
		}
	if(uart->rxData[0]!=13){	//if received data different from ascii 13 (enter)
    uart->transferCplt=false;
    uart->rxBuffer[(uart->rxIndx)++]=uart->rxData[0];
		HAL_UART_Transmit(huart1, uart->rxData,1, 1000);
	}
	else{
		uart->rxIndx=0;
		uart->transferCplt=true;	//transfer complete, data is ready to read
		HAL_UART_Transmit(huart1,"\r\n" ,2, 1000);
	}
	HAL_UART_Receive_IT(huart1,uart->rxData,1);
	//activate UART receive interrupt every time
}
