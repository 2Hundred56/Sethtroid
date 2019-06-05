################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/glew-2.1.0/build/conan/test_package/main.c 

OBJS += \
./lib/glew-2.1.0/build/conan/test_package/main.o 

C_DEPS += \
./lib/glew-2.1.0/build/conan/test_package/main.d 


# Each subdirectory must supply rules for building sources it contributes
lib/glew-2.1.0/build/conan/test_package/%.o: ../lib/glew-2.1.0/build/conan/test_package/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


