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
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

// Funções baseadas no em um contador de tempo

void TimerIntConfig(void);

uint32_t getTime(void);

void clearTime(void);

#endif /* INTERRUPCAO_H_ */

