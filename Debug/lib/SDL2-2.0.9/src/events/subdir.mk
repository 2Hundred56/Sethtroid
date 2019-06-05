################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/events/SDL_clipboardevents.c \
../lib/SDL2-2.0.9/src/events/SDL_displayevents.c \
../lib/SDL2-2.0.9/src/events/SDL_dropevents.c \
../lib/SDL2-2.0.9/src/events/SDL_events.c \
../lib/SDL2-2.0.9/src/events/SDL_gesture.c \
../lib/SDL2-2.0.9/src/events/SDL_keyboard.c \
../lib/SDL2-2.0.9/src/events/SDL_mouse.c \
../lib/SDL2-2.0.9/src/events/SDL_quit.c \
../lib/SDL2-2.0.9/src/events/SDL_touch.c \
../lib/SDL2-2.0.9/src/events/SDL_windowevents.c 

OBJS += \
./lib/SDL2-2.0.9/src/events/SDL_clipboardevents.o \
./lib/SDL2-2.0.9/src/events/SDL_displayevents.o \
./lib/SDL2-2.0.9/src/events/SDL_dropevents.o \
./lib/SDL2-2.0.9/src/events/SDL_events.o \
./lib/SDL2-2.0.9/src/events/SDL_gesture.o \
./lib/SDL2-2.0.9/src/events/SDL_keyboard.o \
./lib/SDL2-2.0.9/src/events/SDL_mouse.o \
./lib/SDL2-2.0.9/src/events/SDL_quit.o \
./lib/SDL2-2.0.9/src/events/SDL_touch.o \
./lib/SDL2-2.0.9/src/events/SDL_windowevents.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/events/SDL_clipboardevents.d \
./lib/SDL2-2.0.9/src/events/SDL_displayevents.d \
./lib/SDL2-2.0.9/src/events/SDL_dropevents.d \
./lib/SDL2-2.0.9/src/events/SDL_events.d \
./lib/SDL2-2.0.9/src/events/SDL_gesture.d \
./lib/SDL2-2.0.9/src/events/SDL_keyboard.d \
./lib/SDL2-2.0.9/src/events/SDL_mouse.d \
./lib/SDL2-2.0.9/src/events/SDL_quit.d \
./lib/SDL2-2.0.9/src/events/SDL_touch.d \
./lib/SDL2-2.0.9/src/events/SDL_windowevents.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/events/%.o: ../lib/SDL2-2.0.9/src/events/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


