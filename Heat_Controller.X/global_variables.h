/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GLOBAL_VARIABLES_H
#define	GLOBAL_VARIABLES_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define TH1_AN              0b000010                                            //AN2
#define TH2_AN              0b000011											//AN3

extern double thermistor_1;
extern double thermistor_2;

#endif	/* GLOBAL_VARIABLES_H */

