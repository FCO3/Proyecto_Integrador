################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_jpeg_decode/r_jpeg_decode.c 

OBJS += \
./synergy/ssp/src/driver/r_jpeg_decode/r_jpeg_decode.o 

C_DEPS += \
./synergy/ssp/src/driver/r_jpeg_decode/r_jpeg_decode.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_jpeg_decode/%.o: ../synergy/ssp/src/driver/r_jpeg_decode/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	C:\Renesas\e2_studio\eclipse\/../\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy_cfg\ssp_cfg\driver" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\bsp" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\driver\api" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\driver\instances" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\src" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\src\synergy_gen" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy_cfg\ssp_cfg\framework" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\framework\api" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\framework\instances" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\framework\tes" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\inc\framework\el" -I"C:\Users\SEI203\e2_studio\workspace\GUIApp_Hector\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


