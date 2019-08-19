################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/SPITemp.c \
../Src/main.c \
../Src/pidMath.c \
../Src/pulse_math.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f1xx.c \
../Src/timer.c \
../Src/uartInterface.c 

OBJS += \
./Src/SPITemp.o \
./Src/main.o \
./Src/pidMath.o \
./Src/pulse_math.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f1xx.o \
./Src/timer.o \
./Src/uartInterface.o 

C_DEPS += \
./Src/SPITemp.d \
./Src/main.d \
./Src/pidMath.d \
./Src/pulse_math.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f1xx.d \
./Src/timer.d \
./Src/uartInterface.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/User/Desktop/BAME3114/TC3/Inc" -I"C:/Users/User/Desktop/BAME3114/TC3/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/User/Desktop/BAME3114/TC3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/User/Desktop/BAME3114/TC3/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/User/Desktop/BAME3114/TC3/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


