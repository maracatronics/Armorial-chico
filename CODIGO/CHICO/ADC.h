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

// ele recebe o indice do vetor que a gnt quer que seja retornado no caso escolher se queremos a carga do capacitor ou da bateria
uint32_t GetADC(int TypeCarga);

#endif /* ADC_H_ */
