#include <stdio.h>
#include <string.h>
#include "common.h"
#include "gpio.h"
#include "lpuart.h"
#include "flash.h"
#include "scg.h"


int main(void)
{
    uint8_t c;
    DelayInit();
    
    SCG->FIRCDIV =   SCG_FIRCDIV_FIRCDIV2(1) | SCG_FIRCDIV_FIRCDIV1(1);  
    SetPinMux(HW_GPIOC, 6, 2);
    SetPinMux(HW_GPIOC, 7, 2);
    LPUART_Init(HW_LPUART1, 115200);

    GPIO_Init(HW_GPIOD, 0, kGPIO_OPPH);
    while(1)
    {
        GPIO_PinToggle(HW_GPIOD, 0);
        DelayMs(500);
    }
    
}



void HardFault_Handler(void)
{
    NVIC_SystemReset();
    
    while(1)
    {
    }
}


