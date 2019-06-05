################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/SDL.c \
../lib/SDL2-2.0.9/src/SDL_assert.c \
../lib/SDL2-2.0.9/src/SDL_dataqueue.c \
../lib/SDL2-2.0.9/src/SDL_error.c \
../lib/SDL2-2.0.9/src/SDL_hints.c \
../lib/SDL2-2.0.9/src/SDL_log.c 

OBJS += \
./lib/SDL2-2.0.9/src/SDL.o \
./lib/SDL2-2.0.9/src/SDL_assert.o \
./lib/SDL2-2.0.9/src/SDL_dataqueue.o \
./lib/SDL2-2.0.9/src/SDL_error.o \
./lib/SDL2-2.0.9/src/SDL_hints.o \
./lib/SDL2-2.0.9/src/SDL_log.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/SDL.d \
./lib/SDL2-2.0.9/src/SDL_assert.d \
./lib/SDL2-2.0.9/src/SDL_dataqueue.d \
./lib/SDL2-2.0.9/src/SDL_error.d \
./lib/SDL2-2.0.9/src/SDL_hints.d \
./lib/SDL2-2.0.9/src/SDL_log.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/%.o: ../lib/SDL2-2.0.9/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


