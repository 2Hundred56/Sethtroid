################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/SDL2-2.0.9/src/core/linux/SDL_dbus.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_evdev.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_evdev_kbd.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_fcitx.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_ibus.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_ime.c \
../lib/SDL2-2.0.9/src/core/linux/SDL_udev.c 

OBJS += \
./lib/SDL2-2.0.9/src/core/linux/SDL_dbus.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_evdev.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_evdev_kbd.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_fcitx.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_ibus.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_ime.o \
./lib/SDL2-2.0.9/src/core/linux/SDL_udev.o 

C_DEPS += \
./lib/SDL2-2.0.9/src/core/linux/SDL_dbus.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_evdev.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_evdev_kbd.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_fcitx.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_ibus.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_ime.d \
./lib/SDL2-2.0.9/src/core/linux/SDL_udev.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/core/linux/%.o: ../lib/SDL2-2.0.9/src/core/linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


