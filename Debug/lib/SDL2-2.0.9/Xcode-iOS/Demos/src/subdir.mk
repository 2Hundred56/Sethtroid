################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/accelerometer.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/common.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/fireworks.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/happy.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/keyboard.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/mixer.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/rectangles.c \
../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/touch.c 

OBJS += \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/accelerometer.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/common.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/fireworks.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/happy.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/keyboard.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/mixer.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/rectangles.o \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/touch.o 

C_DEPS += \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/accelerometer.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/common.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/fireworks.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/happy.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/keyboard.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/mixer.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/rectangles.d \
./lib/SDL2-2.0.9/Xcode-iOS/Demos/src/touch.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/Xcode-iOS/Demos/src/%.o: ../lib/SDL2-2.0.9/Xcode-iOS/Demos/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


