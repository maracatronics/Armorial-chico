/*
 * Comunicacao.cpp
 *
 *  Created on: 20 de nov de 2019
 *      Author: Jose Neto
 *      Description: Esta biblioteca constroi as funcoes que implementam a comunicacao entre o Robo e
 *      o computador.
 */

#include "Comunicacao.h"


/*
* Method Name: Protocolo()
* Input: none
* Output: none
* - Construtor da classe
*/
bool ProtocoloInit(struct Protocolo *RoboCom)
{
    //Inicializa o radio
    if(!nrf24l01p_setup(&RoboCom->radio, GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PORTC_BASE, GPIO_PIN_4, SSI0_BASE) )
    {
            //we couldn't communicate with the radio
            return 0;
    }

    return 1;
}

/*
* Method Name: set_address()
* Input: time - 4 bits indicando qual o time
*        add  - 4 bits indicando o endereco do robo
* Output: bool  - 0 - erro no tamanho de time ou add;
*               - 1 - tudo ocorreu corretamente
* Configura o endereco do robo time|add
* Example Call: set_address();
*/
bool ProtocoloSetAddress(struct Protocolo *RoboCom, uint8_t time, uint8_t add)
{
    uint8_t tempTime = 0;
    uint8_t tempAdd = 0;
    if((time < 16) || (add < 16 )) // Verifica se o time e endereco ocupam apenas 4 bits
    {
        tempTime =  0xF0&(time<<4);    //Desloca o time para o comeco do byte e aplica uma mascara para limpar os bits restantes
        tempAdd  =  0x0F&(add);        //Limpa os 4 bits mais signficativos;
        RoboCom->address  = tempTime|tempAdd;   //concatena os 4 bits de time com os 4 bits de add;
        return 1;
    }
    else
    {
        return 0;  //Time ou Add com valores fora do permitido
    }
}



