################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/audio/SDL_audio.c \
../lib/SDL2-2.0.9/src/audio/SDL_audiocvt.c \
../lib/SDL2-2.0.9/src/audio/SDL_audiodev.c \
../lib/SDL2-2.0.9/src/audio/SDL_audiotypecvt.c \
../lib/SDL2-2.0.9/src/audio/SDL_mixer.c \
../lib/SDL2-2.0.9/src/audio/SDL_wave.c 

OBJS += \
./lib/SDL2-2.0.9/src/audio/SDL_audio.o \
./lib/SDL2-2.0.9/src/audio/SDL_audiocvt.o \
./lib/SDL2-2.0.9/src/audio/SDL_audiodev.o \
./lib/SDL2-2.0.9/src/audio/SDL_audiotypecvt.o \
./lib/SDL2-2.0.9/src/audio/SDL_mixer.o \
./lib/SDL2-2.0.9/src/audio/SDL_wave.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/audio/SDL_audio.d \
./lib/SDL2-2.0.9/src/audio/SDL_audiocvt.d \
./lib/SDL2-2.0.9/src/audio/SDL_audiodev.d \
./lib/SDL2-2.0.9/src/audio/SDL_audiotypecvt.d \
./lib/SDL2-2.0.9/src/audio/SDL_mixer.d \
./lib/SDL2-2.0.9/src/audio/SDL_wave.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/audio/%.o: ../lib/SDL2-2.0.9/src/audio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


