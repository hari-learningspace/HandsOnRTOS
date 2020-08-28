################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_RTT.c \
C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW.c \
C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.c \
C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Middlewares/SEGGER/SEGGER_RTT.o \
./Middlewares/SEGGER/SEGGER_SYSVIEW.o \
./Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.o \
./Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Middlewares/SEGGER/SEGGER_RTT.d \
./Middlewares/SEGGER/SEGGER_SYSVIEW.d \
./Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.d \
./Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/SEGGER/SEGGER_RTT.o: C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_RTT.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/SEGGER/SEGGER_RTT.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/SEGGER/SEGGER_SYSVIEW.o: C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/SEGGER/SEGGER_SYSVIEW.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.o: C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/SEGGER/SEGGER_SYSVIEW_Config_FreeRTOS.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.o: C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/SEGGER" -I"C:/Users/uidn9556/STM32CubeIDE/workspace_1.4.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/SEGGER/SEGGER_SYSVIEW_FreeRTOS.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

