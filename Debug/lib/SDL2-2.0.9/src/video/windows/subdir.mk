################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsclipboard.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsevents.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsframebuffer.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowskeyboard.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsmessagebox.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsmodes.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsmouse.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengl.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengles.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsshape.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsvideo.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowsvulkan.c \
../lib/SDL2-2.0.9/src/video/windows/SDL_windowswindow.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsclipboard.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsevents.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsframebuffer.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowskeyboard.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmessagebox.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmodes.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmouse.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengl.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengles.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsshape.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsvideo.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsvulkan.o \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowswindow.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsclipboard.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsevents.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsframebuffer.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowskeyboard.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmessagebox.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmodes.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsmouse.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengl.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsopengles.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsshape.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsvideo.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowsvulkan.d \
./lib/SDL2-2.0.9/src/video/windows/SDL_windowswindow.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/windows/%.o: ../lib/SDL2-2.0.9/src/video/windows/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


