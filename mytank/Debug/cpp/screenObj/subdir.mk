################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/screenObj/MoveScreenObj.cpp 

OBJS += \
./cpp/screenObj/MoveScreenObj.o 

CPP_DEPS += \
./cpp/screenObj/MoveScreenObj.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/screenObj/%.o: ../cpp/screenObj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 --std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


