################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/thread/psp/SDL_syscond.c \
../lib/SDL2-2.0.9/src/thread/psp/SDL_sysmutex.c \
../lib/SDL2-2.0.9/src/thread/psp/SDL_syssem.c \
../lib/SDL2-2.0.9/src/thread/psp/SDL_systhread.c 

OBJS += \
./lib/SDL2-2.0.9/src/thread/psp/SDL_syscond.o \
./lib/SDL2-2.0.9/src/thread/psp/SDL_sysmutex.o \
./lib/SDL2-2.0.9/src/thread/psp/SDL_syssem.o \
./lib/SDL2-2.0.9/src/thread/psp/SDL_systhread.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/thread/psp/SDL_syscond.d \
./lib/SDL2-2.0.9/src/thread/psp/SDL_sysmutex.d \
./lib/SDL2-2.0.9/src/thread/psp/SDL_syssem.d \
./lib/SDL2-2.0.9/src/thread/psp/SDL_systhread.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/thread/psp/%.o: ../lib/SDL2-2.0.9/src/thread/psp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


