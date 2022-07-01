################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ICU.c \
../LCD.c \
../Measure-Distance-Using-Ultrasonic-Sensor.c \
../ULTRASONIC.c \
../gpio.c 

OBJS += \
./ICU.o \
./LCD.o \
./Measure-Distance-Using-Ultrasonic-Sensor.o \
./ULTRASONIC.o \
./gpio.o 

C_DEPS += \
./ICU.d \
./LCD.d \
./Measure-Distance-Using-Ultrasonic-Sensor.d \
./ULTRASONIC.d \
./gpio.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


