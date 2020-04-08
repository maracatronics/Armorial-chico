
/*
* Aquivo base usando para impementacao do firmware do robo omnidirecional.
* Autores: Jose Neto, Flavio Candido
*
* Autor do projeto que usamos como modelo: Texas Instruments e Saurav Shandilya, Vishwanathan Iyer
* Description: Codigo inicial do firmware do robo  omnidirecional.
*              Nesta estapa, estamos usando o modelo de projeto apresnetado em:
*              https://www.cse.iitb.ac.in/~erts/html_pages/resources.html
*              e adaptando.
*
* Implementacao da vez: nRF24L01+
*
* Filename: main.c
* Functions: setup(), led_pin_config(), main()
* Global Variables: none
*/

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "nrf24l01.h"
#include "setup.h"
#include "Comunicacao.h"

struct nrf24l01p nrf;
uint8_t addresses[][6] = {"1Node","2Node"};
//int i;


int main(void) {

  //  uint8_t ui8LED = 2;
    //
    // Enable lazy stacking for interrupt handlers.  This allows floating-point
    // instructions to be used within interrupt handlers, but at the expense of
    // extra stack usage.
    //
    FPULazyStackingEnable();
    FPUEnable();



    setup();

    IntMasterEnable();

    led_pin_config();



    // Kich hoat uart0
           SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
           SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
           //Cau hinh chan PA0 va PA1 lan luot la chan RX va TX
           GPIOPinConfigure(GPIO_PA0_U0RX);
           GPIOPinConfigure(GPIO_PA1_U0TX);
           GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);  //Thieu dinh nghia pin pa1 pa0 la chan cua UART
           //Cau hinh uart 0 baud 115200
           UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));



    setup();

    IntMasterEnable();

    led_pin_config();

    //set up the radio
    if( !nrf24l01p_setup(&nrf, GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PORTC_BASE, GPIO_PIN_4, SSI0_BASE) ){
        //we couldn't communicate with the radio
        //return 1;
    }

    nrf24l01p_set_PA_level(&nrf, RF24_PA_LOW);

    nrf24l01p_open_writing_pipe(&nrf, addresses[1]);
    nrf24l01p_open_reading_pipe(&nrf, 1,addresses[0]);

    uint8_t recebido[6];

    uint8_t envio[6] = "maraca";
    while(1){

      nrf24l01p_stop_listening(&nrf);        // First, stop listening so we can talk
        nrf24l01p_write(&nrf, &envio, sizeof(envio)); // Send the final one back.
       nrf24l01p_start_listening(&nrf); // Now, resume listening so we catch the next packets.

        if (nrf24l01p_available(&nrf)) {

                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_3, 0);
                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 255);
               SysCtlDelay(50000);
                nrf24l01p_read(&nrf, &recebido, sizeof(recebido));     // Get the payload

                UARTCharPut(UART0_BASE, recebido[0]);
                UARTCharPut(UART0_BASE, recebido[1]);
                UARTCharPut(UART0_BASE, recebido[2]);
                UARTCharPut(UART0_BASE, recebido[3]);
                UARTCharPut(UART0_BASE, recebido[4]);
                UARTCharPut(UART0_BASE, recebido[5]);
                UARTCharPut(UART0_BASE, '\n');

                SysCtlDelay(100000);
                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
      //      nrf24l01p_stop_listening(&nrf);        // First, stop listening so we can talk
      //      nrf24l01p_write(&nrf, &envio, sizeof(envio)); // Send the final one back.
       //     nrf24l01p_start_listening(&nrf); // Now, resume listening so we catch the next packets.
       //         ++i ;

      //  }

//            if(recebido[0]==envio[0]){
//                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
//                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 255);
//               // SysCtlDelay(5000000);
//
//            }else{
//                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);
//                GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 255);
//               // SysCtlDelay(20000000);
//            }

        }
        }

//      //give it a little space
//      SysCtlDelay((SysCtlClockGet() >> 12) * 5);



    //return 0;
}
