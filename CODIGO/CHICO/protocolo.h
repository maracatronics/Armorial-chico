/*
 * protocolo.h
 *
 *  Created on: 27 de mar de 2020
 *      Author: Gabriel Tarquinio
 */

#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_


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
#include "setup.h"
#include "Comunicacao.h"
#include "driverlib/pwm.h"
#include "ADC.h"
#include "nrf24l01.h"

void GetComando(uint8_t *recebido);
bool angulacao(uint8_t recebido);
void locomocao(uint8_t vx, uint8_t vy, uint8_t vz);
bool CarregarCapacitor(uint8_t potencia);
void chute(int type_chute);
void send_dados(void);

#endif /* PROTOCOLO_H_ */
