################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/audio/arts/SDL_artsaudio.c 

OBJS += \
./lib/SDL2-2.0.9/src/audio/arts/SDL_artsaudio.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/audio/arts/SDL_artsaudio.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/audio/arts/%.o: ../lib/SDL2-2.0.9/src/audio/arts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


