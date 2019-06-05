################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/android/SDL_androidclipboard.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidevents.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidgl.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidkeyboard.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidmessagebox.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidmouse.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidtouch.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidvideo.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidvulkan.c \
../lib/SDL2-2.0.9/src/video/android/SDL_androidwindow.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/android/SDL_androidclipboard.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidevents.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidgl.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidkeyboard.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidmessagebox.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidmouse.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidtouch.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidvideo.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidvulkan.o \
./lib/SDL2-2.0.9/src/video/android/SDL_androidwindow.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/android/SDL_androidclipboard.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidevents.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidgl.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidkeyboard.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidmessagebox.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidmouse.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidtouch.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidvideo.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidvulkan.d \
./lib/SDL2-2.0.9/src/video/android/SDL_androidwindow.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/android/%.o: ../lib/SDL2-2.0.9/src/video/android/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


