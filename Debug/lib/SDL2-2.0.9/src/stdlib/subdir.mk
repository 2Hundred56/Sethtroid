################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/stdlib/SDL_getenv.c \
../lib/SDL2-2.0.9/src/stdlib/SDL_iconv.c \
../lib/SDL2-2.0.9/src/stdlib/SDL_malloc.c \
../lib/SDL2-2.0.9/src/stdlib/SDL_qsort.c \
../lib/SDL2-2.0.9/src/stdlib/SDL_stdlib.c \
../lib/SDL2-2.0.9/src/stdlib/SDL_string.c 

OBJS += \
./lib/SDL2-2.0.9/src/stdlib/SDL_getenv.o \
./lib/SDL2-2.0.9/src/stdlib/SDL_iconv.o \
./lib/SDL2-2.0.9/src/stdlib/SDL_malloc.o \
./lib/SDL2-2.0.9/src/stdlib/SDL_qsort.o \
./lib/SDL2-2.0.9/src/stdlib/SDL_stdlib.o \
./lib/SDL2-2.0.9/src/stdlib/SDL_string.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/stdlib/SDL_getenv.d \
./lib/SDL2-2.0.9/src/stdlib/SDL_iconv.d \
./lib/SDL2-2.0.9/src/stdlib/SDL_malloc.d \
./lib/SDL2-2.0.9/src/stdlib/SDL_qsort.d \
./lib/SDL2-2.0.9/src/stdlib/SDL_stdlib.d \
./lib/SDL2-2.0.9/src/stdlib/SDL_string.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/stdlib/%.o: ../lib/SDL2-2.0.9/src/stdlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


