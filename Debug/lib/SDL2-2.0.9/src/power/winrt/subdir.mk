################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SDL2-2.0.9/src/power/winrt/SDL_syspower.cpp 

OBJS += \
./lib/SDL2-2.0.9/src/power/winrt/SDL_syspower.o 

CPP_DEPS += \
./lib/SDL2-2.0.9/src/power/winrt/SDL_syspower.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/power/winrt/%.o: ../lib/SDL2-2.0.9/src/power/winrt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


