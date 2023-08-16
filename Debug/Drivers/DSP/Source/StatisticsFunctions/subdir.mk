################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.c \
../Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.c 

OBJS += \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.o \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.o 

C_DEPS += \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.d \
./Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DSP/Source/StatisticsFunctions/%.o Drivers/DSP/Source/StatisticsFunctions/%.su: ../Drivers/DSP/Source/StatisticsFunctions/%.c Drivers/DSP/Source/StatisticsFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/DSP -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-DSP-2f-Source-2f-StatisticsFunctions

clean-Drivers-2f-DSP-2f-Source-2f-StatisticsFunctions:
	-$(RM) ./Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_max_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.d ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.o ./Drivers/DSP/Source/StatisticsFunctions/arm_max_q7.su ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.d ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.o ./Drivers/DSP/Source/StatisticsFunctions/arm_mean_q7.su ./Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_min_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.d ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.o ./Drivers/DSP/Source/StatisticsFunctions/arm_min_q7.su ./Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_power_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.d ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.o ./Drivers/DSP/Source/StatisticsFunctions/arm_power_q7.su ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_rms_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_std_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_std_q31.su ./Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.d ./Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.o ./Drivers/DSP/Source/StatisticsFunctions/arm_var_f32.su ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.d ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.o ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q15.su ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.d ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.o ./Drivers/DSP/Source/StatisticsFunctions/arm_var_q31.su

.PHONY: clean-Drivers-2f-DSP-2f-Source-2f-StatisticsFunctions

