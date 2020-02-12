/*
 * ADC.h
 *
 *  Created on: 27 de jan de 2020
 *      Author: Gabriel Tarquinio
 */

#ifndef ADC_H_
#define ADC_H_


#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"

void ConfigurarADC(uint32_t periferico ,uint32_t base , uint8_t pin);
uint32_t IniciarADC();


#endif /* ADC_H_ */
