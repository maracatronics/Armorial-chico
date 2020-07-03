//Bibliotecas do modelo:
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "setpin.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/pin_map.h"

void startPINS(void){
    int memory = &pa2;

       while(memory <= &pf4){
       definePIN(memory);
       memory = memory + 48;
       }
}

void definePIN(pin *x){
if(x == &pa2){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_2;
}
if(x == &pa3){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_3;
}
if(x == &pa4){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_4;
}
if(x == &pa5){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_5;
}
if(x == &pa6){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_6;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PA6_M1PWM2;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_1;
x->pwmOutBit = PWM_OUT_2_BIT;
x->pwmOut = PWM_OUT_2;
}
if(x == &pa7){
x->periferico = SYSCTL_PERIPH_GPIOA;
x->port = GPIO_PORTA_BASE;
x->pino = GPIO_PIN_7;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PA7_M1PWM3;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_1;
x->pwmOutBit = PWM_OUT_3_BIT;
x->pwmOut = PWM_OUT_3;
}
if(x == &pb0){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_0;
}
if(x == &pb1){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_1;
}
if(x == &pb2){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_2;
}
if(x == &pb3){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_3;
}
if(x == &pb4){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_4;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PB4_M0PWM2;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_1;
x->pwmOutBit = PWM_OUT_2_BIT;
x->pwmOut = PWM_OUT_2;
}
if(x == &pb5){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_5;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PB5_M0PWM3;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_1;
x->pwmOutBit = PWM_OUT_3_BIT;
x->pwmOut = PWM_OUT_3;
}
if(x == &pb6){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_6;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PB6_M0PWM0;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_0;
x->pwmOutBit = PWM_OUT_0_BIT;
x->pwmOut = PWM_OUT_0;
}
if(x == &pb7){
x->periferico = SYSCTL_PERIPH_GPIOB;
x->port = GPIO_PORTB_BASE;
x->pino = GPIO_PIN_7;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PB7_M0PWM1;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_0;
x->pwmOutBit = PWM_OUT_1_BIT;
x->pwmOut = PWM_OUT_1;
}
if(x == &pc0){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_0;
}
if(x == &pc1){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_1;
}
if(x == &pc2){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_2;
}
if(x == &pc3){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_3;
}
if(x == &pc4){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_4;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PC4_M0PWM6;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_3;
x->pwmOutBit = PWM_OUT_6_BIT;
x->pwmOut = PWM_OUT_6;
}
if(x == &pc5){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_5;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PC5_M0PWM7;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_3;
x->pwmOutBit = PWM_OUT_7_BIT;
x->pwmOut = PWM_OUT_7;
}
if(x == &pc6){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_6;
}
if(x == &pc7){
x->periferico = SYSCTL_PERIPH_GPIOC;
x->port = GPIO_PORTC_BASE;
x->pino = GPIO_PIN_7;
}
if(x == &pd0){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_0;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PD0_M1PWM0;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_0;
x->pwmOutBit = PWM_OUT_0_BIT;
x->pwmOut = PWM_OUT_0;
}
if(x == &pd1){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_1;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PD1_M1PWM1;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_0;
x->pwmOutBit = PWM_OUT_1_BIT;
x->pwmOut = PWM_OUT_1;
}
if(x == &pd2){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_2;
}
if(x == &pd3){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_3;
}
if(x == &pd4){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_4;
}
if(x == &pd5){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_5;
}
if(x == &pd6){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_6;
}
if(x == &pd7){
x->periferico = SYSCTL_PERIPH_GPIOD;
x->port = GPIO_PORTD_BASE;
x->pino = GPIO_PIN_7;
}
if(x == &pe0){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_0;
}
if(x == &pe1){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_1;
}
if(x == &pe2){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_2;
}
if(x == &pe3){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_3;
}
if(x == &pe4){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_4;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PE4_M0PWM4;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_2;
x->pwmOutBit = PWM_OUT_4_BIT;
x->pwmOut = PWM_OUT_4;
}
if(x == &pe5){
x->periferico = SYSCTL_PERIPH_GPIOE;
x->port = GPIO_PORTE_BASE;
x->pino = GPIO_PIN_5;
x->pwmPeriferico = SYSCTL_PERIPH_PWM0;
x->pwmMode = GPIO_PE5_M0PWM5;
x->pwmBase = PWM0_BASE;
x->pwmGen = PWM_GEN_0;
x->pwmOutBit = PWM_OUT_1_BIT;
x->pwmOut = PWM_OUT_1;
}
if(x == &pf0){
x->periferico = SYSCTL_PERIPH_GPIOF;
x->port = GPIO_PORTF_BASE;
x->pino = GPIO_PIN_0;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PF0_M1PWM4;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_2;
x->pwmOutBit = PWM_OUT_4_BIT;
x->pwmOut = PWM_OUT_4;
}
if(x == &pf1){
x->periferico = SYSCTL_PERIPH_GPIOF;
x->port = GPIO_PORTF_BASE;
x->pino = GPIO_PIN_1;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PF1_M1PWM5;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_2;
x->pwmOutBit = PWM_OUT_5_BIT;
x->pwmOut = PWM_OUT_5;
}
if(x == &pf2){
x->periferico = SYSCTL_PERIPH_GPIOF;
x->port = GPIO_PORTF_BASE;
x->pino = GPIO_PIN_2;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PF2_M1PWM6;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_3;
x->pwmOutBit = PWM_OUT_6_BIT;
x->pwmOut = PWM_OUT_6;;
}
if(x == &pf3){
x->periferico = SYSCTL_PERIPH_GPIOF;
x->port = GPIO_PORTF_BASE;
x->pino = GPIO_PIN_3;
x->pwmPeriferico = SYSCTL_PERIPH_PWM1;
x->pwmMode = GPIO_PF3_M1PWM7;
x->pwmBase = PWM1_BASE;
x->pwmGen = PWM_GEN_3;
x->pwmOutBit = PWM_OUT_7_BIT;
x->pwmOut = PWM_OUT_7;
}
if(x == &pf4){
x->periferico = SYSCTL_PERIPH_GPIOF;
x->port = GPIO_PORTF_BASE;
x->pino = GPIO_PIN_4;
}
}

// função para configurar o pino como input ou output
void setIO(pin *x, int mode){//pin->pa0,pa1,etc| mode-> 1= input 0 = output


SysCtlPeripheralEnable(x->periferico); // habilita o periférico referente
switch (mode){
case 0:
GPIOPinTypeGPIOOutput(x->port, x->pino);
break;

case 1:
GPIOPinTypeGPIOInput(x->port, x->pino);
GPIOPadConfigSet(x->port, x->pino, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
break;
}
}

// funcao para controlar um pino
void pinWrite(pin *x, uint8_t valor){
    GPIOPinWrite(x->port, x->pino, valor);
}

// funcao para fazer leitura de um pino
uint32_t pinRead(pin *x){
    uint8_t leitura;
    leitura = GPIOPinRead(x->port, x->pino);
    return leitura;
}

// função para configurar um pino como pwm
void pwmMode(pin *x, int period){
    SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
    SysCtlPeripheralEnable(x->periferico);
    SysCtlPeripheralEnable(x->pwmPeriferico);

    GPIOPinConfigure(x->pwmMode);
    GPIOPinTypePWM(x->port, x->pino);

    PWMGenConfigure(x->pwmBase,x->pwmGen, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenPeriodSet(x->pwmBase, x->pwmGen, period);
    PWMGenEnable(x->pwmBase,x->pwmGen);
           // Turn on the Output pins
    PWMOutputState(x->pwmBase,x->pwmOutBit, true);
  }

// funcao para controlar o pwm
void pwmWrite(pin *x, int sizeWave){
    PWMPulseWidthSet(x->pwmBase, x->pwmOut,sizeWave);
}

void ADCMode(pin *x, int base) {
    if(base == 0){
        x->adcPeriferico = SYSCTL_PERIPH_ADC0;
        x->adcBase = ADC0_BASE;
        x->adcSequencia = 0;
    }if(base == 1) {
        x->adcPeriferico = SYSCTL_PERIPH_ADC1;
        x->adcBase = ADC1_BASE;
        x->adcSequencia = 1;
    }
    SysCtlPeripheralEnable(x->periferico);
    SysCtlPeripheralEnable(x->adcPeriferico);
    GPIOPinTypeADC(x->port,x->pino);
//    while(!(SysCtlPeripheralReady(x->adcPeriferico))){}
    ADCSequenceDisable(x->adcBase, x->adcSequencia); // desabilitar sequencia
    ADCSequenceConfigure(x->adcBase, x->adcSequencia, ADC_TRIGGER_PROCESSOR, x->adcSequencia); // configurando para adc
    ADCSequenceStepConfigure(x->adcBase, x->adcSequencia, 0, ADC_CTL_CH0);
    ADCSequenceStepConfigure(x->adcBase,x->adcSequencia, 1, ADC_CTL_CH2 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(x->adcBase, x->adcSequencia);
}
uint32_t ADCRead(pin *x) {
 //    float constant = 0.059584859584;
    uint32_t pui32ADC0Value[2];
             ADCIntClear(x->adcBase, x->adcSequencia);
             ADCProcessorTrigger(x->adcBase, x->adcSequencia);
             while(!ADCIntStatus(x->adcBase, x->adcSequencia, false))
             {
             }
             ADCSequenceDataGet(x->adcBase, x->adcSequencia, pui32ADC0Value);
       //      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, pui32ADC0Value);
             return pui32ADC0Value[0];

}
void interruptMode(pin *x, uint32_t type, void (*pfnIntHandler)(void)){
       GPIOIntDisable(x->port, x->pino);        // Disable interrupt for pin (in case it was enabled)
       GPIOIntClear(x->port, x->pino);      // Clear pending interrupts for pin
       GPIOIntRegister(x->port, pfnIntHandler);     // Register our handler function for port pin
       GPIOIntTypeSet(x->port, x->pino,
                      type);             // Configure pin for type
       GPIOIntEnable(x->port, x->pino);     // Enable interrupt for pin

}
