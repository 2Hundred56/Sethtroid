################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/render/opengl/SDL_render_gl.c \
../lib/SDL2-2.0.9/src/render/opengl/SDL_shaders_gl.c 

OBJS += \
./lib/SDL2-2.0.9/src/render/opengl/SDL_render_gl.o \
./lib/SDL2-2.0.9/src/render/opengl/SDL_shaders_gl.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/render/opengl/SDL_render_gl.d \
./lib/SDL2-2.0.9/src/render/opengl/SDL_shaders_gl.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/render/opengl/%.o: ../lib/SDL2-2.0.9/src/render/opengl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


