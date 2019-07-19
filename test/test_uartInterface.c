#include "unity.h"
#include "uartInterface.h"
#include "mock_timer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_uartInterfaceFirstInputWithEnter(void)
{
  //uart.transferCplt indicate whether user already key in enter
  //uart.rxBuffer is for program to read the data
  UART_HandleTypeDef huart1;
  UartInfo uart;
  uart.rxIndx=0;
  //uart.rxBuffer[0]="";
  uart.rxData[0]='a';
  uart.rxData[1]=0;
  uart.transferCplt=false;
  //TEST_ASSERT_EQUAL_STRING("an",uart.rxData);
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(1,uart.rxIndx);
  TEST_ASSERT_EQUAL('a',uart.rxBuffer[0]);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);


  uart.rxData[0]='\r';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,"\r\n",2,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(0,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("a",uart.rxBuffer);
  TEST_ASSERT_EQUAL(true,uart.transferCplt);


  uart.rxData[0]='b';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(1,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("b",uart.rxBuffer);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);
}

void test_interruptWithMultipleKeyWords(void){
  //this test check the data in the struct before user press enter
  //and after user press enter
  UART_HandleTypeDef huart1;
  UartInfo uart;
  uart.rxIndx=0;
  //uart.rxBuffer[0]="";
  uart.rxData[0]='q';
  uart.rxData[1]=0;
  uart.transferCplt=false;
  //TEST_ASSERT_EQUAL_STRING("an",uart.rxData);
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(1,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("q",uart.rxBuffer);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);


  uart.rxData[0]='w';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(2,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("qw",uart.rxBuffer);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);


  uart.rxData[0]='e';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(3,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("qwe",uart.rxBuffer);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);


  uart.rxData[0]='\r';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,"\r\n",2,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(0,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("qwe",uart.rxBuffer);
  TEST_ASSERT_EQUAL(true,uart.transferCplt);


  uart.rxData[0]='r';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,uart.rxData,1,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(1,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("r",uart.rxBuffer);
  TEST_ASSERT_EQUAL(false,uart.transferCplt);
}

void test_interruptWithDoubleEnter(void){
  UART_HandleTypeDef huart1;
  UartInfo uart;
  uart.rxIndx=0;
  uart.transferCplt=false;
  uart.rxData[0]='\r';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,"\r\n",2,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(0,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("",uart.rxBuffer);
  TEST_ASSERT_EQUAL(true,uart.transferCplt);


  uart.rxData[0]='\r';
  uart.rxData[1]=0;
  HAL_UART_Transmit_Expect(&huart1,"\r\n",2,1000);
  HAL_UART_Receive_IT_Expect(&huart1,uart.rxData,1);
  interruptRxTx(&huart1,&uart);
  TEST_ASSERT_EQUAL(0,uart.rxIndx);
  TEST_ASSERT_EQUAL_STRING("",uart.rxBuffer);
  TEST_ASSERT_EQUAL(true,uart.transferCplt);
}
