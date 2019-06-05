################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SDL2-2.0.9/src/hidapi/libusb/hidusb.cpp 

C_SRCS += \
../lib/SDL2-2.0.9/src/hidapi/libusb/hid.c 

OBJS += \
./lib/SDL2-2.0.9/src/hidapi/libusb/hid.o \
./lib/SDL2-2.0.9/src/hidapi/libusb/hidusb.o 

CPP_DEPS += \
./lib/SDL2-2.0.9/src/hidapi/libusb/hidusb.d 

C_DEPS += \
./lib/SDL2-2.0.9/src/hidapi/libusb/hid.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/hidapi/libusb/%.o: ../lib/SDL2-2.0.9/src/hidapi/libusb/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/SDL2-2.0.9/src/hidapi/libusb/%.o: ../lib/SDL2-2.0.9/src/hidapi/libusb/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


