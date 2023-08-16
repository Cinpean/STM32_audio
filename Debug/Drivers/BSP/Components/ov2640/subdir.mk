################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/ov2640/ov2640.c 

OBJS += \
./Drivers/BSP/Components/ov2640/ov2640.o 

C_DEPS += \
./Drivers/BSP/Components/ov2640/ov2640.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ov2640/%.o Drivers/BSP/Components/ov2640/%.su: ../Drivers/BSP/Components/ov2640/%.c Drivers/BSP/Components/ov2640/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/BSP/STM324x9I_EVAL -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-ov2640

clean-Drivers-2f-BSP-2f-Components-2f-ov2640:
	-$(RM) ./Drivers/BSP/Components/ov2640/ov2640.d ./Drivers/BSP/Components/ov2640/ov2640.o ./Drivers/BSP/Components/ov2640/ov2640.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-ov2640

