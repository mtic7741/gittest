/*
 * GccApplication3.c
 *
 * Created: 2022-07-01 오후 12:27:03
 * Author : user
 */ 

//New Blink.c

#define F_CPU 1600000

#include <avr/io.h>

int main(void) {
	
	DDRB = 0xff;
	PORTB = 0x01;
	while (1) {
	}
}

