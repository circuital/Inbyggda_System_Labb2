#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>

#include "Led.h"
#include "Serial.h"
#include "Timer.h"

int main(void) 
{
    int overflowCount = 0;

    uart_init(); 
	timer_init();
    led_init();

    //Deluppgift 1
    //while (1) 
    //{
    //    while ((TIFR0 & (1 << OCF0A)) > 0) //Timer/Counter Interrupt Flag Register. V�ntar p� ett overflow event. 
    //    {      
    //        overflowCount++;
    //        if (overflowCount == 10)
    //        {
    //            toggle_led();
    //            overflowCount = 0;
    //        }
    //        TIFR0 |= (1 << OCF0A);  //Rensar overflow flaggan. 
    //    }
    //}

    //Deluppgift 2
    //while (1)
    //{
    //    change_led();
    //}

    //Deluppgift 3
    while (1)
    {
        while ((TIFR2 & (1 << OCF2A)) > 0) //Timer/Counter Interrupt Flag Register. V�ntar p� ett overflow event. 
        {      
            OCR0A = simple_ramp();
            TIFR2 |= (1 << OCF2A);  //Rensar overflow flaggan. 
        }
    }
}