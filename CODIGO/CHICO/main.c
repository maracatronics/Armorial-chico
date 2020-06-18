
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
#include "driverlib/timer.h"
#include "ADC.h"
#include "protocolo.h"
#include "interrupcao.h"
#define id_robo  0b0000001
struct nrf24l01p nrf;
uint8_t addresses[][6] = {"1Node","2Node"};
//int i;


int main(void) {

    uint32_t ui32Period;
    //
    // Enable lazy stacking for interrupt handlers.  This allows floating-point
    // instructions to be used within interrupt handlers, but at the expense of
    // extra stack usage.
    //
    FPULazyStackingEnable();
    FPUEnable();

    // Funções de configuração

    setup();
    setup_serial(115200);
    setup_pwm(5000);
    ConfigurarADC(SYSCTL_PERIPH_GPIOE,GPIO_PORTE_BASE,GPIO_PIN_0|GPIO_PIN_3);

    IntMasterEnable();

    led_pin_config();

    // configuração do timer para interrupcao

    TimerIntConfig();

    //set up the radio
    if( !nrf24l01p_setup(&nrf, GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PORTC_BASE, GPIO_PIN_4, SSI0_BASE) ){
        //we couldn't communicate with the radio
        //return 1;
    }

    nrf24l01p_set_PA_level(&nrf, RF24_PA_LOW);

    nrf24l01p_open_writing_pipe(&nrf, addresses[1]);
    nrf24l01p_open_reading_pipe(&nrf, 1,addresses[0]);

    uint8_t recebido[6];

    while(1){

       nrf24l01p_start_listening(&nrf); // Now, resume listening so we catch the next packets.
       if (nrf24l01p_available(&nrf)) {

                nrf24l01p_read(&nrf, &recebido, sizeof(recebido));     // Get the payload
                GetComando(recebido);   // pegar o comando e executa-lo
        }
        if (getTime() == 5000){
            send_dados();  // envia os dados pro PC
            clearTime();
            }
        }
}


