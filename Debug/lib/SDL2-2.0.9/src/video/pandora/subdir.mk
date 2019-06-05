################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/pandora/SDL_pandora.c \
../lib/SDL2-2.0.9/src/video/pandora/SDL_pandora_events.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/pandora/SDL_pandora.o \
./lib/SDL2-2.0.9/src/video/pandora/SDL_pandora_events.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/pandora/SDL_pandora.d \
./lib/SDL2-2.0.9/src/video/pandora/SDL_pandora_events.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/pandora/%.o: ../lib/SDL2-2.0.9/src/video/pandora/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


