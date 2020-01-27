/*
    Copyright (C) 2016 Dean Miller

    Based on RF24 arduino Library example.
    This will talk to an NRF24L01 on another board and ping back whatever is sent.

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use, copy,
    modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#include "nrf24l01.h"

struct nrf24l01p nrf;
uint8_t addresses[][6] = {"1Node","2Node"};




/*
* Function Name: setup()
* Input: none
* Output: none
* Description: Set crystal frequency and enable GPIO Peripherals
* Example Call: setup();
*/
//void setup(void)
//{
//    //
//    // Set the clocking to run directly from the crystal.
//    // Clock to 80MHZ
//    //
//    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//}

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


int main(void) {

    uint8_t ui8LED = 2;
	//
	// Enable lazy stacking for interrupt handlers.  This allows floating-point
	// instructions to be used within interrupt handlers, but at the expense of
	// extra stack usage.
	//
	FPULazyStackingEnable();
	FPUEnable();


	setup_tiva();

	IntMasterEnable();

	led_pin_config();

	//set up the radio
	if( !nrf24l01p_setup(&nrf, GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PORTC_BASE, GPIO_PIN_4, SSI0_BASE) ){
		//we couldn't communicate with the radio
		//return 1;
	}
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, ui8LED);
	nrf24l01p_set_PA_level(&nrf, RF24_PA_LOW);

	nrf24l01p_open_writing_pipe(&nrf, addresses[0]);
	nrf24l01p_open_reading_pipe(&nrf, 1,addresses[1]);

	nrf24l01p_start_listening(&nrf);

	while(1){
	    uint8_t envio[6]={'m','a','r','a','c','a'};
	    uint8_t recebimento[5];
		if (nrf24l01p_available(&nrf)) {
			//uint32_t got_time;

			// Variable for the received time stamp
			while (nrf24l01p_available(&nrf)) {                 // While there is data ready
				nrf24l01p_read(&nrf, recebimento, sizeof(recebimento));     // Get the payload
			}

			nrf24l01p_stop_listening(&nrf);        // First, stop listening so we can talk
			nrf24l01p_write(&nrf, &envio, sizeof(envio)); // Send the final one back.
			nrf24l01p_start_listening(&nrf); // Now, resume listening so we catch the next packets.



		//give it a little space
		SysCtlDelay((SysCtlClockGet() >> 12) * 5);

		// Turn on the LED
		ui8LED = 255;  //forcei 255 para ligar o led
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, ui8LED);
		// Delay for a bit
		SysCtlDelay(10000000);

		// Cycle through Red, Green and Blue LEDs

	}	else
		{
		    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, ui8LED);

		}

		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, ui8LED);
	}

	//return 0;
}
