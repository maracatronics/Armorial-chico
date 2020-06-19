/*
 * protocolo.c
 *
 *  Created on: 27 de mar de 2020
 *      Author: Gabriel Tarquinio
 */
#include "protocolo.h"
#define id_robo  0b0000001
bool cap;
bool ang;

void GetComando(uint8_t *recebido){   // vai pegar o comando e fazer uma ação a partir disso

    if ((recebido[1] & 0b0000011) == 0b00000011){        // Drible
         locomocao(recebido[2],recebido[3],recebido[4]);
         }
    if ((recebido[1] & 0b0001100) == 0b0001100){         // Chute
          cap = CarregarCapacitor(recebido[5]);
          ang = angulacao(recebido[5]);
          if((cap & ang) == 1){
              chute(1);
          }
          }
    if ((recebido[1] & 0b0110000) == 0b0110000){        // passe
           cap = CarregarCapacitor(recebido[5]);
           ang = angulacao(recebido[5]);
           if((cap & ang) == 1){
               chute(1);
          }
          }
    if ((recebido[1] & 0b011000000) == 0b011000000){        //chip kick
            cap = CarregarCapacitor(recebido[5]);
            ang = angulacao(recebido[5]);
            if((cap & ang) == 1){
                chute(2);

              }
          }

}

bool angulacao(uint8_t recebido){

}

void locomocao(uint8_t vx, uint8_t vy, uint8_t vz){

}

bool CarregarCapacitor(uint8_t potencia){ // verifica tensao do capacitor e o carrega até a tensao desejada
    int pot;
    float cargaCapacitor;
    if ((potencia & 0b0000000) == 0b0000000){ // Não chutar
           pot = 0;
       }
       if ((potencia & 0b0000001) == 0b0000001){ // chute fraco
           pot = 70;   // valor aleatorio
       }
       if ((potencia & 0b0000010) == 0b0000010){ // chute medio
           pot = 120;  // valor aleatorio
       }
       if ((potencia & 0b0000011) == 0b0000011){ // chute forte
           pot = 180; // valor aleatorio
       }
       cargaCapacitor = GetADC(1); //leitura do capacitor
       if(cargaCapacitor >= pot){
           return 1;
       }
       else{
       PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,0);  // pwm terá um tamanho minimo de onda para ter um frequencia maxima de carregamento
          return 0;
       }


}
void chute (int type_chute){
     switch(type_chute){
     // chute normal
     case 1:
         GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 255);
         GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);
         break;
     // chip kick
     case 2:
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 255);
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
         break;

     }
}
void send_dados(){
    uint8_t envio[6];
    struct nrf24l01p nrf;
    envio[0] = id_robo;    // envia id do robo, como temos 6, cada robo vai ter um id sendo de 1 a 6
    envio[1] = GetADC(0);  // status da bateria
    envio[2] = GetADC(1);  // status do capacitor
    envio[3] = GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_4); //status do sensor infravermelho
    envio[4] = cap;   // kick enabled
    envio[5] = ang;

    nrf24l01p_stop_listening(&nrf);        // First, stop listening so we can talk
    nrf24l01p_write(&nrf, &envio, sizeof(envio)); // Send the final one back.

}
