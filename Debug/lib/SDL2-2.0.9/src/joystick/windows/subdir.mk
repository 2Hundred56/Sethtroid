################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/joystick/windows/SDL_dinputjoystick.c \
../lib/SDL2-2.0.9/src/joystick/windows/SDL_mmjoystick.c \
../lib/SDL2-2.0.9/src/joystick/windows/SDL_windowsjoystick.c \
../lib/SDL2-2.0.9/src/joystick/windows/SDL_xinputjoystick.c 

OBJS += \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_dinputjoystick.o \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_mmjoystick.o \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_windowsjoystick.o \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_xinputjoystick.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_dinputjoystick.d \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_mmjoystick.d \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_windowsjoystick.d \
./lib/SDL2-2.0.9/src/joystick/windows/SDL_xinputjoystick.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/joystick/windows/%.o: ../lib/SDL2-2.0.9/src/joystick/windows/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


