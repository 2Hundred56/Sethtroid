################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SMB1/Mario.cpp 

OBJS += \
./src/SMB1/Mario.o 

CPP_DEPS += \
./src/SMB1/Mario.d 


# Each subdirectory must supply rules for building sources it contributes
src/SMB1/%.o: ../src/SMB1/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -w -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


