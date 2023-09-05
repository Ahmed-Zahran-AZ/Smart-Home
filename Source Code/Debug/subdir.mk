################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prg.c \
../DTEST.c \
../Internal_EEPROM.c \
../KPD.c \
../LCD.c \
../main.c \
../motor.c 

OBJS += \
./DIO_Prg.o \
./DTEST.o \
./Internal_EEPROM.o \
./KPD.o \
./LCD.o \
./main.o \
./motor.o 

C_DEPS += \
./DIO_Prg.d \
./DTEST.d \
./Internal_EEPROM.d \
./KPD.d \
./LCD.d \
./main.d \
./motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


