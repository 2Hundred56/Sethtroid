################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/qnx/gl.c \
../lib/SDL2-2.0.9/src/video/qnx/keyboard.c \
../lib/SDL2-2.0.9/src/video/qnx/video.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/qnx/gl.o \
./lib/SDL2-2.0.9/src/video/qnx/keyboard.o \
./lib/SDL2-2.0.9/src/video/qnx/video.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/qnx/gl.d \
./lib/SDL2-2.0.9/src/video/qnx/keyboard.d \
./lib/SDL2-2.0.9/src/video/qnx/video.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/qnx/%.o: ../lib/SDL2-2.0.9/src/video/qnx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


