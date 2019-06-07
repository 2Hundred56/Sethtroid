################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CollisionManager.cpp \
../src/Game.cpp \
../src/Physics.cpp \
../src/PhysicsObject.cpp \
../src/Player.cpp \
../src/SDLInterface.cpp \
../src/Sprite.cpp \
../src/SpritedObject.cpp \
../src/Tile.cpp \
../src/TileLayer.cpp \
../src/Tileset.cpp \
../src/main.cpp 

OBJS += \
./src/CollisionManager.o \
./src/Game.o \
./src/Physics.o \
./src/PhysicsObject.o \
./src/Player.o \
./src/SDLInterface.o \
./src/Sprite.o \
./src/SpritedObject.o \
./src/Tile.o \
./src/TileLayer.o \
./src/Tileset.o \
./src/main.o 

CPP_DEPS += \
./src/CollisionManager.d \
./src/Game.d \
./src/Physics.d \
./src/PhysicsObject.d \
./src/Player.d \
./src/SDLInterface.d \
./src/Sprite.d \
./src/SpritedObject.d \
./src/Tile.d \
./src/TileLayer.d \
./src/Tileset.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -pedantic -Wall -Wextra -Wconversion -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


