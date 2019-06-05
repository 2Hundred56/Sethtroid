################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/nacl/SDL_naclevents.c \
../lib/SDL2-2.0.9/src/video/nacl/SDL_naclglue.c \
../lib/SDL2-2.0.9/src/video/nacl/SDL_naclopengles.c \
../lib/SDL2-2.0.9/src/video/nacl/SDL_naclvideo.c \
../lib/SDL2-2.0.9/src/video/nacl/SDL_naclwindow.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclevents.o \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclglue.o \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclopengles.o \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclvideo.o \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclwindow.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclevents.d \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclglue.d \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclopengles.d \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclvideo.d \
./lib/SDL2-2.0.9/src/video/nacl/SDL_naclwindow.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/nacl/%.o: ../lib/SDL2-2.0.9/src/video/nacl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


