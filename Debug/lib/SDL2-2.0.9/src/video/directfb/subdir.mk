################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_WM.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_dyn.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_events.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_modes.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_mouse.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_opengl.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_render.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_shape.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_video.c \
../lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_window.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_WM.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_dyn.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_events.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_modes.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_mouse.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_opengl.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_render.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_shape.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_video.o \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_window.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_WM.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_dyn.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_events.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_modes.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_mouse.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_opengl.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_render.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_shape.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_video.d \
./lib/SDL2-2.0.9/src/video/directfb/SDL_DirectFB_window.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/directfb/%.o: ../lib/SDL2-2.0.9/src/video/directfb/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


