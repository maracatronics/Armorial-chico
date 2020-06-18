    #include <stdint.h>
    #include <stdbool.h>
    #include "inc/tm4c123gh6pm.h"
    #include "inc/hw_memmap.h"
    #include "inc/hw_types.h"
    #include "driverlib/sysctl.h"
    #include "driverlib/interrupt.h"
    #include "driverlib/gpio.h"
    #include "driverlib/timer.h"
    #include "interrupcao.h"

    int main(void)
    {
        SysCtlClockSet( SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN );
        SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOF );
        GPIOPinTypeGPIOOutput( GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 );
        TimerIntConfig();

        while( 1 ) {
            if (getTime() == 5000){
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 255);
                clearTime();
            }
        }
    }


