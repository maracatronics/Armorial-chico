/*
* Aquivo base usando para impementacao do firmware do robo omnidirecional.
* Autores: Jose Neto, Flavio Candido
*
* Autor do projeto que usamos como modelo: Texas Instruments e Saurav Shandilya, Vishwanathan Iyer

* Description: Codigo inicial do firmware do robo  omnidirecional.
*              Nesta estapa, estamos usando o modelo de projeto apresnetado em:
*              https://www.cse.iitb.ac.in/~erts/html_pages/resources.html
*              e adaptando.
*
* Implementacao da vez: nRF24L01+
*
* Filename: main.c
* Functions: setup(), led_pin_config(), main()  
* Global Variables: none
*/

//Bibliotecas do modelo:
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
//Bibliotecas adicionadas por nos:
#include "driverlib/ssi.h" //SPI Library


/*
* Function Name: setup()
* Input: none
* Output: none
* Description: Set crystal frequency and enable GPIO Peripherals  
* Example Call: setup();
*/
void setup(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

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
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
}


int main(void)
{
	uint8_t ui8LED = 2;

	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

	while(1)
	{
		// Turn on the LED
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, ui8LED);
		// Delay for a bit
		SysCtlDelay(10000000);

		// Cycle through Red, Green and Blue LEDs
		if (ui8LED == 8+4+2)
		{
			ui8LED = 2;
		}
		else
		{
			++ui8LED;
		}
	}
}
