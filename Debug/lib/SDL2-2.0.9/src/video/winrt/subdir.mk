################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtevents.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtgamebar.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtkeyboard.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmessagebox.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmouse.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtopengles.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtpointerinput.cpp \
../lib/SDL2-2.0.9/src/video/winrt/SDL_winrtvideo.cpp 

OBJS += \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtevents.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtgamebar.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtkeyboard.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmessagebox.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmouse.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtopengles.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtpointerinput.o \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtvideo.o 

CPP_DEPS += \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtevents.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtgamebar.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtkeyboard.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmessagebox.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtmouse.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtopengles.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtpointerinput.d \
./lib/SDL2-2.0.9/src/video/winrt/SDL_winrtvideo.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SDL2-2.0.9/src/video/winrt/%.o: ../lib/SDL2-2.0.9/src/video/winrt/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/triforce/Eclipse/Sethtroid/lib/SDL2-2.0.9/include" -I"/Users/triforce/Eclipse/Sethtroid/lib/glew-2.1.0/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


