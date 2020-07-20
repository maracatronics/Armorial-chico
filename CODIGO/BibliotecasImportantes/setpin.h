/*
 * setpin.h
 *
 *  Created on: 5 de jun de 2020
 *      Author: Gabriel Tarquinio
 *      Esta biblioteca foi criada para facilitar a programa��o no ccs, nela estar as fun��es  basicas relacionadas a pinos
 */

#ifndef SETPIN_H_
#define SETPIN_H_
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"

typedef struct
{
    uint32_t periferico;
    uint32_t port;
    uint8_t pino;
    uint32_t pwmPeriferico;
    uint32_t pwmMode;
    uint32_t pwmBase;
    uint32_t pwmGen;
    uint32_t pwmOutBit;
    uint32_t pwmOut;
    uint32_t adcPeriferico;
    uint32_t adcBase;
    uint32_t adcSequencia;
}pin;

// declara��es das estruturas de cada pino
pin pa2,pa3,pa4,pa5,pa6,pa7,pb0,pb1,pb2,pb3,pb4,pb5,pb6,pb7,pc0,pc1,pc2,pc3,pc4,pc5,pc6,pc7,pd0,pd1,pd2,pd3,pd4,pd5,pd6,pd7,pe0,pe1,pe2,pe3,pe4,pe5,pf0,pf1,pf2,pf3,pf4;

/*
 * Nome: startPINS
 * input: None
 * output: None
 * descri��o: Serve para carregar as informa��es de todos os pinos nas suas estruturas
 */

void startPINS(void);

/*
 * Nome: definePIN
 * input: estrutura do pino
 * output: None
 * descri��o: Serve para carregar as informa��es de um pino especifico
 */

void definePIN(pin *x);

/*
 * Nome: setIO
 * input: estrutura do pino e modo(0- para output e 1- para input)
 * output: None
 * descri��o: Serve para configurar pino como input ou output
 */

void setIO(pin *x, int mode);

/*
 * Nome: pinWrite
 * input: estrutura do pino e valor do pino(high ou low)
 * output: None
 * descri��o: Serve para setar o valor do pino output
 */

void pinWrite(pin *x, uint8_t valor);

/*
 * Nome: pinRead
 * input: estrutura do pino
 * output: leitura do pino(no caso high ou low
 * descri��o: Serve para ler um pino input
 */

uint32_t pinRead(pin *x);

/*
 * Nome: pwmMode
 * input: estrutura do pino e periodo do pwm
 * output: None
 * descri��o: Serve para setar um pino como pwm
 */

void pwmMode(pin *x, int period);

/*
 * Nome: pwmWrite
 * input: estrutura do pino e tamanho da onda
 * output: None
 * descri��o: Serve para controlar o pwm
 */

void pwmWrite(pin *x, int sizeWave);

/*
 * Nome: ADCMode
 * input: estrutura do pino e o periferico que vai fazer a leitura do adc(0 ou 1)
 * output: None
 * descri��o: Serve para configurar um pino como adc
 */

void ADCMode(pin *x, int base);

/*
 * Nome: ADCRead
 * input: estrutura do pino
 * output: None
 * descri��o: Serve para fazer a leitura do pino adc
 */

uint32_t ADCRead(pin *x);

/*
 * Nome: interruptMode
 * input: estrutura do pino, que tipo de evento quer capitar para fazer a interrup��o(GPIO_FALLING_EDGE sets detection to edge and trigger to falling,
                                                                                      GPIO_RISING_EDGE sets detection to edge and trigger to rising,
                                                                                      GPIO_BOTH_EDGES sets detection to both edges,
                                                                                      GPIO_LOW_LEVEL sets detection to low level,
                                                                                      GPIO_HIGH_LEVEL sets detection to high level)
   e a rotina de interrup��o que n�o tem parametro e n�o retorna nada
 * output: None
 * descri��o: Serve para setar um pino como interrup��o
 */

void interruptMode(pin *x, uint32_t type, void (*pfnIntHandler)(void));


#endif /* SETPIN_H_ */
