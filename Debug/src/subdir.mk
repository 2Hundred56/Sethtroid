################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CollisionManager.cpp \
../src/Game.cpp \
../src/Physics.cpp \
../src/SDLInterface.cpp \
../src/Sprite.cpp \
../src/ThreeBy3.cpp \
../src/Tile.cpp \
../src/TileLayer.cpp \
../src/Tileset.cpp \
../src/main.cpp 

OBJS += \
./src/CollisionManager.o \
./src/Game.o \
./src/Physics.o \
./src/SDLInterface.o \
./src/Sprite.o \
./src/ThreeBy3.o \
./src/Tile.o \
./src/TileLayer.o \
./src/Tileset.o \
./src/main.o 

CPP_DEPS += \
./src/CollisionManager.d \
./src/Game.d \
./src/Physics.d \
./src/SDLInterface.d \
./src/Sprite.d \
./src/ThreeBy3.d \
./src/Tile.d \
./src/TileLayer.d \
./src/Tileset.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -w -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


