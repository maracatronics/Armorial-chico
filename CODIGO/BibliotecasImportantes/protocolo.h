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
#include "setpin.h"
#include "nrf24l01.h"


/*
 * Nome: GetComando
 * input: recebido(protocolo que o robo recebe)
 * output: None
 * descrição: Serve para interpretar o comando recebido
 */

void GetComando(uint8_t *recebido);

bool angulacao(uint8_t recebido);

void locomocao(uint8_t vx, uint8_t vy, uint8_t vz);

/*
 * Nome: CarregarCapacitor
 * input: potencia desejada para o capacitor
 * output: bool 0 - se o capacitor ainda não estiver na carga desejada ou
 *              1 - se o capacitor tiver a carga desejada
 * descrição: Serve para verificar a potencia do capacitor e carrega-lo
 */

bool CarregarCapacitor(uint8_t potencia);

/*
 * Nome: chute
 * input: tipo de chute(1-chute normal, 2-chip kick)
 * output: None
 * descrição: Executa o chute desejado
 */

void chute(int type_chute);

/*
 * Nome: send_dados
 * input: none
 * output: None
 * descrição: Serve para enviar dados para IA
 */

void send_dados(void);

#endif /* PROTOCOLO_H_ */
