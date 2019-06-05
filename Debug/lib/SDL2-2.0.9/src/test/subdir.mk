################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/test/SDL_test_assert.c \
../lib/SDL2-2.0.9/src/test/SDL_test_common.c \
../lib/SDL2-2.0.9/src/test/SDL_test_compare.c \
../lib/SDL2-2.0.9/src/test/SDL_test_crc32.c \
../lib/SDL2-2.0.9/src/test/SDL_test_font.c \
../lib/SDL2-2.0.9/src/test/SDL_test_fuzzer.c \
../lib/SDL2-2.0.9/src/test/SDL_test_harness.c \
../lib/SDL2-2.0.9/src/test/SDL_test_imageBlit.c \
../lib/SDL2-2.0.9/src/test/SDL_test_imageBlitBlend.c \
../lib/SDL2-2.0.9/src/test/SDL_test_imageFace.c \
../lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitives.c \
../lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitivesBlend.c \
../lib/SDL2-2.0.9/src/test/SDL_test_log.c \
../lib/SDL2-2.0.9/src/test/SDL_test_md5.c \
../lib/SDL2-2.0.9/src/test/SDL_test_memory.c \
../lib/SDL2-2.0.9/src/test/SDL_test_random.c 

OBJS += \
./lib/SDL2-2.0.9/src/test/SDL_test_assert.o \
./lib/SDL2-2.0.9/src/test/SDL_test_common.o \
./lib/SDL2-2.0.9/src/test/SDL_test_compare.o \
./lib/SDL2-2.0.9/src/test/SDL_test_crc32.o \
./lib/SDL2-2.0.9/src/test/SDL_test_font.o \
./lib/SDL2-2.0.9/src/test/SDL_test_fuzzer.o \
./lib/SDL2-2.0.9/src/test/SDL_test_harness.o \
./lib/SDL2-2.0.9/src/test/SDL_test_imageBlit.o \
./lib/SDL2-2.0.9/src/test/SDL_test_imageBlitBlend.o \
./lib/SDL2-2.0.9/src/test/SDL_test_imageFace.o \
./lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitives.o \
./lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitivesBlend.o \
./lib/SDL2-2.0.9/src/test/SDL_test_log.o \
./lib/SDL2-2.0.9/src/test/SDL_test_md5.o \
./lib/SDL2-2.0.9/src/test/SDL_test_memory.o \
./lib/SDL2-2.0.9/src/test/SDL_test_random.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/test/SDL_test_assert.d \
./lib/SDL2-2.0.9/src/test/SDL_test_common.d \
./lib/SDL2-2.0.9/src/test/SDL_test_compare.d \
./lib/SDL2-2.0.9/src/test/SDL_test_crc32.d \
./lib/SDL2-2.0.9/src/test/SDL_test_font.d \
./lib/SDL2-2.0.9/src/test/SDL_test_fuzzer.d \
./lib/SDL2-2.0.9/src/test/SDL_test_harness.d \
./lib/SDL2-2.0.9/src/test/SDL_test_imageBlit.d \
./lib/SDL2-2.0.9/src/test/SDL_test_imageBlitBlend.d \
./lib/SDL2-2.0.9/src/test/SDL_test_imageFace.d \
./lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitives.d \
./lib/SDL2-2.0.9/src/test/SDL_test_imagePrimitivesBlend.d \
./lib/SDL2-2.0.9/src/test/SDL_test_log.d \
./lib/SDL2-2.0.9/src/test/SDL_test_md5.d \
./lib/SDL2-2.0.9/src/test/SDL_test_memory.d \
./lib/SDL2-2.0.9/src/test/SDL_test_random.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/test/%.o: ../lib/SDL2-2.0.9/src/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


