/*
 * interrupcao.h
 *
 *  Created on: 22 de jan de 2020
 *      Author: Gabriel Tarquinio
 */

#ifndef INTERRUPCAO_H_
#define INTERRUPCAO_H_


#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"/*
 * função: IntConfig
 * input: periferico, porta-base, pino (ex: SYSCTL_PERIPH_GPIOF, GPIO_PORTF_BASE,GPIO_PIN_4)
 * output: none
 */

 void IntConfig(uint32_t base, uint8_t pino,uint32_t ui32IntType);

 int IntContador(uint32_t base, uint8_t pino,uint32_t ui32IntType, bool state,int contador);

#endif /* INTERRUPCAO_H_ */

