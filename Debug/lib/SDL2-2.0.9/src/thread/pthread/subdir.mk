################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/thread/pthread/SDL_syscond.c \
../lib/SDL2-2.0.9/src/thread/pthread/SDL_sysmutex.c \
../lib/SDL2-2.0.9/src/thread/pthread/SDL_syssem.c \
../lib/SDL2-2.0.9/src/thread/pthread/SDL_systhread.c \
../lib/SDL2-2.0.9/src/thread/pthread/SDL_systls.c 

OBJS += \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_syscond.o \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_sysmutex.o \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_syssem.o \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_systhread.o \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_systls.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_syscond.d \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_sysmutex.d \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_syssem.d \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_systhread.d \
./lib/SDL2-2.0.9/src/thread/pthread/SDL_systls.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/thread/pthread/%.o: ../lib/SDL2-2.0.9/src/thread/pthread/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


