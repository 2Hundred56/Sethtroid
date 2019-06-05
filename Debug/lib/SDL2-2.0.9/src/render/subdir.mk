################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/render/SDL_d3dmath.c \
../lib/SDL2-2.0.9/src/render/SDL_render.c \
../lib/SDL2-2.0.9/src/render/SDL_yuv_sw.c 

OBJS += \
./lib/SDL2-2.0.9/src/render/SDL_d3dmath.o \
./lib/SDL2-2.0.9/src/render/SDL_render.o \
./lib/SDL2-2.0.9/src/render/SDL_yuv_sw.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/render/SDL_d3dmath.d \
./lib/SDL2-2.0.9/src/render/SDL_render.d \
./lib/SDL2-2.0.9/src/render/SDL_yuv_sw.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/render/%.o: ../lib/SDL2-2.0.9/src/render/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


