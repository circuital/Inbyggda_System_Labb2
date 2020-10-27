#include <avr/io.h>
#include <util/delay.h>
#include "Led.h"

int dir = 1;
int bri = 0;

void led_init() 
{
	//Sätter bit PBO i port B till output.
	DDRB |= (1 << PB0);
	//Sätter bit PD6 i port D till output.
	DDRD |= (1 << PD6);
}

void toggle_led()
{
	PORTB ^= (1 << PB0);
}

void change_led()
{
    OCR0A = 255;
    _delay_ms(500);

    OCR0A = 128;
    _delay_ms(500);

    OCR0A = 0;
    _delay_ms(500);
}

int simple_ramp()
{
    if (dir == 1)
    {
        bri++;
        if (bri == 254)
        {
            dir = -1;
        }
    }
    else
    {
        bri--;
        if (bri == 0)
        {
            dir = 1;
        }
    }
    return bri;
}