#include <avr/io.h>

#include "Timer.h"

void timer_init() 
{
	//Deluppgift 1
	//TCCR0A |= (1 << WGM01); //Timer/Counter Control Register 0 A. Sätter andra biten (WGM01) till 1 för CTC mode. 
	//TCCR0B |= (1 << CS00) | (1 << CS02); //Timer/Counter Control Register 0 B. Sätter första (CS00) och tredje (CS02) till 1 för prescaler=1024.
	//TCNT0 = 0b00000000; //Timer/Counter Register (stores the counter value). Sätter till 0 för att initiera. 
	//OCR0A = 0b10011100; //Output Compare Register. Sätter till 156. 

	//Deluppgift 2
	//TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1); //Timer/Counter Control Register 0 A. Sätter första (WGM00), andra (WGM01) och 8e (COM0A1) biten till 1 för fast PWM non invert mode. 
	//TCCR0B |= (1 << CS00) | (1 << CS01); //Timer/Counter Control Register 0 B. Sätter första (CS00) och andra (CS01) till 1 för prescaler=64.

	//Deluppgift 3
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1); //Timer/Counter Control Register 0 A. Sätter första (WGM00), andra (WGM01) och 8e (COM0A1) biten till 1 för fast PWM non invert mode. 
	TCCR0B |= (1 << CS00) | (1 << CS01); //Timer/Counter Control Register 0 B. Sätter första (CS00) och andra (CS01) till 1 för prescaler=64.

	TCCR2A |= (1 << WGM21); //Timer/Counter Control Register 2 A. Sätter andra biten (WGM21) till 1 för CTC mode. 
	TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22); //Timer/Counter Control Register 0 B. Sätter första (CS20), andra (CS21) och tredje (CS22) till 1 för prescaler=1024.
	TCNT2 = 0b00000000; //Timer/Counter Register (stores the counter value). Sätter till 0 för att initiera.
	OCR2A = 0b11111010; //Output Compare Register. Sätter till 250. 
}