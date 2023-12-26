/*
 * File:   main.c
 * Author: rodrigobaeta
 *
 * Created on December 3, 2023, 7:26 PM
 */


#include <xc.h>

#include "config.h"
#include "isr.h"
#include "adc.h"

// variable declarations
static bool flag_10_ms = false;
static bool flag_100_ms = false;
static bool flag_1_s = false;

// function prototypes
void set_local_timer_flags(void);

void main(void) 
{
    TRISA = 0b00000000;
    ANSELA = 0b00001100;
    LATA = 0;
    TRISB = 0b00000000;
    ANSELB = 0;
    LATB = 0;

	isr_disable();
	init_timers();
	init_adc();
	isr_enable();
	
    //RELAY = 1;
    LED = 0;
       
    while(1)
    {
		set_local_timer_flags();

		// =====================Read Inputs=====================
		if (flag_10_ms)
		{
			
		}

		if (flag_100_ms)
		{
		}

		if (flag_1_s)
		{
		}

		// =====================Calculations=====================
		if (flag_10_ms)
		{
		}

		if (flag_100_ms)
		{
		}

		if (flag_1_s)
		{
		}

		// =====================Set outputs=====================
		if (flag_10_ms)
		{
		}

		if (flag_100_ms)
		{
			LED = !LED;
		}

		if (flag_1_s)
		{
		}

		// //reset timer flags
		flag_10_ms = false;
		flag_100_ms = false;
		flag_1_s = false;
    }
}

void set_local_timer_flags(void)
{
  static bool old_10_ms = false;
  static bool old_100_ms = false;
  static bool old_1_s = false;

  // set timer flags so they are not reset mid loop

  if (old_10_ms != timers.t_10_ms)
  {
    old_10_ms = !old_10_ms;
    flag_10_ms = true;
  }

  if (old_100_ms != timers.t_100_ms)
  {
    old_100_ms = !old_100_ms;
    flag_100_ms = true;
  }

  if (old_1_s != timers.t_1_s)
  {
    old_1_s = !old_1_s;
    flag_1_s = true;
  }
}
