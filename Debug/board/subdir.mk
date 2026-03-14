################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_K32L2B31VLH0A -DCPU_K32L2B31VLH0A_cm0plus -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\board" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\source" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\drivers" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\utilities\str" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\component\serial_manager" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\CMSIS" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\CMSIS\m-profile" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\device" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\component\lists" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\component\uart" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\utilities\debug_console" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\device\periph2" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\utilities\debug_console\config" -I"C:\Users\elmes\Documents\MCUXpressoIDE_25.6.136\workspace\Video_0_Clock_Register_LED\utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

