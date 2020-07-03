
//Bibliotecas do modelo:
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
//Bibliotecas adicionadas por nos:
#include "driverlib/ssi.h" //SPI Library
#include <setpin.h>

volatile bool valor = false;

void onButtonDown(void); // declaração da rotina de interrupção

void onButtonDown(void) {  // exemplo de rotina de interrupção quando o evento acontece em pf4(botao)
    if (GPIOIntStatus(GPIO_PORTF_BASE, false) & GPIO_PIN_4) {
        // PF4 was interrupt cause
        valor = !valor;
        if(valor == true){
        pinWrite(&pf1,255);
        }else{
            pinWrite(&pf1,0);
        }
        SysCtlDelay(7000000);
    }
}


int main(void)
{
//    struct *PF1 = &pf1;
    startPINS();      // função que serve para habilitar as estruturas para qe possamos trabalhar com elas
    uint32_t read;
    uint32_t ADC;
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    //configuraçoes de pinos

    setIO(&pf1 ,0);  // setando pino como output
    setIO(&pf2 ,0);
    setIO(&pe0 ,1);  // setando pino como input
    setIO(&pf4 ,1);  // setando pino como input
    pwmMode(&pf3,5000);  // configurando pino como pwm
    ADCMode(&pe3,0);   // configurando pino como adc
    interruptMode(&pf4,GPIO_LOW_LEVEL,onButtonDown);     // setando interrupção no pino input
    while(1)
    {
        // Turn on the LED
        // teste das funções pinRead e pinWrite

        read = pinRead(&pe0); //quando pe0 recebe tensão o led azul acende
        if(read != 0){
           pinWrite(&pf2,255);
        }else{
           pinWrite(&pf2,0);
        }

        // teste das funções ADCRead e pwmWrite
        ADC = ADCRead(&pe3);
        pwmWrite(&pf3,ADC);

    }
}
