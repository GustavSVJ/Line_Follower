#include "stm32f30x_conf.h" // STM32 config
#include "Uart.h"
#include "lcd.h"
#include "MotorControl.h"

int main(void){
    InitializeLeftMotor();
    InitializeRightMotor();
    InitializeMotorTimer(63999, 9);
    SetDutycycleLeftMotor(15000);
    SetDutycycleRightMotor(32000);

    init_usb_uart(2000000);

    InitializeRightMotorEncoder();
    EnableRightMotorEncoder();

    InitializeLeftMotorEncoder();
    EnableLeftMotorEncoder();



    while(1){
    }

    return 0;
}
