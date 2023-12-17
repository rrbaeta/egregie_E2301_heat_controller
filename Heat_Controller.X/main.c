/*
 * File:   main.c
 * Author: rodrigobaeta
 *
 * Created on December 3, 2023, 7:26 PM
 */


#include <xc.h>

#include "config.h"

#define LED LATAbits.LATA7
#define RELAY LATBbits.LATB4

void main(void) 
{
    TRISA = 0b00000000;
    ANSELA = 0;
    LATA = 0;
    TRISB = 0b00000000;
    ANSELB = 0;
    LATB = 0;

    //RELAY = 1;
    LED = 1;
       
    while(1)
    {
    }
}
