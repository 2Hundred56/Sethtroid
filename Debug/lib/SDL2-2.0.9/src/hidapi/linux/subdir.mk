################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SDL2-2.0.9/src/hidapi/linux/hid.cpp \
../lib/SDL2-2.0.9/src/hidapi/linux/hidraw.cpp 

C_SRCS += \
../lib/SDL2-2.0.9/src/hidapi/linux/hid.c 

OBJS += \
./lib/SDL2-2.0.9/src/hidapi/linux/hid.o \
./lib/SDL2-2.0.9/src/hidapi/linux/hidraw.o 

CPP_DEPS += \
./lib/SDL2-2.0.9/src/hidapi/linux/hid.d \
./lib/SDL2-2.0.9/src/hidapi/linux/hidraw.d 

C_DEPS += \
./lib/SDL2-2.0.9/src/hidapi/linux/hid.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/hidapi/linux/%.o: ../lib/SDL2-2.0.9/src/hidapi/linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/SDL2-2.0.9/src/hidapi/linux/%.o: ../lib/SDL2-2.0.9/src/hidapi/linux/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


