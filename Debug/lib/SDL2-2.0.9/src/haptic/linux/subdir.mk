################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/haptic/linux/SDL_syshaptic.c 

OBJS += \
./lib/SDL2-2.0.9/src/haptic/linux/SDL_syshaptic.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/haptic/linux/SDL_syshaptic.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/haptic/linux/%.o: ../lib/SDL2-2.0.9/src/haptic/linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


