################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/glew-2.1.0/src/glew.c \
../lib/glew-2.1.0/src/glewinfo.c \
../lib/glew-2.1.0/src/visualinfo.c 

OBJS += \
./lib/glew-2.1.0/src/glew.o \
./lib/glew-2.1.0/src/glewinfo.o \
./lib/glew-2.1.0/src/visualinfo.o 

C_DEPS += \
./lib/glew-2.1.0/src/glew.d \
./lib/glew-2.1.0/src/glewinfo.d \
./lib/glew-2.1.0/src/visualinfo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/glew-2.1.0/src/%.o: ../lib/glew-2.1.0/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


