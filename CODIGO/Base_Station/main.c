#include <stdint.h>
#include <stdbool.h>
#include "String.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "setup.h"
#include "driverlib/sw_crc.h"
#include "crc32.h"
#define CRC_CCITT 0x1021
#define CRC16 0x18005

//#include "nrf24l01.h"
//struct nrf24l01p nrf;
//uint8_t addresses[][6] = {"1Node","2Node"};
//uint8_t time,add;
int i,j,k = 0;
uint8_t RECEBIDO[20];
uint32_t crc;
int divisorMsg, endMsg;
uint8_t msg[10];
uint8_t CRC[4];

//int j;

unsigned int crc32b(unsigned char* );

unsigned int crc32b(unsigned char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0) {
      byte = message[i];            // Get next byte.
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i = i + 1;
   }
   return crc;
}
int main(void)
{
    // Thiet lap clock he thong
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    setup_serial(115200);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    //UARTCharGet(UART0_BASE)

    while(1)
    {
       RECEBIDO[i] = UARTCharGet(UART0_BASE);

       if (RECEBIDO[0] == '@') {   // quando ler esse comeca a armazenar

   //   if (RECEBIDO[i] == ':') divisorMsg = i;

       if (RECEBIDO[i] == '^'){   // quando ler esse caracter para a leitura
           endMsg = i;
           i = 0;
           crc = 0;
           for(j = 0;j < endMsg - 1; ++j){       // armazenando a mensagem
               msg[j] = RECEBIDO[j+1];
           }


           crc = crc32b(msg);      // Funcao que calcular o crc

           if(crc == 0){
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,255);
 //             SysCtlDelay(2500000);
              GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3,0);
              UARTCharPut(UART0_BASE, 'O');
              UARTCharPut(UART0_BASE, 'K');
          }
       }
       else ++i;

       }
    }

}


