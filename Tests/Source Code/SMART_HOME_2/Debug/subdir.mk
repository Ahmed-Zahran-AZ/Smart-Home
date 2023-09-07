################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AC_TempSens.c \
../ADC.c \
../DIO_Prg.c \
../LCD.c \
../Timer1.c \
../UART.c \
../UART_PROJ.c \
../main.c 

OBJS += \
./AC_TempSens.o \
./ADC.o \
./DIO_Prg.o \
./LCD.o \
./Timer1.o \
./UART.o \
./UART_PROJ.o \
./main.o 

C_DEPS += \
./AC_TempSens.d \
./ADC.d \
./DIO_Prg.d \
./LCD.d \
./Timer1.d \
./UART.d \
./UART_PROJ.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


