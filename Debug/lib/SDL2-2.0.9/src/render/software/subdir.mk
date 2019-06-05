################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/render/software/SDL_blendfillrect.c \
../lib/SDL2-2.0.9/src/render/software/SDL_blendline.c \
../lib/SDL2-2.0.9/src/render/software/SDL_blendpoint.c \
../lib/SDL2-2.0.9/src/render/software/SDL_drawline.c \
../lib/SDL2-2.0.9/src/render/software/SDL_drawpoint.c \
../lib/SDL2-2.0.9/src/render/software/SDL_render_sw.c \
../lib/SDL2-2.0.9/src/render/software/SDL_rotate.c 

OBJS += \
./lib/SDL2-2.0.9/src/render/software/SDL_blendfillrect.o \
./lib/SDL2-2.0.9/src/render/software/SDL_blendline.o \
./lib/SDL2-2.0.9/src/render/software/SDL_blendpoint.o \
./lib/SDL2-2.0.9/src/render/software/SDL_drawline.o \
./lib/SDL2-2.0.9/src/render/software/SDL_drawpoint.o \
./lib/SDL2-2.0.9/src/render/software/SDL_render_sw.o \
./lib/SDL2-2.0.9/src/render/software/SDL_rotate.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/render/software/SDL_blendfillrect.d \
./lib/SDL2-2.0.9/src/render/software/SDL_blendline.d \
./lib/SDL2-2.0.9/src/render/software/SDL_blendpoint.d \
./lib/SDL2-2.0.9/src/render/software/SDL_drawline.d \
./lib/SDL2-2.0.9/src/render/software/SDL_drawpoint.d \
./lib/SDL2-2.0.9/src/render/software/SDL_render_sw.d \
./lib/SDL2-2.0.9/src/render/software/SDL_rotate.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/render/software/%.o: ../lib/SDL2-2.0.9/src/render/software/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


