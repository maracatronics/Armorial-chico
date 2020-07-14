/*
 * setpin.h
 *
 *  Created on: 5 de jun de 2020
 *      Author: Gabriel Tarquinio
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

// declarações das estruturas de cada pino
pin pa2,pa3,pa4,pa5,pa6,pa7,pb0,pb1,pb2,pb3,pb4,pb5,pb6,pb7,pc0,pc1,pc2,pc3,pc4,pc5,pc6,pc7,pd0,pd1,pd2,pd3,pd4,pd5,pd6,pd7,pe0,pe1,pe2,pe3,pe4,pe5,pf0,pf1,pf2,pf3,pf4;

void startPINS(void);
void definePIN(pin *x);
void setIO(pin *x, int mode);
void pinWrite(pin *x, uint8_t valor);
uint32_t pinRead(pin *x);
void pwmMode(pin *x, int period);
void pwmWrite(pin *x, int sizeWave);
void ADCMode(pin *x, int base);
uint32_t ADCRead(pin *x);
void interruptMode(pin *x, uint32_t type, void (*pfnIntHandler)(void));


#endif /* SETPIN_H_ */
