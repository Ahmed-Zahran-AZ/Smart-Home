################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prg.c \
../EEPROM.c \
../EXT_EE_DOOR_TEST.c \
../I2c.c \
../KPD.c \
../LCD.c \
../main.c \
../motor.c 

OBJS += \
./DIO_Prg.o \
./EEPROM.o \
./EXT_EE_DOOR_TEST.o \
./I2c.o \
./KPD.o \
./LCD.o \
./main.o \
./motor.o 

C_DEPS += \
./DIO_Prg.d \
./EEPROM.d \
./EXT_EE_DOOR_TEST.d \
./I2c.d \
./KPD.d \
./LCD.d \
./main.d \
./motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


