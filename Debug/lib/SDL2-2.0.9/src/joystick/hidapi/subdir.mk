################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_ps4.c \
../lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_switch.c \
../lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xbox360.c \
../lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xboxone.c \
../lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapijoystick.c 

OBJS += \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_ps4.o \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_switch.o \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xbox360.o \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xboxone.o \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapijoystick.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_ps4.d \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_switch.d \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xbox360.d \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapi_xboxone.d \
./lib/SDL2-2.0.9/src/joystick/hidapi/SDL_hidapijoystick.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/joystick/hidapi/%.o: ../lib/SDL2-2.0.9/src/joystick/hidapi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


