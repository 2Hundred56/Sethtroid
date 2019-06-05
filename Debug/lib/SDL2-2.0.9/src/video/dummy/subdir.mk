################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/dummy/SDL_nullevents.c \
../lib/SDL2-2.0.9/src/video/dummy/SDL_nullframebuffer.c \
../lib/SDL2-2.0.9/src/video/dummy/SDL_nullvideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullevents.o \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullframebuffer.o \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullvideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullevents.d \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullframebuffer.d \
./lib/SDL2-2.0.9/src/video/dummy/SDL_nullvideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/dummy/%.o: ../lib/SDL2-2.0.9/src/video/dummy/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


