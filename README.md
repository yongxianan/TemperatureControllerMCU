IDE code inside TC3

TRIAC Controller Heater with PID Control System
==================================================
list of materials needed for this project:
- TRIAC (control circuit for average current: firing angle)
- Type K Thermocouple
- MAX6675 (for thermocouple)
- STM32F103C8 as programmer (ST-LINK V2)
- stm32f103 V2 smart (MCU)
- 9V transformer
- 2 opto-isolator (MCU & PC protection 4N25 and 4N32)
- comparator LM311

To make STM32 to ST-LINK V2 guide found in link below:
http://slemi.info/2018/08/14/making-your-own-st-link-v2/

zero crossing circuit
----------------------
creating circuit that output (rising edge/falling edge) whenever input signal crossing zero volt. The idea is using caparator to detect input voltage and compare to a reference voltage then give a digital output. in this circuit, comparator output high when V+ higher potential than 0V, output low (0V) when V+ lower potential than 0V.
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/6c3f149e6b140ec704bf604958639c0a/zero_crossing_circuit.png)
(Note that C1 and C2 capacitor change to 100u farrad to power the input of the opto-couple 4N25. D3 and D4 act as rectifier, provide DC to power the comparator) Opto-couple is used for protecting the circuit from high voltage and current, it used for protecting PC and MCU.
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/a0f9433744ea11d844cab38f909e682d/expected_result_from_zero_crossing_circuit.png)
the above image shown the expected output signal when sine wave signal as input. The output result will either have rising edge or falling edge when the input sine wave cross zero volt.


![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/2fb4bd8a27473584e7f5d26a689c9625/actual_result_before_opto-couple.jpg)
Image above shown the signal of sine wave and the opto-couple input signal. there is small distortion signal for opto-couple input signal.


![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d01dab615a0d020cbee4e42/0c9733ff4dc5d4218e970d729a3d15b0/actual_result_after_opto-couple.jpg)
Image above shown the signal of sine wave and the opto-couple output signal. opto-couple output signal range from 0V-3.3V

TRIAC trigger method using Timer in MCU
------------------------------------------
The output compare mode is used for firing TRIAC:
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d09d2f828969932f64ef562/c40675b38a1cc59b268e83d3d170c1e2/output_compare.PNG)

calculation:
- prescaler=36
- internal clock = 72MHz
- after prescaler, timer clock=2MHz=0.5us
- 50Hz=10ms high + 10ms low
- 20000 * 0.25us = 10ms
- 40000 ticks for whole sine wave

![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/8d221dab2403e8a8bfad4d4041985296/image.png)
the zero-crossing circuit will trigger the TI2FP2 pin on MCU everytime AC signal crossing zero. the output compare pin will trigger TRIAC according to TI2FP2 pin and firing angle.

MCU using 1 output compare from timer 2 and interrupt to trigger the TRIAC.
Function that being create:

- void update_CCR3(uint32_t CCR3);

it's function just to update the CCR3 register to implement the next toggle. There are 4 CCR register (CCR1 to CCR4), 4 output compare, depends on which output compare you use. (Note that the actual CCR1 register is being used here because the output compare 3 is change to output compare 1 due to pin location is not suitable.)

- void TriacTriggerCallback(CCRxData *ccr3Data);

it's function that is called at CNT==0 (because CCR3 is 0 in the beginning) and CNT==CCR3. this is the interrupt that toggle the output compare pin, each sine wave will toggle the output compare pin for 4 times. the state machine (4 state due to 4 toggles) is inside this interrupt and it will keep track the state everytime it been called. take counter value from global variables at one particular state in state machine.

- void config_pulse(CCRxData *ccr3Data, uint32_t firingAngle, uint32_t width);

used for config firing angle and pulse width. it will calculate the ticks cycles for toggle timing.

- HAL_TIM_OC_Start_IT(&htim2,TIM_CHANNEL_3); or void enable_OC3_interrupt();

enable interrupt and output compare

test on output compare trigger with firing angle of 90 degree (at 10000 ticks cycles).
the expected delay is 5 ms and the actual delay is 4.8 ms.
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/eaf880669bdd4404538796bc035cf28f/image.png)

the expected time between 2 trigger in a sine wave period is 10ms.
tested result shown the time between 2 trigger is 10.4 ms.
![](https://trello-attachments.s3.amazonaws.com/5cee4d3b0bae3033dfba95f5/5d14633d2cee8e0d3ffca5b1/32053c4d9837c6b72372979c18965319/image.png)
