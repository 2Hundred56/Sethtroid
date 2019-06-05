################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/raspberry/SDL_rpievents.c \
../lib/SDL2-2.0.9/src/video/raspberry/SDL_rpimouse.c \
../lib/SDL2-2.0.9/src/video/raspberry/SDL_rpiopengles.c \
../lib/SDL2-2.0.9/src/video/raspberry/SDL_rpivideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpievents.o \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpimouse.o \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpiopengles.o \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpivideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpievents.d \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpimouse.d \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpiopengles.d \
./lib/SDL2-2.0.9/src/video/raspberry/SDL_rpivideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/raspberry/%.o: ../lib/SDL2-2.0.9/src/video/raspberry/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


