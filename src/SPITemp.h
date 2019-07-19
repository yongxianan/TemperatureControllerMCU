#ifndef _SPITEMP_H
#define _SPITEMP_H

#include <stdint.h>
/*
typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

typedef struct{
  HAL_StatusTypeDef spiStatus;

}
*/
float calculateTemp(uint8_t	*TempData);

#endif // _SPITEMP_H
