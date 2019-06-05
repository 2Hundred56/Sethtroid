################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/libm/e_atan2.c \
../lib/SDL2-2.0.9/src/libm/e_exp.c \
../lib/SDL2-2.0.9/src/libm/e_fmod.c \
../lib/SDL2-2.0.9/src/libm/e_log.c \
../lib/SDL2-2.0.9/src/libm/e_log10.c \
../lib/SDL2-2.0.9/src/libm/e_pow.c \
../lib/SDL2-2.0.9/src/libm/e_rem_pio2.c \
../lib/SDL2-2.0.9/src/libm/e_sqrt.c \
../lib/SDL2-2.0.9/src/libm/k_cos.c \
../lib/SDL2-2.0.9/src/libm/k_rem_pio2.c \
../lib/SDL2-2.0.9/src/libm/k_sin.c \
../lib/SDL2-2.0.9/src/libm/k_tan.c \
../lib/SDL2-2.0.9/src/libm/s_atan.c \
../lib/SDL2-2.0.9/src/libm/s_copysign.c \
../lib/SDL2-2.0.9/src/libm/s_cos.c \
../lib/SDL2-2.0.9/src/libm/s_fabs.c \
../lib/SDL2-2.0.9/src/libm/s_floor.c \
../lib/SDL2-2.0.9/src/libm/s_scalbn.c \
../lib/SDL2-2.0.9/src/libm/s_sin.c \
../lib/SDL2-2.0.9/src/libm/s_tan.c 

OBJS += \
./lib/SDL2-2.0.9/src/libm/e_atan2.o \
./lib/SDL2-2.0.9/src/libm/e_exp.o \
./lib/SDL2-2.0.9/src/libm/e_fmod.o \
./lib/SDL2-2.0.9/src/libm/e_log.o \
./lib/SDL2-2.0.9/src/libm/e_log10.o \
./lib/SDL2-2.0.9/src/libm/e_pow.o \
./lib/SDL2-2.0.9/src/libm/e_rem_pio2.o \
./lib/SDL2-2.0.9/src/libm/e_sqrt.o \
./lib/SDL2-2.0.9/src/libm/k_cos.o \
./lib/SDL2-2.0.9/src/libm/k_rem_pio2.o \
./lib/SDL2-2.0.9/src/libm/k_sin.o \
./lib/SDL2-2.0.9/src/libm/k_tan.o \
./lib/SDL2-2.0.9/src/libm/s_atan.o \
./lib/SDL2-2.0.9/src/libm/s_copysign.o \
./lib/SDL2-2.0.9/src/libm/s_cos.o \
./lib/SDL2-2.0.9/src/libm/s_fabs.o \
./lib/SDL2-2.0.9/src/libm/s_floor.o \
./lib/SDL2-2.0.9/src/libm/s_scalbn.o \
./lib/SDL2-2.0.9/src/libm/s_sin.o \
./lib/SDL2-2.0.9/src/libm/s_tan.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/libm/e_atan2.d \
./lib/SDL2-2.0.9/src/libm/e_exp.d \
./lib/SDL2-2.0.9/src/libm/e_fmod.d \
./lib/SDL2-2.0.9/src/libm/e_log.d \
./lib/SDL2-2.0.9/src/libm/e_log10.d \
./lib/SDL2-2.0.9/src/libm/e_pow.d \
./lib/SDL2-2.0.9/src/libm/e_rem_pio2.d \
./lib/SDL2-2.0.9/src/libm/e_sqrt.d \
./lib/SDL2-2.0.9/src/libm/k_cos.d \
./lib/SDL2-2.0.9/src/libm/k_rem_pio2.d \
./lib/SDL2-2.0.9/src/libm/k_sin.d \
./lib/SDL2-2.0.9/src/libm/k_tan.d \
./lib/SDL2-2.0.9/src/libm/s_atan.d \
./lib/SDL2-2.0.9/src/libm/s_copysign.d \
./lib/SDL2-2.0.9/src/libm/s_cos.d \
./lib/SDL2-2.0.9/src/libm/s_fabs.d \
./lib/SDL2-2.0.9/src/libm/s_floor.d \
./lib/SDL2-2.0.9/src/libm/s_scalbn.d \
./lib/SDL2-2.0.9/src/libm/s_sin.d \
./lib/SDL2-2.0.9/src/libm/s_tan.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/libm/%.o: ../lib/SDL2-2.0.9/src/libm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


