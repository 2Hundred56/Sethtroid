################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmdyn.c \
../lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmevents.c \
../lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmmouse.c \
../lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmopengles.c \
../lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmvideo.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmdyn.o \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmevents.o \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmmouse.o \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmopengles.o \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmvideo.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmdyn.d \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmevents.d \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmmouse.d \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmopengles.d \
./lib/SDL2-2.0.9/src/video/kmsdrm/SDL_kmsdrmvideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/kmsdrm/%.o: ../lib/SDL2-2.0.9/src/video/kmsdrm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


