################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/yuv2rgb/yuv_rgb.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/yuv2rgb/yuv_rgb.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/yuv2rgb/yuv_rgb.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/yuv2rgb/%.o: ../lib/SDL2-2.0.9/src/video/yuv2rgb/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


