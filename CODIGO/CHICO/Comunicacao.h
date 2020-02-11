/*
 * Comunicacao.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: Jose Neto
 *      Description: Esta biblioteca constroi as funcoes que implementam a comunicacao entre o Robo e
 *      o computador.
 */

#ifndef COMUNICACAO_H_
#define COMUNICACAO_H_


#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#include "nrf24l01.h"


extern struct nrf24l01p radio; //O radio

//extern uint8_t addresses[][6] = {"1Node","2Node"};

//Bytes do protocolo de comunicacao
typedef struct
{
    uint8_t address;
    struct nrf24l01p radio;
    uint8_t pacote[6];
    uint8_t pipe;


}Protocolo;//Precisa colocar ainda o pipe, pacote como um que é a mensagem,
           //
           //

/*
* Method Name: Protocolo()
* Input: none
* Output: none
* - Construtor da classe
*/
bool  ProtocoloInit(Protocolo *RoboCom);

/*
* Method Name: set_address()
* Input: time - 4 bits indicando qual o time
*        add  - 4 bits indicando o endereco do robo
* Output: bool  - 0 - erro no tamanho de time ou add;
*               - 1 - tudo ocorreu corretamente
* Configura o endereco do robo time|add
* Example Call: set_address();
*/
bool  ProtocoloSetAddress(Protocolo *RoboCom, uint8_t time, uint8_t add);


#endif /* COMUNICACAO_H_ */
