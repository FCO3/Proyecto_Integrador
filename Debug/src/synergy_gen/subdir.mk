################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/synergy_gen/adc_thread.c \
../src/synergy_gen/common_data.c \
../src/synergy_gen/hal_data.c \
../src/synergy_gen/main.c \
../src/synergy_gen/pin_data.c \
../src/synergy_gen/pwm_thread.c 

OBJS += \
./src/synergy_gen/adc_thread.o \
./src/synergy_gen/common_data.o \
./src/synergy_gen/hal_data.o \
./src/synergy_gen/main.o \
./src/synergy_gen/pin_data.o \
./src/synergy_gen/pwm_thread.o 

C_DEPS += \
./src/synergy_gen/adc_thread.d \
./src/synergy_gen/common_data.d \
./src/synergy_gen/hal_data.d \
./src/synergy_gen/main.d \
./src/synergy_gen/pin_data.d \
./src/synergy_gen/pwm_thread.d 


# Each subdirectory must supply rules for building sources it contributes
src/synergy_gen/%.o: ../src/synergy_gen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\e2_studio\eclipse\/../\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\driver" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\bsp" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\driver\api" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\driver\instances" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\src" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\src\synergy_gen" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


