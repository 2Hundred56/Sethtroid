################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.c 

OBJS += \
./lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.o 

C_DEPS += \
./lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.o: ../lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"lib/SDL2-2.0.9/Xcode-iOS/Template/SDL iOS Application/main.d" -MT"lib/SDL2-2.0.9/Xcode-iOS/Template/SDL\ iOS\ Application/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


