    #include <stdint.h>

    #include <stdbool.h>

    #include "inc/tm4c123gh6pm.h"

    #include "inc/hw_memmap.h"

    #include "inc/hw_types.h"

    #include "driverlib/sysctl.h"

    #include "driverlib/interrupt.h"

    #include "driverlib/gpio.h"

    #include "driverlib/timer.h"

     volatile bool condicao = true;
     volatile uint32_t N_eventos = 0;

    int main(void)

    {

        uint32_t ui32Period;


        SysCtlClockSet( SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN );



        SysCtlPeripheralEnable( SYSCTL_PERIPH_GPIOF );

        GPIOPinTypeGPIOOutput( GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 );



        SysCtlPeripheralEnable( SYSCTL_PERIPH_TIMER0 );

        TimerConfigure( TIMER0_BASE, TIMER_CFG_PERIODIC );



        ui32Period = ( SysCtlClockGet()*0.0005 - 1);

        TimerLoadSet( TIMER0_BASE, TIMER_A, ui32Period - 1 );



        IntEnable( INT_TIMER0A );

        TimerIntEnable( TIMER0_BASE, TIMER_TIMA_TIMEOUT );

        IntMasterEnable();



        TimerEnable( TIMER0_BASE, TIMER_A );



        while( 1 ) {

        }

    }



    void Timer0IntHandler(void)

    {


        TimerIntClear( TIMER0_BASE, TIMER_TIMA_TIMEOUT );

        condicao = !condicao;
        // Clear the timer interrupt

        if (condicao == true){
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 255);
            ++N_eventos;
        }
       // GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);

        // Read the current state of the GPIO pin and

        // write back the opposite state

        if( GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2) ) {

            GPIOPinWrite( GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0 );

        } else {

           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);

        }

    }
