################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/STM32L476xx_GPIO_DRIVER.c 

OBJS += \
./Drivers/Src/STM32L476xx_GPIO_DRIVER.o 

C_DEPS += \
./Drivers/Src/STM32L476xx_GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L4 -DSTM32 -DNUCLEO_L476RG -DSTM32L476RGTx -c -I../Inc -I"C:/Users/ABU SAYED/Desktop/MCU/DriverLayer/DriveLayerAPI/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/STM32L476xx_GPIO_DRIVER.d ./Drivers/Src/STM32L476xx_GPIO_DRIVER.o ./Drivers/Src/STM32L476xx_GPIO_DRIVER.su

.PHONY: clean-Drivers-2f-Src

