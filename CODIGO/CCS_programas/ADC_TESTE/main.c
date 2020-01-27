#include "driverlib/pin_map.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/adc.h"

uint32_t pui32ADC0Value[2];

/**
 * main.c
 */
int main(void)
{
        SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
        GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3|GPIO_PIN_2);
   //     GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
        ADCSequenceDisable(ADC0_BASE, 0); // desabilitar sequencia
        ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0); // configurando para adc
        ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0);
        ADCSequenceStepConfigure(ADC0_BASE,0, 1, ADC_CTL_CH1 | ADC_CTL_IE |
                                 ADC_CTL_END);
        ADCSequenceEnable(ADC0_BASE, 0);
        while(1)
        {
            ADCIntClear(ADC0_BASE, 0);
            ADCProcessorTrigger(ADC0_BASE, 0);
            while(!ADCIntStatus(ADC0_BASE, 0, false))
            {
            }
            ADCSequenceDataGet(ADC0_BASE, 0, pui32ADC0Value);
      //      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, pui32ADC0Value);

        }
    }


