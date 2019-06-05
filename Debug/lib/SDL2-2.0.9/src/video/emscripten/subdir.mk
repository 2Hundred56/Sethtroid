################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenevents.c \
../lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenframebuffer.c \
../lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenmouse.c \
../lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenopengles.c \
../lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenvideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenevents.o \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenframebuffer.o \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenmouse.o \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenopengles.o \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenvideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenevents.d \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenframebuffer.d \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenmouse.d \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenopengles.d \
./lib/SDL2-2.0.9/src/video/emscripten/SDL_emscriptenvideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/emscripten/%.o: ../lib/SDL2-2.0.9/src/video/emscripten/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


