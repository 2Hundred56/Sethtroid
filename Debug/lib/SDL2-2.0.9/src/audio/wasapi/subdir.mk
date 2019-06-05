################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_winrt.cpp 

C_SRCS += \
../lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi.c \
../lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_win32.c 

OBJS += \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi.o \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_win32.o \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_winrt.o 

CPP_DEPS += \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_winrt.d 

C_DEPS += \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi.d \
./lib/SDL2-2.0.9/src/audio/wasapi/SDL_wasapi_win32.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/audio/wasapi/%.o: ../lib/SDL2-2.0.9/src/audio/wasapi/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/SDL2-2.0.9/src/audio/wasapi/%.o: ../lib/SDL2-2.0.9/src/audio/wasapi/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


