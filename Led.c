#include <avr/io.h>
#include <util/delay.h>
#include "Led.h"

void led_init() 
{
	//Sätter bit PBO i port B till output.
	DDRB |= (1 << PB0);
}

void toggle_led()
{
	PORTB ^= (1 << PB0);
}