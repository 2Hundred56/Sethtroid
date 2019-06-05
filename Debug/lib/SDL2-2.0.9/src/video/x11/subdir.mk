################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11clipboard.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11dyn.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11events.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11framebuffer.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11keyboard.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11messagebox.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11modes.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11mouse.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11opengl.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11opengles.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11shape.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11touch.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11video.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11vulkan.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11window.c \
../lib/SDL2-2.0.9/src/video/x11/SDL_x11xinput2.c \
../lib/SDL2-2.0.9/src/video/x11/edid-parse.c \
../lib/SDL2-2.0.9/src/video/x11/imKStoUCS.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11clipboard.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11dyn.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11events.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11framebuffer.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11keyboard.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11messagebox.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11modes.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11mouse.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11opengl.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11opengles.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11shape.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11touch.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11video.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11vulkan.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11window.o \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11xinput2.o \
./lib/SDL2-2.0.9/src/video/x11/edid-parse.o \
./lib/SDL2-2.0.9/src/video/x11/imKStoUCS.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11clipboard.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11dyn.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11events.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11framebuffer.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11keyboard.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11messagebox.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11modes.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11mouse.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11opengl.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11opengles.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11shape.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11touch.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11video.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11vulkan.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11window.d \
./lib/SDL2-2.0.9/src/video/x11/SDL_x11xinput2.d \
./lib/SDL2-2.0.9/src/video/x11/edid-parse.d \
./lib/SDL2-2.0.9/src/video/x11/imKStoUCS.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/x11/%.o: ../lib/SDL2-2.0.9/src/video/x11/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


