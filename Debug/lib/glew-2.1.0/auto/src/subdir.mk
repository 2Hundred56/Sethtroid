################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/glew-2.1.0/auto/src/glew_head.c \
../lib/glew-2.1.0/auto/src/glew_init_egl.c \
../lib/glew-2.1.0/auto/src/glew_init_gl.c \
../lib/glew-2.1.0/auto/src/glew_init_glx.c \
../lib/glew-2.1.0/auto/src/glew_init_tail.c \
../lib/glew-2.1.0/auto/src/glew_init_wgl.c \
../lib/glew-2.1.0/auto/src/glew_str_egl.c \
../lib/glew-2.1.0/auto/src/glew_str_glx.c \
../lib/glew-2.1.0/auto/src/glew_str_head.c \
../lib/glew-2.1.0/auto/src/glew_str_tail.c \
../lib/glew-2.1.0/auto/src/glew_str_wgl.c \
../lib/glew-2.1.0/auto/src/glewinfo_egl.c \
../lib/glew-2.1.0/auto/src/glewinfo_gl.c \
../lib/glew-2.1.0/auto/src/glewinfo_glx.c \
../lib/glew-2.1.0/auto/src/glewinfo_head.c \
../lib/glew-2.1.0/auto/src/glewinfo_tail.c \
../lib/glew-2.1.0/auto/src/glewinfo_wgl.c 

OBJS += \
./lib/glew-2.1.0/auto/src/glew_head.o \
./lib/glew-2.1.0/auto/src/glew_init_egl.o \
./lib/glew-2.1.0/auto/src/glew_init_gl.o \
./lib/glew-2.1.0/auto/src/glew_init_glx.o \
./lib/glew-2.1.0/auto/src/glew_init_tail.o \
./lib/glew-2.1.0/auto/src/glew_init_wgl.o \
./lib/glew-2.1.0/auto/src/glew_str_egl.o \
./lib/glew-2.1.0/auto/src/glew_str_glx.o \
./lib/glew-2.1.0/auto/src/glew_str_head.o \
./lib/glew-2.1.0/auto/src/glew_str_tail.o \
./lib/glew-2.1.0/auto/src/glew_str_wgl.o \
./lib/glew-2.1.0/auto/src/glewinfo_egl.o \
./lib/glew-2.1.0/auto/src/glewinfo_gl.o \
./lib/glew-2.1.0/auto/src/glewinfo_glx.o \
./lib/glew-2.1.0/auto/src/glewinfo_head.o \
./lib/glew-2.1.0/auto/src/glewinfo_tail.o \
./lib/glew-2.1.0/auto/src/glewinfo_wgl.o 

C_DEPS += \
./lib/glew-2.1.0/auto/src/glew_head.d \
./lib/glew-2.1.0/auto/src/glew_init_egl.d \
./lib/glew-2.1.0/auto/src/glew_init_gl.d \
./lib/glew-2.1.0/auto/src/glew_init_glx.d \
./lib/glew-2.1.0/auto/src/glew_init_tail.d \
./lib/glew-2.1.0/auto/src/glew_init_wgl.d \
./lib/glew-2.1.0/auto/src/glew_str_egl.d \
./lib/glew-2.1.0/auto/src/glew_str_glx.d \
./lib/glew-2.1.0/auto/src/glew_str_head.d \
./lib/glew-2.1.0/auto/src/glew_str_tail.d \
./lib/glew-2.1.0/auto/src/glew_str_wgl.d \
./lib/glew-2.1.0/auto/src/glewinfo_egl.d \
./lib/glew-2.1.0/auto/src/glewinfo_gl.d \
./lib/glew-2.1.0/auto/src/glewinfo_glx.d \
./lib/glew-2.1.0/auto/src/glewinfo_head.d \
./lib/glew-2.1.0/auto/src/glewinfo_tail.d \
./lib/glew-2.1.0/auto/src/glewinfo_wgl.d 


# Each subdirectory must supply rules for building sources it contributes
lib/glew-2.1.0/auto/src/%.o: ../lib/glew-2.1.0/auto/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


