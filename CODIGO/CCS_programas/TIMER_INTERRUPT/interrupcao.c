/*
 * interrupcao.c
 *
 *  Created on: 22 de jan de 2020
 *      Author: Gabriel Tarquinio
 */

#include "interrupcao.h"
//void IntConfig(void);

void IntConfig( uint32_t base, uint8_t pino,uint32_t ui32IntType){
    GPIOIntDisable(base, pino);        // Disable interrupt for PF4 (in case it was enabled)
    GPIOIntClear(base, pino);      // Clear pending interrupts for PF4
   // GPIOIntRegister(GPIO_PORTF_BASE, onButtonDown);     // Register our handler function for port F
    GPIOIntTypeSet(base, pino, ui32IntType);             // Configure PF4 for falling edge trigger
    GPIOIntEnable(base, pino);
}

int IntContador(uint32_t base, uint8_t pino,uint32_t ui32IntType,bool state,int contador){
    if (GPIOIntStatus(base, state) & pino) {
            // PF4 was interrupt cause
          //  printf("Button Down\n");
            GPIOIntRegister(base,IntConfig );   // Register our handler function for port F
            GPIOIntTypeSet(base, pino,
                ui32IntType);          // Configure PF4 for rising edge trigger
            GPIOIntClear(base, pino);  // Clear interrupt flag
            ++contador;
            return contador;

        }
}


