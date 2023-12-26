/*
 * File:   isr.c
 * Author: rodrigobaeta
 *
 * Created on December 17, 2023, 10:03 PM
 */

#include <xc.h>

#include "isr.h"
#include "config.h"
#include "utils.h"
#include "global_variables.h"

struct Timers timers = {0};

void isr_disable(void)
{
	INTCON0bits.GIE = 0;														//Disables all interrupts
}

void isr_enable(void)
{	
    INTCON0bits.IPEN = 0;														//Disable priority levels on interrupts; all interrupts are treated as high priority interrupts
	INTCON0bits.GIE = 1;														//Enables all unmasked interrupts
}

void init_timers(void) 
{
    //Timer 0 interrupt
	T0CON0bits.EN = 0;
	T0CON0bits.OUTPS = 0b0000;													//1:1
	T0CON0bits.MD16 = 0;														//TMR0 is an 8-bit timer
	T0CON1bits.CS = 0b101;														//MFINTOSC (500 kHz)
	T0CON1bits.CKPS = 0b0110;													//1:64
	TMR0 = 178;																	//100Hz 10ms

	T0CON0bits.EN = 1;															//The module is enabled and operating
	PIE3bits.TMR0IE = 1;														//Timer 0 interrupt enabled
}

void __interrupt(irq(IRQ_TMR0)) TMR0_ISR(void)
{
	PIR3bits.TMR0IF = 0;														// Clear the interrupt flag
	TMR0 = 178;
	
    volatile static uint8_t counter_1_s = 10;
    volatile static uint8_t counter_100_ms = 10;

    timers.t_10_ms = !timers.t_10_ms;

    counter_100_ms--;
    if(!counter_100_ms)
    {
        timers.t_100_ms = !timers.t_100_ms;
        counter_100_ms = 10;

        counter_1_s--;
        if (!counter_1_s)
        {
            timers.t_1_s = !timers.t_1_s;
            counter_1_s = 10;
        }
    }
}

void __interrupt(irq(IRQ_AD)) ADC_ISR(void)
{
	PIR1bits.ADIF = 0;
	
	static uint8_t stage = 0;
	union UNION_16 adc_value = {0};
	
	adc_value.value = ADRES;
	
	switch(stage)
	{
		case 0:
			thermistor_1 = (adc_value.value * 3.3) / 4096;
			//stage++;
			break;
			
		case 1:
			thermistor_2 = (adc_value.value * 3.3) / 4096;
			//stage++;
			break;
			
		default:
			break;
	}
	
	Nop();
	Nop();
	Nop();
	
	ADCON0bits.GO = 1;															// Start Conversion cycle
}
