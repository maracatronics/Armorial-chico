/*
 * ADC.c
 *
 *  Created on: 27 de jan de 2020
 *      Author: Gabriel Tarquinio
 */
#include "ADC.h"

/*Nome : ADCinit()
 *
 * Descrição: metodo a seguir configura a conversão analogica/digital
 * e retorna o valor obtido da conversao
 * input : porta base,pino
 * output: leitura da conversão
 */

uint32_t ADCinit(uint32_t periferico ,uint32_t base , uint8_t pin) {
    uint32_t pui32ADC0Value[2];
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    SysCtlPeripheralEnable(periferico);
    GPIOPinTypeADC(base,pin);
    ADCSequenceDisable(ADC0_BASE, 0); // desabilitar sequencia
    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0); // configurando para adc
    ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE,0, 1, ADC_CTL_CH1 | ADC_CTL_IE |
                                  ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 0);
             ADCIntClear(ADC0_BASE, 0);
             ADCProcessorTrigger(ADC0_BASE, 0);
             while(!ADCIntStatus(ADC0_BASE, 0, false))
             {
             }
             ADCSequenceDataGet(ADC0_BASE, 0, pui32ADC0Value);
       //      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, pui32ADC0Value);
             return pui32ADC0Value;



}
