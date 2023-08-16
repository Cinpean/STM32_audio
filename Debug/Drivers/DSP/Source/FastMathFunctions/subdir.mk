################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.c \
../Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.c \
../Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.c \
../Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.c \
../Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.c \
../Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.c \
../Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.c \
../Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.o \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.o \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.o \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.o \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.o \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.o \
./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.o \
./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.d \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.d \
./Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.d \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.d \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.d \
./Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.d \
./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.d \
./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/Source/FastMathFunctions/%.o Drivers/DSP/Source/FastMathFunctions/%.su: ../Drivers/DSP/Source/FastMathFunctions/%.c Drivers/DSP/Source/FastMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-DSP-2f-Source-2f-FastMathFunctions

clean-Drivers-2f-DSP-2f-Source-2f-FastMathFunctions:
	-$(RM) ./Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.d ./Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.o ./Drivers/DSP/Source/FastMathFunctions/arm_cos_f32.su ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.d ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.o ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q15.su ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.d ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.o ./Drivers/DSP/Source/FastMathFunctions/arm_cos_q31.su ./Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.d ./Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.o ./Drivers/DSP/Source/FastMathFunctions/arm_sin_f32.su ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.d ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.o ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q15.su ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.d ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.o ./Drivers/DSP/Source/FastMathFunctions/arm_sin_q31.su ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.d ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.o ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q15.su ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.d ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.o ./Drivers/DSP/Source/FastMathFunctions/arm_sqrt_q31.su

.PHONY: clean-Drivers-2f-DSP-2f-Source-2f-FastMathFunctions

