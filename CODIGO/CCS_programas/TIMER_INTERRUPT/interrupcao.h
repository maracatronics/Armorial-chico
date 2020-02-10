/*
 * interrupcao.h
 *
 *  Created on: 22 de jan de 2020
 *      Author: Gabriel Tarquinio
 */

#ifndef INTERRUPCAO_H_
#define INTERRUPCAO_H_
/*
 * função: IntConfig
 * input: periferico, porta-base, pino (ex: SYSCTL_PERIPH_GPIOF, GPIO_PORTF_BASE,GPIO_PIN_4)
 * output: none
 */

 void IntConfig(uint32_t periferico, uint32_t base, uint32_t pino,);



#endif /* INTERRUPCAO_H_ */

