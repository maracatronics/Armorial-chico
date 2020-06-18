/*
 * setup.c
 *
 *  Created on: 20 de nov de 2019
 *      Author: Jose Neto
 *      Description: Funcoes e incializacoes necessarias para fazer o sistema funcionar
 */

#include "setup.h"

/*
* Function Name: setup()
* Input: none
* Output: none
* Description: Set crystal frequency and enable GPIO Peripherals
* Example Call: setup();
*/
void setup(void)
{
    //
    // Set the clocking to run directly from the crystal.
    // Clock to 80MHZ
    //
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

   }

/*
* Function Name: led_pin_config()
* Input: none
* Output: none
* Description: Set PORTF Pin 1, Pin 2, Pin 3 as output. On this pin Red, Blue and Green LEDs are connected.
* Example Call: led_pin_config();
*/
void led_pin_config(void)
{
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
}

// Configura os pinos PB4,PB6,PF1,PF4 como pwms

void setup_pwm(void){
    uint32_t period = 5000;
        SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB|SYSCTL_PERIPH_GPIOF);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0|SYSCTL_PERIPH_PWM1);

        GPIOPinConfigure(GPIO_PF1_M1PWM5);
     //   GPIOPinConfigure(GPIO_PF4_M1FAULT0);
     //   GPIOPinConfigure(GPIO_PB4_M0PWM2);
     //   GPIOPinConfigure(GPIO_PB6_M0PWM0);
        GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
      //  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_6);

        PWMGenConfigure(PWM1_BASE,PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
        PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, period);
        // Enable the PWM generator
        PWMGenEnable(PWM1_BASE,PWM_GEN_2);
         // Turn on the Output pins
        PWMOutputState(PWM1_BASE,PWM_OUT_5_BIT, true);
}
    // configura a serial para a velocidade 115200
void setup_serial(int BaudRate){
     SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
      // Enable the peripherals used by this program.
 //    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
 //    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
     //  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_3);
     GPIOPinConfigure(GPIO_PA0_U0RX);
     GPIOPinConfigure(GPIO_PA1_U0TX);
     GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
     UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), BaudRate, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
}
