################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/haptic/windows/SDL_dinputhaptic.c \
../lib/SDL2-2.0.9/src/haptic/windows/SDL_windowshaptic.c \
../lib/SDL2-2.0.9/src/haptic/windows/SDL_xinputhaptic.c 

OBJS += \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_dinputhaptic.o \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_windowshaptic.o \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_xinputhaptic.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_dinputhaptic.d \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_windowshaptic.d \
./lib/SDL2-2.0.9/src/haptic/windows/SDL_xinputhaptic.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/haptic/windows/%.o: ../lib/SDL2-2.0.9/src/haptic/windows/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


