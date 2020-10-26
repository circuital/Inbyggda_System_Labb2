#include <avr/io.h>
#include <util/delay.h>
#include "Led.h"

void led_init() 
{
	//Sätter bit PBO i port B till output.
	DDRB |= (1 << PB0);
	//Sätter bit PD1 i port D till output.
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