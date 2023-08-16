################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MedianFilter.c \
../Core/Src/WM8994.c \
../Core/Src/adc.c \
../Core/Src/dma.c \
../Core/Src/dma2d.c \
../Core/Src/fmc.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/ltdc.c \
../Core/Src/main.c \
../Core/Src/sai.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/MedianFilter.o \
./Core/Src/WM8994.o \
./Core/Src/adc.o \
./Core/Src/dma.o \
./Core/Src/dma2d.o \
./Core/Src/fmc.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/ltdc.o \
./Core/Src/main.o \
./Core/Src/sai.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/MedianFilter.d \
./Core/Src/WM8994.d \
./Core/Src/adc.d \
./Core/Src/dma.d \
./Core/Src/dma2d.d \
./Core/Src/fmc.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/ltdc.d \
./Core/Src/main.d \
./Core/Src/sai.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/BSP/STM324x9I_EVAL -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/MedianFilter.d ./Core/Src/MedianFilter.o ./Core/Src/MedianFilter.su ./Core/Src/WM8994.d ./Core/Src/WM8994.o ./Core/Src/WM8994.su ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/dma2d.d ./Core/Src/dma2d.o ./Core/Src/dma2d.su ./Core/Src/fmc.d ./Core/Src/fmc.o ./Core/Src/fmc.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/ltdc.d ./Core/Src/ltdc.o ./Core/Src/ltdc.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/sai.d ./Core/Src/sai.o ./Core/Src/sai.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

