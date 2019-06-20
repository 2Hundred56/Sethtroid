################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CollisionManager.cpp \
../src/Game.cpp \
../src/LivingObject.cpp \
../src/Loading.cpp \
../src/Physics.cpp \
../src/PhysicsObject.cpp \
../src/Player.cpp \
../src/SDLInterface.cpp \
../src/Tile.cpp \
../src/TileLayer.cpp \
../src/Tileset.cpp \
../src/main.cpp 

OBJS += \
./src/CollisionManager.o \
./src/Game.o \
./src/LivingObject.o \
./src/Loading.o \
./src/Physics.o \
./src/PhysicsObject.o \
./src/Player.o \
./src/SDLInterface.o \
./src/Tile.o \
./src/TileLayer.o \
./src/Tileset.o \
./src/main.o 

CPP_DEPS += \
./src/CollisionManager.d \
./src/Game.d \
./src/LivingObject.d \
./src/Loading.d \
./src/Physics.d \
./src/PhysicsObject.d \
./src/Player.d \
./src/SDLInterface.d \
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


