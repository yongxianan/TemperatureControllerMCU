#include "build/temp/_test_uartInterface.c"
#include "mock_timer.h"
#include "uartInterface.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_uartInterfaceFirstInputWithEnter(void)

{





  UART_HandleTypeDef huart1;

  UartInfo uart;

  uart.rxIndx=0;



  uart.rxData[0]='a';

  uart.rxData[1]=0;

  uart.transferCplt=

                   0

                        ;



  HAL_UART_Transmit_CMockExpect(25, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(26, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)(('a')), (UNITY_INT)((uart.rxBuffer[0])), (

 ((void *)0)

 ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='\r';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(35, &huart1, "\r\n", 2, 1000);

  HAL_UART_Receive_IT_CMockExpect(36, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("a")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(39));

  UnityAssertEqualNumber((UNITY_INT)((

 1

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='b';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(45, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(46, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("b")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(49));

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}



void test_interruptWithMultipleKeyWords(void){





  UART_HandleTypeDef huart1;

  UartInfo uart;

  uart.rxIndx=0;



  uart.rxData[0]='q';

  uart.rxData[1]=0;

  uart.transferCplt=

                   0

                        ;



  HAL_UART_Transmit_CMockExpect(64, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(65, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("q")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(68));

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='w';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(74, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(75, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("qw")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(78));

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='e';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(84, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(85, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("qwe")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(88));

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='\r';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(94, &huart1, "\r\n", 2, 1000);

  HAL_UART_Receive_IT_CMockExpect(95, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("qwe")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(98));

  UnityAssertEqualNumber((UNITY_INT)((

 1

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='r';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(104, &huart1, uart.rxData, 1, 1000);

  HAL_UART_Receive_IT_CMockExpect(105, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("r")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(108));

  UnityAssertEqualNumber((UNITY_INT)((

 0

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}



void test_interruptWithDoubleEnter(void){

  UART_HandleTypeDef huart1;

  UartInfo uart;

  uart.rxIndx=0;

  uart.transferCplt=

                   0

                        ;

  uart.rxData[0]='\r';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(119, &huart1, "\r\n", 2, 1000);

  HAL_UART_Receive_IT_CMockExpect(120, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(123));

  UnityAssertEqualNumber((UNITY_INT)((

 1

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);





  uart.rxData[0]='\r';

  uart.rxData[1]=0;

  HAL_UART_Transmit_CMockExpect(129, &huart1, "\r\n", 2, 1000);

  HAL_UART_Receive_IT_CMockExpect(130, &huart1, uart.rxData, 1);

  interruptRxTx(&huart1,&uart);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((uart.rxIndx)), (

 ((void *)0)

 ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualString((const char*)(("")), (const char*)((uart.rxBuffer)), (

 ((void *)0)

 ), (UNITY_UINT)(133));

  UnityAssertEqualNumber((UNITY_INT)((

 1

 )), (UNITY_INT)((uart.transferCplt)), (

 ((void *)0)

 ), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_INT);

}
