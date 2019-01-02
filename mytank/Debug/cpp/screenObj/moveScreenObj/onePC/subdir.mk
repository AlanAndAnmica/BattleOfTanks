################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/screenObj/moveScreenObj/onePC/Player.cpp 

OBJS += \
./cpp/screenObj/moveScreenObj/onePC/Player.o 

CPP_DEPS += \
./cpp/screenObj/moveScreenObj/onePC/Player.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/screenObj/moveScreenObj/onePC/%.o: ../cpp/screenObj/moveScreenObj/onePC/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 --std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


