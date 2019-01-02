################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/Game.cpp \
../cpp/GameMg.cpp \
../cpp/Screen.cpp \
../cpp/ScreenObj.cpp \
../cpp/mytank.cpp \
../cpp/src.cpp 

OBJS += \
./cpp/Game.o \
./cpp/GameMg.o \
./cpp/Screen.o \
./cpp/ScreenObj.o \
./cpp/mytank.o \
./cpp/src.o 

CPP_DEPS += \
./cpp/Game.d \
./cpp/GameMg.d \
./cpp/Screen.d \
./cpp/ScreenObj.d \
./cpp/mytank.d \
./cpp/src.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/%.o: ../cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 --std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


