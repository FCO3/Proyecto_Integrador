################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/adc_thread_entry.c \
../src/adc_thread_handler.c \
../src/blinky_thread_entry.c \
../src/hal_entry.c \
../src/pwm_thread_entry.c \
../src/pwm_thread_handler.c 

OBJS += \
./src/adc_thread_entry.o \
./src/adc_thread_handler.o \
./src/blinky_thread_entry.o \
./src/hal_entry.o \
./src/pwm_thread_entry.o \
./src/pwm_thread_handler.o 

C_DEPS += \
./src/adc_thread_entry.d \
./src/adc_thread_handler.d \
./src/blinky_thread_entry.d \
./src/hal_entry.d \
./src/pwm_thread_entry.d \
./src/pwm_thread_handler.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\e2_studio\eclipse\/../\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\driver" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\bsp" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\driver\api" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\driver\instances" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\src" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\src\synergy_gen" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\inc\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\Proyecto_Integrador\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


