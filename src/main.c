#include "stm32f30x_usart.h"
#include "stm32f30x_conf.h" // STM32 config
#include "Uart.h"
#include "lcd.h"

int main(void)
{
    void UART1_init()
    {
        USART_InitTypeDef usartConfig;

        RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
        USART_Cmd(USART1, ENABLE);

        usartConfig.USART_BaudRate = 9600;
        usartConfig.USART_WordLength = USART_WordLength_8b;
        usartConfig.USART_StopBits = USART_StopBits_1;
        usartConfig.USART_Parity = USART_Parity_No;
        usartConfig.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
        usartConfig.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        USART_Init(USART1, &usartConfig);

        GPIO_InitTypeDef gpioConfig;

        //PA9 = USART1.TX => Alternative Function Output
        gpioConfig.GPIO_Mode = GPIO_Mode_AF_PP;
        gpioConfig.GPIO_Pin = GPIO_Pin_9;
        gpioConfig.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(GPIOA, &gpioConfig);

        //PA10 = USART1.RX => Input
        gpioConfig.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        gpioConfig.GPIO_Pin = GPIO_Pin_10;
        GPIO_Init(GPIOA, &gpioConfig);
}

    while(1)
    {

    }

    return 0;
}
