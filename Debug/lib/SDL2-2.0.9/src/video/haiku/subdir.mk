################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bclipboard.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bevents.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bframebuffer.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bkeyboard.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bmodes.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bopengl.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bvideo.cc \
../lib/SDL2-2.0.9/src/video/haiku/SDL_bwindow.cc 

CC_DEPS += \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bclipboard.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bevents.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bframebuffer.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bkeyboard.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bmodes.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bopengl.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bvideo.d \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bwindow.d 

OBJS += \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bclipboard.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bevents.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bframebuffer.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bkeyboard.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bmodes.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bopengl.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bvideo.o \
./lib/SDL2-2.0.9/src/video/haiku/SDL_bwindow.o 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/haiku/%.o: ../lib/SDL2-2.0.9/src/video/haiku/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


