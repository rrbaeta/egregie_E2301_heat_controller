/*
 * File:   adc.c
 * Author: rodrigobaeta
 *
 * Created on December 25, 2023, 2:58 PM
 */

#include <xc.h>

#include "global_variables.h"

void init_adc(void) {
	ADCON0bits.ON = 0;															// ADC is disabled
	
	ADCON0bits.CONT = 0;														// ADC is cleared upon completion of each conversion trigger
	ADCON0bits.CS = 0;															// Clock supplied by FOSC, divided according to ADCLK register
	ADCON0bits.FM = 1;															// ADRES and PREV data are right-justified
	
	ADCON1bits.PPOL = 1;														// Connected to VDD
	ADCON1bits.IPEN = 0;														// Both Conversion cycles use the precharge and guards specified by PPOL and GPOL
	ADCON1bits.GPOL = 0;														// ADC guard Ring outputs start as digital low during Precharge stage
	ADCON1bits.DSEN = 0;														// One conversion is performed for each trigger
	
	ADCLKbits.CS = 0b111111;													// FOSC/128 (500kHz)
	ADPCHbits.PCH = TH1_AN;
	
	PIE1bits.ADIE = 1;															// ADC interrupt enable
	
	ADCON0bits.ON = 1;															// ADC is enabled
	ADCON0bits.GO = 1;															// Start Conversion cycle
}
