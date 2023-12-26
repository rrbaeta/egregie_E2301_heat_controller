/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef UTILS_H
#define	UTILS_H

#include <xc.h> // include processor files - each processor file is guarded.  

union UNION_16
{
    uint16_t value;
    
    struct
    {
        uint8_t LOW;
        uint8_t HIGH;
    };
};

union BITFIELD
{
    uint8_t value;
    
    struct
    {
        unsigned BIT0 : 1;
        unsigned BIT1 : 1;
        unsigned BIT2 : 1;
        unsigned BIT3 : 1;
        unsigned BIT4 : 1;
        unsigned BIT5 : 1;
        unsigned BIT6 : 1;
        unsigned BIT7 : 1;
    };
};

#endif	/* UTILS_H */

