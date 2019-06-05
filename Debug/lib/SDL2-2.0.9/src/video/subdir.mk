################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/video/SDL_RLEaccel.c \
../lib/SDL2-2.0.9/src/video/SDL_blit.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_0.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_1.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_A.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_N.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_auto.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_copy.c \
../lib/SDL2-2.0.9/src/video/SDL_blit_slow.c \
../lib/SDL2-2.0.9/src/video/SDL_bmp.c \
../lib/SDL2-2.0.9/src/video/SDL_clipboard.c \
../lib/SDL2-2.0.9/src/video/SDL_egl.c \
../lib/SDL2-2.0.9/src/video/SDL_fillrect.c \
../lib/SDL2-2.0.9/src/video/SDL_pixels.c \
../lib/SDL2-2.0.9/src/video/SDL_rect.c \
../lib/SDL2-2.0.9/src/video/SDL_shape.c \
../lib/SDL2-2.0.9/src/video/SDL_stretch.c \
../lib/SDL2-2.0.9/src/video/SDL_surface.c \
../lib/SDL2-2.0.9/src/video/SDL_video.c \
../lib/SDL2-2.0.9/src/video/SDL_vulkan_utils.c \
../lib/SDL2-2.0.9/src/video/SDL_yuv.c 

OBJS += \
./lib/SDL2-2.0.9/src/video/SDL_RLEaccel.o \
./lib/SDL2-2.0.9/src/video/SDL_blit.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_0.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_1.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_A.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_N.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_auto.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_copy.o \
./lib/SDL2-2.0.9/src/video/SDL_blit_slow.o \
./lib/SDL2-2.0.9/src/video/SDL_bmp.o \
./lib/SDL2-2.0.9/src/video/SDL_clipboard.o \
./lib/SDL2-2.0.9/src/video/SDL_egl.o \
./lib/SDL2-2.0.9/src/video/SDL_fillrect.o \
./lib/SDL2-2.0.9/src/video/SDL_pixels.o \
./lib/SDL2-2.0.9/src/video/SDL_rect.o \
./lib/SDL2-2.0.9/src/video/SDL_shape.o \
./lib/SDL2-2.0.9/src/video/SDL_stretch.o \
./lib/SDL2-2.0.9/src/video/SDL_surface.o \
./lib/SDL2-2.0.9/src/video/SDL_video.o \
./lib/SDL2-2.0.9/src/video/SDL_vulkan_utils.o \
./lib/SDL2-2.0.9/src/video/SDL_yuv.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/video/SDL_RLEaccel.d \
./lib/SDL2-2.0.9/src/video/SDL_blit.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_0.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_1.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_A.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_N.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_auto.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_copy.d \
./lib/SDL2-2.0.9/src/video/SDL_blit_slow.d \
./lib/SDL2-2.0.9/src/video/SDL_bmp.d \
./lib/SDL2-2.0.9/src/video/SDL_clipboard.d \
./lib/SDL2-2.0.9/src/video/SDL_egl.d \
./lib/SDL2-2.0.9/src/video/SDL_fillrect.d \
./lib/SDL2-2.0.9/src/video/SDL_pixels.d \
./lib/SDL2-2.0.9/src/video/SDL_rect.d \
./lib/SDL2-2.0.9/src/video/SDL_shape.d \
./lib/SDL2-2.0.9/src/video/SDL_stretch.d \
./lib/SDL2-2.0.9/src/video/SDL_surface.d \
./lib/SDL2-2.0.9/src/video/SDL_video.d \
./lib/SDL2-2.0.9/src/video/SDL_vulkan_utils.d \
./lib/SDL2-2.0.9/src/video/SDL_yuv.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/%.o: ../lib/SDL2-2.0.9/src/video/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


