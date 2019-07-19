#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>
typedef char UART_HandleTypeDef;

void UpdateCCR3(uint32_t CCR3);
void HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

#endif // _TIMER_H
