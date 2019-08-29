IDE code inside TC3
-------------------------

TRIAC Controller Heater with PID Control System
==================================================
description
--------------------------------------------------
this project use STM32F103C8T6 develop a heating system with PID cotroller, it allows user to set target temperature using the command line interface through the UART communication with PC. Temperature is measure and feedback using Serial Peripheral Interface through MAX6675 K-thermocouple to Digital Converter and K-type thermocouple. The PID algorithm is program inside the microcontroller to control the temperature to a desired temperature. TRIAC is used by microcontroller to control the power delivered to the light bulb (act as a heater). this project can be used in oven for control temperature and other purpose.

list of materials needed for this project:
- TRIAC (control circuit for average current: firing angle)
- Type K Thermocouple
- MAX6675 (for thermocouple)
- STM32F103C8 as programmer (ST-LINK V2)
- stm32f103 V2 smart (MCU)
- 9V transformer
- opto-isolator 4N25 (use in zero crossing circuit for circuit protection)
- opto-isolator 4N32 (use in TRIAC trigger circuit protection)
- comparator LM311N

![cubeMX](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d6635a35e7d6a2314944608/715c9a5de9ec29bd087244b04fb93d8b/image.png)
![whole circuit diagram](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5cef7f7b1654da1f2d773907/55367768f98557726fac2e35d85fccb6/wholeDiagram.PNG)
<h6>Figure 1 : the whole setup circuit diagram and cubeMX pins configuration.

In fig 1, STM32F103C8T6 use as a programmer for the STM32F103 V2 SMART, STM32F103C8T6 is flash to ST-LINK. 9V transformer provide power for zero crossing circuit and also for zero crossing detection. TRIAC triggering circuit is used for controlling power deliver to the lamp. MAX 6675 with K-type thermocouple is used for temperature feedback from the light bulb. The USB TO TTL is used for communication through the UART to the PC, it allows user to set desired temperature and read actual temperature from light bulb.

zero crossing circuit
----------------------
creating circuit that output (rising edge/falling edge) whenever input signal crossing zero volt. The idea is using caparator to detect input voltage and compare to a reference voltage then give a digital output. in this circuit, comparator output high when V+ higher potential than 0V, output low (0V) when V+ lower potential than 0V.

![zero crossing circuit](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/32897f1bd7d5a39010b1fb5553a9e847/image.png)
<h6>Figure 2 : zero crossing circuit

(Note that D3 and D4 act as rectifier, provide DC to power the comparator) Opto-couple is used for protecting the circuit from high voltage and current, it used for protecting PC and MCU. From Figure 2, expected output signal (channel B range from 0 - 3.3 V) in oscilloscope when 9 Vrms sine wave signal as input (channel A). The output result will either have rising edge or falling edge when the input sine wave cross zero volt. when the input voltage near 0V (channel A), channel B voltage already rise to 2.874 V, then able reach 3.3 V.

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/48656ec15a5fe8f167287848f5ee5d28/image.png)
<h6>Figure 3 : zero crossing signal and input signal (sine wave)
Figure 3 shown that it take 96.7 us for output signal (channel B) to reach 3.187 V when the input signal cross zero volt (channel A) in simulation program.


![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/2fb4bd8a27473584e7f5d26a689c9625/actual_result_before_opto-couple.jpg)
<h6>Figure 4 : zero crossing signal (opto-couple input signal) and input signal (sine wave).
Figure 4 shown there is small distortion signal for opto-couple input signal.


![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/0c9733ff4dc5d4218e970d729a3d15b0/actual_result_after_opto-couple.jpg)
<h6>Figure 5 :  sine wave signal as input and the opto-couple output signal range from 0V-3.3V

TRIAC trigger method using Timer in MCU
-------------------------------------------------
The TRIAC triggering is done by using output compare pin on MCU with output compare mode in timer 2, MCU detect the zero crossing in sine wave, then control the timing for triggering.

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d09d2f828969932f64ef562/c40675b38a1cc59b268e83d3d170c1e2/output_compare.PNG)
<h6>Figure 6 : output compare mode from manual

calculation:
- prescaler=36
- internal clock = 72MHz
- after prescaler, timer clock=2MHz=0.5us
- 50Hz=10ms high + 10ms low
- 20000 * 0.25us = 10ms
- 40000 ticks for whole sine wave

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/8d221dab2403e8a8bfad4d4041985296/image.png)
<h6>Figure 7 : timer block diagram.
the zero-crossing circuit will trigger the TI2FP2 pin on MCU everytime AC signal crossing zero, TI2FP2 reset the timer 2 counter back to zero. the output compare pin will trigger TRIAC according to TI2FP2 pin and firing angle, it also update the next output compare trigger timing (next CCR tick cycle).

MCU using 1 output compare from timer 2 and interrupt to trigger the TRIAC.
Function that being create:

- void update_CCR3(uint32_t CCR1);

it's function just to update the CCR1 register to implement the next toggle. There are 4 CCR register (CCR1 to CCR4), 4 output compare, depends on which output compare you use. (Note that the actual CCR1 register is being used here because the output compare 3 is change to output compare 1 due to pin location is not suitable.)

- void TriacTriggerCallback(CCRxData *ccr3Data);

it's function that is called at CNT==0 (because CCR3 is 0 in the beginning) and CNT==CCR3. this is the interrupt that toggle the output compare pin, each sine wave will toggle the output compare pin for 4 times. the state machine (4 state due to 4 toggles) is inside this interrupt and it will keep track the state everytime it been called. take counter value from global variables at one particular state in state machine.

- void config_pulse(CCRxData *ccr3Data, uint32_t firingAngle, uint32_t width);

used for config firing angle and pulse width. it will calculate and set the ticks cycles for toggle timing.

- HAL_TIM_OC_Start_IT(&htim2,TIM_CHANNEL_1); 

enable interrupt and output compare

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/eaf880669bdd4404538796bc035cf28f/image.png)
<h6>Figure 8 : test on output compare trigger (channel 1) with firing angle of 90 degree (at 10000 ticks cycles). the expected delay is 5 ms and the actual delay is 4.8 ms.

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/32053c4d9837c6b72372979c18965319/image.png)
<h6>Figure 9 : the expected time between 2 trigger (channel 1) in a sine wave period is 10ms. tested result shown the time between 2 trigger is 10.4 ms.  channel 2 is signal from zero crossing circuit.

TRIAC triggering circuit
--------------------------------
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d5e7ad3cf99c38ba6c7ca49/15b85bfef3fb9b0da956dd4dfb6e749d/image.png)
<h6>Figure 10 : using negative G- to trigger, second and third quadrant used. (50-60 mA)

positive trigger has been trigger (first and fourth quadrant 50-100 mA) on the gate, there is visible delay display in oscilloscope when using positive trigger on the gate, the negative trigger found no delay from oscilloscope. 
![negative trigger triac circuit](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d5e7ad3cf99c38ba6c7ca49/ecdb6e1e8eafdeaad8879beaca901b43/image.png)
<h6>Figure 11 : negative trigger TRIAC circuit with the lamp shown, the MCU is connect to U1 opto-coupler. this circuit being used in this project.


    config_pulse(&ccr3Data,i,40);
	  if(resetState==false)
		  i++;
	  else
		  i--;

	  if(i>=150)
		  resetState=true;
	  else if(i<=0)
		  resetState=false;
     
     HAL_Delay(500);
<h6>Figure 12 : there is testing for different firing angle for TRIAC circuit using this code.

a test from 0 to 150 degree firing angle and 150 to 0 degree firing angle, change (minus or add) the firing angle every 500ms using HAL_Delay.
in the test, the (pulse width + firing angle won't exceed 165) because it may accidentally firing the next 180 degree sine wave, it only detect the rising edge from zero crossing circuit.
testing video : https://youtu.be/LwTu69IMxX0

UART communication between MUC and PC
--------------------------------------------------------
MCU send data to PC using HAL function:

- HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)

MCU receive data from PC using interrupt, this function will be called by interrupt:

-void interruptRxTx(UART_HandleTypeDef *huart, UartInfo *uart);

the function will store each character into a buffer, other function only able to read this buffer if this interrupt function receive a "enter" from user. it also send back each character to PC when user is typing to the console for UART, so that the console feedback to user whether user got key in characters correctly.

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d2846e69c76246ef5c855ee/653cd236ce6cdd6958f1953bd86e8952/sending_data_from_PC_to_MCU_(uart)_%26_tdd.png)
<h6>Figure 13 : when user key in "start" and enter, it show the temperature data, it wait until user key in enter to stop it. User can set target temperature with "set temp". it will ignore other commands that are not recognize by the MCU. the time is get from HAL_GetTick function.

read temperature from sensor
----------------------------------
the diagram for connection is in figure 1.
the get temperature function prototype:

- float getTemp(SPI_HandleTypeDef *hspi);
this function use full duplex mode to receive data from MAX 6675 (with K-type thermocouple), it will return temperature reading with the resolution of 0.25 degree celsius. this function also use another function:

- float calculateTemp(uint8_t	*TempData)

to decode the 16 bit data from MAX6675.

![display get time and temp](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d26ba9d084d9846ffd95d3e/4f6c1e98b7b58eee85353c2dc075363b/uart_communication_(receive_from_MCU)_and_test_getTemp_and_getTime.png)
<h6>Figure 14 : testing for the getTemp function.

PID function
-------------------------
the PID function prototype:

- int findPIDValue(PidInfo *pidInfo, double actualTemp, uint32_t currentTime);

this function input parameter are the (actualTemp) temperature reading from thermocouple, a set temperature from user. pidInfo hold the PID constant which is Kp, Ki and Kd can be set by user, it also hold other information that are require for calculate firing angle value. this function will return the firing angle value to control temperature.

testing the MCU with set temperature to calibrate the Ki, Kp and Kd values.
---------------------------------------------------------------------------------------
PID constant is set with this method:
First set Kp, Ki, Kd to zero.
Increase Kp slowly until the temperature start oscillating, it is because this oscillation show that it can provide immediate responds that is quick enough when the environment change suddenly. when Kp too low, PID have not control if the environment temperature suddenly change a lot, for example you might not want the actual temperature stay above set point for too long. (Note that it may oscillate under the setpoint which is fine because the integrate value will increase and shift the whole oscillation up to reach the set point.)
for Ki this have to judge by experience because if the Ki value is too large, it will tune it's integrate value within large integrate value (for example -500 to 500) which will not stabilize the integrate value to certain firing angle. if too small, it can take too long to stabilize to certain firing angle. increase Kd to increase stability (reduce overshoot). 

Kp and Ki is tune in first few attempt. Kd set to zero at the moment.
link to the testing demo for Kp=10, Ki=0.2, Kd=0:
https://youtu.be/iyvu84LFajU

new testing for Kp=10, Ki=0.2, Kd=0.5. this test is more complete.
https://youtu.be/2ljTTxVdJQo

Reference:
-----------------
4N25, 4N26, 4N27, 4N28 from Vishay Semiconductors. (n.d.). Retrieved from https://www.vishay.com/docs/83725/4n25.pdf

Texas instruments. (n.d.). LM111, LM211, LM311 Differential Comparators. Retrieved from http://www.ti.com/lit/ds/symlink/lm211.pdf

ST. (n.d.). STM32F103xx Reference manual. Retrieved from https://www.st.com/content/ccc/resource/technical/document/reference_manual/59/b9/ba/7f/11/af/43/d5/CD00171190.pdf/files/CD00171190.pdf/jcr:content/translations/en.CD00171190.pdf

Learnabout Electronics. (n.d.). Retrieved from http://www.learnabout-electronics.org/Semiconductors/thyristors_63.php

2N3904 datasheet. (n.d.). Retrieved from https://www.onsemi.com/pub/Collateral/2N3903-D.PDF

2N3906 datasheet. (n.d.). Retrieved from https://www.onsemi.com/pub/Collateral/2N3906-D.PDF

BTA16 datasheet. (n.d.). Retrieved from https://my.mouser.com/datasheet/2/389/bta16-954517.pdf

BTA16-600B datasheet. (n.d.). Retrieved from http://download.maritex.com.pl/pdfs/sc/BTA16-600B.pdf

MAX6675 Cold-Junction-Compensated K-Thermocoupleto-Digital Converter (0°C to 1024°C). (n.d.). Retrieved from https://datasheets.maximintegrated.com/en/ds/MAX6675.pdf

How Does a PID Controller Work? - Structure & Tuning Methods. (2018, November 10). Retrieved from https://www.elprocus.com/the-working-of-a-pid-controller/
