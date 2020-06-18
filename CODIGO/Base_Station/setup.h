/*
 * setup.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: Jose Neto
 *      Description: Funcoes e incializacoes necessarias para fazer o sistema funcionar
 */

#ifndef SETUP_H_
#define SETUP_H_

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/pwm.h"
#include "driverlib/uart.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"



/*
* Function Name: setup()
* Input: none
* Output: none
* Description: Set crystal frequency and enable GPIO Peripherals
* Example Call: setup();
*/
void setup(void);
/*
* Function Name: led_pin_config()
* Input: none
* Output: none
* Description: Set PORTF Pin 1, Pin 2, Pin 3 as output. On this pin Red, Blue and Green LEDs are connected.
* Example Call: led_pin_config();
*/
void led_pin_config(void);


#endif /* SETUP_H_ */
