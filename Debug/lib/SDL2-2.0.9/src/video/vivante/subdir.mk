################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteopengles.c \
../lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteplatform.c \
../lib/SDL2-2.0.9/src/video/vivante/SDL_vivantevideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteopengles.o \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteplatform.o \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivantevideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteopengles.d \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivanteplatform.d \
./lib/SDL2-2.0.9/src/video/vivante/SDL_vivantevideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/vivante/%.o: ../lib/SDL2-2.0.9/src/video/vivante/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


