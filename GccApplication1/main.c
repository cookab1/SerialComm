/*
 * Project2.c
 *
 * Created: 2/10/2018 7:19:02 PM
 * Author: Andy Cook
 * Author: John Osborne
 */ 


#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include "SWSerial.h"
#include "EmSys.h"
#include "string.h"

void delay_usec(unsigned int);
void BITBANG(int);


int main(void) {

	long baudrate = 9600L;
	int tx_pin = 12;
	int rx_pin = 11;  
	int framing = SERIAL_8N1;
	
	//int mask = find(tx_pin);
	
	DDRB = 0x40;//1 << mask;

	init_sw_serial(rx_pin, tx_pin, baudrate, framing);  // this is your function
	init_sw_serial_puts_test(baudrate, framing);   // library function: note we need the baudrate and framing here

	while(1) {
		sw_serial_puts("Hello,World!\n");
		test_sw_serial_puts();   // library test function
		_delay_ms(1000);
	}
}

void BITBANG(int b) {
	if (b) {
		// ON
		PORTB |= 0x40;//tMask;
	}
	else {
		// OFF
		PORTB &= ~0x40;//tMask;
	}
	delay_usec(104);
}