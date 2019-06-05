################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandclipboard.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddatamanager.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddyn.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandevents.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandmouse.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandopengles.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandtouch.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvideo.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvulkan.c \
../lib/SDL2-2.0.9/src/video/wayland/SDL_waylandwindow.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandclipboard.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddatamanager.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddyn.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandevents.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandmouse.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandopengles.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandtouch.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvideo.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvulkan.o \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandwindow.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandclipboard.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddatamanager.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylanddyn.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandevents.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandmouse.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandopengles.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandtouch.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvideo.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandvulkan.d \
./lib/SDL2-2.0.9/src/video/wayland/SDL_waylandwindow.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/wayland/%.o: ../lib/SDL2-2.0.9/src/video/wayland/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


