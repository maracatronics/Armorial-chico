#include <setpin.h>




//Bibliotecas do modelo:
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
//Bibliotecas adicionadas por nos:
#include "driverlib/ssi.h" //SPI Library


#define perA	0xf0000800
#define perB	0xf0000801
#define perC	0xf0000802
#define perD	0xf0000803  //HABILITAR PERIFÉRICO
#define perE	0xf0000804
#define perF	0xf0000805



#define portA	0x40004000
#define portB	0x40005000
#define portC	0x40006000 //ENDEREÇO DA PORTA
#define portD	0x40007000
#define portE	0x40024000
#define portF	0x40025000

#define pin0	0x00000001
#define pin1	0x00000002
#define pin2	0x00000004
#define pin3	0x00000008  // ENDEREÇO DO PINO
#define pin4	0x00000010
#define pin5	0x00000020
#define pin6	0x00000040
#define pin7	0x00000080

//LISTA DE PINOS
#define pa0 48
#define pa1 1
#define pa2 2
#define pa3 3
#define pa4 4
#define pa5 5
#define pa6 6
#define pa7 7
#define pb0 8
#define pb1 9
#define pb2 10
#define pb3 11
#define pb4 12
#define pb5 13
#define pb6 14
#define pb7 15
#define pc0 16
#define pc1 17
#define pc2 18
#define pc3 19
#define pc4 20
#define pc5 21
#define pc6 22
#define pc7 23
#define pd0 24
#define pd1 25
#define pd2 26
#define pd3 27
#define pd4 28
#define pd5 29
#define pd6 30
#define pd7 31
#define pe0 32
#define pe1 33
#define pe2 34
#define pe3 35
#define pe4 36
#define pe5 37
#define pe6 38
#define pe7 39
#define pf0 40
#define pf1 41
#define pf2 42
#define pf3 43
#define pf4 44
#define pf5 45
#define pf6 46
#define pf7 47





void setIO(uint8_t pin, bool mode){//pin->pa0,pa1,etc| mode-> 1= input 0 = output
switch (pin){

case pa0: //testa a porta referente

SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin0);}
else{GPIOPinTypeGPIOInput(portA, pin0);}
break;

case pa1:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin1);}
else{GPIOPinTypeGPIOInput(portA, pin1);}
break;

case pa2:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin2);}
else{GPIOPinTypeGPIOInput(portA, pin2);}
break;

case pa3:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin3);}
else{GPIOPinTypeGPIOInput(portA, pin3);}
break;

case pa4:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin4);}
else{GPIOPinTypeGPIOInput(portA, pin4);}
break;

case pa5:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin5);}
else{GPIOPinTypeGPIOInput(portA, pin5);}
break;

case pa6:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin6);}
else{GPIOPinTypeGPIOInput(portA, pin6);}
break;

case pa7:
SysCtlPeripheralEnable(perA); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portA, pin7);}
else{GPIOPinTypeGPIOInput(portA, pin7);}
break;

case pb0:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb0);}
else{GPIOPinTypeGPIOInput(portB, pb0);}
break;

case pb1:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb1);}
else{GPIOPinTypeGPIOInput(portB, pb1);}
break;

case pb2:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb2);}
else{GPIOPinTypeGPIOInput(portB, pb2);}
break;

case pb3:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb3);}
else{GPIOPinTypeGPIOInput(portB, pb3);}
break;

case pb4:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb4);}
else{GPIOPinTypeGPIOInput(portB, pb4);}
break;

case pb5:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb5);}
else{GPIOPinTypeGPIOInput(portB, pb5);}
break;

case pb6:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb6);}
else{GPIOPinTypeGPIOInput(portB, pb6);}
break;

case pb7:
SysCtlPeripheralEnable(perB); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portB, pb7);}
else{GPIOPinTypeGPIOInput(portB, pb7);}
break;

case pc0:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc0);}
else{GPIOPinTypeGPIOInput(portC, pc0);}
break;

case pc1:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc1);}
else{GPIOPinTypeGPIOInput(portC, pc1);}
break;

case pc2:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc2);}
else{GPIOPinTypeGPIOInput(portC, pc2);}
break;

case pc3:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc3);}
else{GPIOPinTypeGPIOInput(portC, pc3);}
break;

case pc4:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc4);}
else{GPIOPinTypeGPIOInput(portC, pc4);}
break;

case pc5:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc5);}
else{GPIOPinTypeGPIOInput(portC, pc5);}
break;

case pc6:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc6);}
else{GPIOPinTypeGPIOInput(portC, pc6);}
break;

case pc7:
SysCtlPeripheralEnable(perC); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portC, pc7);}
else{GPIOPinTypeGPIOInput(portC, pc7);}
break;

case pd0:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd0);}
else{GPIOPinTypeGPIOInput(portD, pd0);}
break;

case pd1:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd1);}
else{GPIOPinTypeGPIOInput(portD, pd1);}
break;

case pd2:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd2);}
else{GPIOPinTypeGPIOInput(portD, pd2);}
break;

case pd3:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd3);}
else{GPIOPinTypeGPIOInput(portD, pd3);}
break;

case pd4:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd4);}
else{GPIOPinTypeGPIOInput(portD, pd4);}
break;

case pd5:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd5);}
else{GPIOPinTypeGPIOInput(portD, pd5);}
break;

case pd6:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd6);}
else{GPIOPinTypeGPIOInput(portD, pd6);}
break;

case pd7:
SysCtlPeripheralEnable(perD); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portD, pd7);}
else{GPIOPinTypeGPIOInput(portD, pd7);}
break;

case pe0:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe0);}
else{GPIOPinTypeGPIOInput(portE, pe0);}
break;


case pe1:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe1);}
else{GPIOPinTypeGPIOInput(portE, pe1);}
break;

case pe2:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe2);}
else{GPIOPinTypeGPIOInput(portE, pe2);}
break;

case pe3:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe3);}
else{GPIOPinTypeGPIOInput(portE, pe3);}
break;

case pe4:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe4);}
else{GPIOPinTypeGPIOInput(portE, pe4);}
break;

case pe5:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe5);}
else{GPIOPinTypeGPIOInput(portE, pe5);}
break;

case pe6:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe6);}
else{GPIOPinTypeGPIOInput(portE, pe6);}
break;

case pe7:
SysCtlPeripheralEnable(perE); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portE, pe7);}
else{GPIOPinTypeGPIOInput(portE, pe7);}
break;

case pf0:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf0);}
else{GPIOPinTypeGPIOInput(portF, pf0);}
break;

case pf1:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf1);}
else{GPIOPinTypeGPIOInput(portF, pf1);}
break;

case pf2:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf2);}
else{GPIOPinTypeGPIOInput(portF, pf2);}
break;

case pf3:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf3);}
else{GPIOPinTypeGPIOInput(portF, pf3);}
break;

case pf4:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf4);}
else{GPIOPinTypeGPIOInput(portF, pf4);}
break;

case pf5:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf5);}
else{GPIOPinTypeGPIOInput(portF, pf5);}
break;

case pf6:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf6);}
else{GPIOPinTypeGPIOInput(portF, pf6);}
break;

case pf7:
SysCtlPeripheralEnable(perF); // habilita o periférico referente
if (mode==0){							//testa modo 0 output 1=input
GPIOPinTypeGPIOOutput(portF, pf7);}
else{GPIOPinTypeGPIOInput(portF, pf7);}
break;

}

}



//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

//GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
