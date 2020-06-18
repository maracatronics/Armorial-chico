/*
 * interrupcao.c
 *
 *  Created on: 22 de jan de 2020
 *      Author: Gabriel Tarquinio
 */

#include "interrupcao.h"

volatile bool condicao = true;
volatile uint32_t N_eventos = 0;

void TimerIntConfig(void){
            uint32_t ui32Period;
            SysCtlPeripheralEnable( SYSCTL_PERIPH_TIMER0 );
            TimerConfigure( TIMER0_BASE, TIMER_CFG_PERIODIC );
            ui32Period = ( SysCtlClockGet()*0.0005 - 1 );
            TimerLoadSet( TIMER0_BASE, TIMER_A, ui32Period - 1 );
            IntEnable( INT_TIMER0A );
            TimerIntEnable( TIMER0_BASE, TIMER_TIMA_TIMEOUT );
            IntMasterEnable();
            TimerEnable( TIMER0_BASE, TIMER_A );
}

uint32_t getTime(void){
    return N_eventos;
}

void clearTime(void){
    N_eventos = 0;
}

void Timer0IntHandler(void)

  {
      GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
      TimerIntClear( TIMER0_BASE, TIMER_TIMA_TIMEOUT );
      condicao = !condicao;
      // Clear the timer interrupt
      if (condicao == true){
          ++N_eventos;
      }

  }

