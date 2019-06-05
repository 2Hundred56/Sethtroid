################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirdyn.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirevents.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirframebuffer.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirmouse.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_miropengl.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirvideo.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirvulkan.c \
../lib/SDL2-2.0.9/src/video/mir/SDL_mirwindow.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirdyn.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirevents.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirframebuffer.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirmouse.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_miropengl.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirvideo.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirvulkan.o \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirwindow.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirdyn.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirevents.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirframebuffer.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirmouse.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_miropengl.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirvideo.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirvulkan.d \
./lib/SDL2-2.0.9/src/video/mir/SDL_mirwindow.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/mir/%.o: ../lib/SDL2-2.0.9/src/video/mir/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


