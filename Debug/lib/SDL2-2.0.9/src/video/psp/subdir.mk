################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/psp/SDL_pspevents.c \
../lib/SDL2-2.0.9/src/video/psp/SDL_pspgl.c \
../lib/SDL2-2.0.9/src/video/psp/SDL_pspmouse.c \
../lib/SDL2-2.0.9/src/video/psp/SDL_pspvideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspevents.o \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspgl.o \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspmouse.o \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspvideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspevents.d \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspgl.d \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspmouse.d \
./lib/SDL2-2.0.9/src/video/psp/SDL_pspvideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/psp/%.o: ../lib/SDL2-2.0.9/src/video/psp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


