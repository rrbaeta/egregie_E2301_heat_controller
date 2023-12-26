  
#ifndef ISR_H
#define	ISR_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdbool.h>

struct Timers
{
    volatile bool t_10_ms;  
    volatile bool t_100_ms;
    volatile bool t_1_s;
};

//Global variables
extern struct Timers timers;

//Function prototypes
void isr_disable(void);
void isr_enable(void);
void init_timers(void);

#endif	/* XC_HEADER_TEMPLATE_H */

