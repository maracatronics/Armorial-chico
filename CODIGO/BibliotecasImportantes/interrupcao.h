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

// Funções baseadas em um contador de tempo

/*
 * Nome: TimerIntConfig
 * input: None
 * output: None
 * descrição: Serve para configurar e inicializar o timer
 */

void TimerIntConfig(void);

/*
 * Nome: getTime
 * input: None
 * output: unidade de tempo em ms(uint32_t)
 * descrição: Serve para ver a medição do cronometro
 */

uint32_t getTime(void);

/*
 * Nome: clearTime
 * input: None
 * output: None
 * descrição: Serve para zerar o cronometro
 */

void clearTime(void);

#endif /* INTERRUPCAO_H_ */

