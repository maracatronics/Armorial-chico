/*
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
//#include "nrf24l01.h"
//struct nrf24l01p nrf;
//uint8_t addresses[][6] = {"1Node","2Node"};
//uint8_t time,add;


int main(void)
{
    // Thiet lap clock he thong
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    // Kich hoat uart0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    //Cau hinh chan PA0 va PA1 lan luot la chan RX va TX
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    //Cau hinh uart 0 baud 115200
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
  //  nrf24l01p_set_PA_level(&nrf, RF24_PA_LOW);
   // nrf24l01p_open_reading_pipe(&nrf, 1,addresses[0]);
   // nrf24l01p_start_listening(&nrf);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    //UARTCharGet(UART0_BASE)

    while(1)
    {
      uint32_t  RECEBIDO = UARTCharGet(UART0_BASE);
       if(RECEBIDO == 'A'){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 255);
        SysCtlDelay(20000000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
    }  if(RECEBIDO == 'B') {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 255);
        SysCtlDelay(20000000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
    }  if(RECEBIDO== 'C'){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 255);
        SysCtlDelay(20000000);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
    }

    }
}
