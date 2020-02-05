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
#include "ADC.h"

void delayMS(int ms) {
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}

int
main(void)
{
    uint32_t period = 5000; //20ms (16Mhz / 64pwm_divider / 50)
    uint32_t pui32ADC0Value[2];    //1.5ms pulse width
  //  uint32_t duty[2] = ADCinit(SYSCTL_PERIPH_GPIOE,GPIO_PORTE_BASE,GPIO_PIN_3|GPIO_PIN_2);
    //Set the clock
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock divide system clock by 64
   SysCtlPWMClockSet(SYSCTL_PWMDIV_64);

   // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
  //  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_3);
    //Configure PF1,PF2,PF3 Pins as PWM
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    GPIOPinConfigure(GPIO_PF2_M1PWM6);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    //Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    //Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, period);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, period);

    //Set PWM duty
   // PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,duty[0]);
//    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,duty[0]);
//    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,duty[0]);

    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
   // PWMGenEnable(PWM1_BASE, PWM_GEN_3);

    // Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);

    while(1)
    {
        delayMS(2000);
        ADCinit(SYSCTL_PERIPH_GPIOE,GPIO_PORTE_BASE,GPIO_PIN_3|GPIO_PIN_2);
        //Drive servo to 135 degrees
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pui32ADC0Value[0]+(pui32ADC0Value[0]/2));
       // PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pui32ADC0Value[0]+(pui32ADC0Value[0]/2));
       // PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,duty[0]+(duty[0]/2));

        delayMS(2000);

        //Drive servo to 90 degrees
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pui32ADC0Value[0]);
    //    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,duty[0]);
    //    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,duty[0]);

    }

}
